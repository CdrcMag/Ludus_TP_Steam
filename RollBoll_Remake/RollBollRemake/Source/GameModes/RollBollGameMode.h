// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
//Incluide Steam API
#include "RollBollRemake/Steam/steam_api.h"
#include "RollBollRemakeGameModeBase.generated.h"
//Definition ID
#define RAW_APP_ID "480"


class APlayerControllerBase;
UCLASS()
class ROLLBOLL_API ARollBollGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
private:

	APlayerControllerBase* PlayerControllerRef;


	void HandleGameStart();
	void HandleGameOver(bool PlayerWon);

public:

	void ActorDie(AActor* DeadActor);

	static constexpr char* APP_ID = RAW_APP_ID;
	CSteamID MyId;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Loop")
	int32 StartDelay = 5;


	virtual void BeginPlay() override;
	UFUNCTION(BlueprintImplementableEvent)
	void GameStart();
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool PlayerWon);
};