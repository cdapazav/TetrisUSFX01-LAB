// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include <string>
#include "Containers/Map.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Block.h"
#include "Piece.h"
#include "TetrisUSFX01GameModeBase.generated.h"



using namespace std;

UCLASS()
class TETRISUSFX01_API ATetrisUSFX01GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY()
	ABlock* SpawnedActor;
	
	UPROPERTY()
	APiece* SpawnedPiece;

	UFUNCTION()
	void DestroyActorFunction();

	virtual void Tick(float DeltaTime) override;

};
