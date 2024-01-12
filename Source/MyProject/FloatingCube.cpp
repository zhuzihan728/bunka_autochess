// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingCube.h"

// Sets default values
AFloatingCube::AFloatingCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    VisualMesh->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

    if (CubeVisualAsset.Succeeded())
    {
        VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
        VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    }
}

// Called when the game starts or when spawned
void AFloatingCube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingCube::Tick(float DeltaTime)
{
	//int32 drawint = RandomDrawN(10, 0);
	//FString log_drawint = FString::FromInt(drawint);
	//UE_LOG(LogTemp, Warning, TEXT("This is the data: %s"), *FString(log_drawint));
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 20.0f;	 // Scale our height by a factor of 20
	float DeltaRotation = DeltaTime * 20.0f; // Rotate by 20 degrees per second
	NewRotation.Yaw += DeltaRotation;
	SetActorLocationAndRotation(NewLocation, NewRotation);
}


void AFloatingCube::RandomArrangeArr(TArray<int32> inArray, int32 n, TArray<int32>& outArray)
{
	// desc: choose n non-duplicate elements from inArray. 
	// inArray: the domain to sample from
	// n: the number of elements to sample, if n==0, n = len(inArray)

	int32 len = inArray.Num();
	TArray<int32> tempArray;
	int32 drawn_ind;
	int32 drawn_num;
	int32 cnt = n;
	if (cnt == 0) {
		cnt = len + 10;
	}

	for (int32 ind = len; ind != 0; --ind)
	{
		if (cnt == 0) {
			break;
		}

		drawn_ind = FMath::RandRange(1, ind) - 1;
		drawn_num = inArray[drawn_ind];
		tempArray.Add(drawn_num);
		inArray[drawn_ind] = inArray[ind - 1];
		cnt = cnt - 1;

	}

	outArray = tempArray;
}
