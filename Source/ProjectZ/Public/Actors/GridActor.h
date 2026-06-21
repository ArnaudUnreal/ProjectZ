// Copyright Arnaud Szobad 2026. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridActor.generated.h"

UCLASS()
class PROJECTZ_API AGridActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGridActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
