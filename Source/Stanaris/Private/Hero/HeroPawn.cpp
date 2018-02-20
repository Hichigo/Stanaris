// Fill out your copyright notice in the Description page of Project Settings.

#include "Hero/HeroPawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "ConstructorHelpers.h"


// Sets default values
AHeroPawn::AHeroPawn(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer),
	ActionDistance(200)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Skeletal mesh
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshContainer(TEXT("SkeletalMesh'/Game/Stanaris/Hero/Character/SkeletalMesh/SK_Hero.SK_Hero'"));
	if (MeshContainer.Succeeded())
	{
		USkeletalMeshComponent *PlayerMesh = GetMesh();
		PlayerMesh->SetSkeletalMesh(MeshContainer.Object);
	}



	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	//CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetupAttachment(GetMesh(), GetMesh()->GetSocketBoneName(FName(TEXT("head")))); // Possible error, i don't know
	CameraBoom->TargetArmLength = 0.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller
	//CameraBoom->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("head"));
	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm


	// Create a stats component
	StatsComp = ObjectInitializer.CreateAbstractDefaultSubobject<UStatsComp>(this, TEXT("StatsComp"));

}

void AHeroPawn::TraceAction()
{
	FVector EyeLocation;
	FRotator EyeRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(EyeLocation, EyeRotation);


	FCollisionQueryParams TraceParameters(TEXT(""), false, GetOwner());

	FHitResult Hit;

	FVector EndLocation = EyeLocation + EyeRotation.Vector() * ActionDistance;
	

	GetWorld()->LineTraceSingleByObjectType(
		Hit, // result
		EyeLocation, // start trace
		EndLocation,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_WorldDynamic),
		TraceParameters
	);

	// actor
}

// Called when the game starts or when spawned
void AHeroPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHeroPawn::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}


void AHeroPawn::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

// Called every frame
void AHeroPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHeroPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AHeroPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AHeroPawn::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
}
