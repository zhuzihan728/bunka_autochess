// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingCube.generated.h"

UCLASS()
class MYPROJECT_API AFloatingCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingCube();
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	int32 RandomDrawN(int len, int n);
	
	UFUNCTION(BlueprintCallable, meta = (CallableWithoutWorldContext))
	void RandomArrangeArr(TArray<int32> inArray, int32 n, TArray<int32>& outArray);
};
