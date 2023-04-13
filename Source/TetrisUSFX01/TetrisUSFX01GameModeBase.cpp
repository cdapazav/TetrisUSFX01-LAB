// Copyright Epic Games, Inc. All Rights Reserved.


#include "TetrisUSFX01GameModeBase.h"

void ATetrisUSFX01GameModeBase::BeginPlay()
{
    // Call the parent class version of this function

    Super::BeginPlay();

    // Displays a red message on the screen for 10 seconds

 /*   GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Spawning un Block"));*/

    // Spawn an instance of the AMyFirstActor class at the
    //default location.

    /*TMap<string, FVector> PosicionesPieza;


    FTransform SpawnLocation;
    SpawnedActor = GetWorld()->SpawnActor<ABlock>(ABlock::StaticClass(), SpawnLocation);
    SpawnedActor->SetActorRelativeLocation(FVector(0.0, 0.0, 0.0));

    GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Spawning un Piece"));
    SpawnedPiece = GetWorld()->SpawnActor<APiece>(APiece::StaticClass(), SpawnLocation);
    SpawnedPiece->SetActorRelativeLocation(FVector(0.0, 100.0, 0.0));
    SpawnedPiece->SpawnBlocks();*/

}

void ATetrisUSFX01GameModeBase::DestroyActorFunction()
{
	if (SpawnedActor != nullptr)
   {
      // Displays a red message on the screen for 10 seconds
      GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Actor Block destruido"));
      SpawnedActor->Destroy();
   }
}

// Declarar una variable para contar el tiempo transcurrido
float TiempoTranscurrido = 0.0f;

void ATetrisUSFX01GameModeBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    TiempoTranscurrido += DeltaTime;

    // Generar una nueva pieza cada 5 segundos durante los primeros 30 segundos
    if (TiempoTranscurrido < 30.0f && fmod(TiempoTranscurrido, 5.0f) < DeltaTime)
    {
        FTransform SpawnLocation;
        // Establecer una distancia de 50 unidades en el eje Z o Y
        FVector SpawnOffset = FVector(0.0f, 0.0f, 20.0f);
        SpawnLocation.SetLocation(GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation() + SpawnOffset);

        GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Spawning un Block"));
        SpawnedActor = GetWorld()->SpawnActor<ABlock>(ABlock::StaticClass(), SpawnLocation);
        SpawnedActor->SetActorRelativeLocation(FVector(0.0, 0.0, 0.0));

        GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Spawning un Piece"));
        SpawnedPiece = GetWorld()->SpawnActor<APiece>(APiece::StaticClass(), SpawnLocation);
        SpawnedPiece->SetActorRelativeLocation(FVector(0.0f, 100.0f, 0.0f));
        SpawnedPiece->SpawnBlocks();
    }
}



