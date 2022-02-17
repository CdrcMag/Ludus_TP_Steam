// Fill out your copyright notice in the Description page of Project Settings.


#include "RollBollGameModeBase.h"
#include "RollBollRemake/Pawns/PawnTank.h"
#include "RollBollRemake/Pawns/PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "RollBollRemake/PlayerControllers/PlayerControllerBase.h"



//At Start
void ARollBollGameModeBase::BeginPlay() 
{
    Super::BeginPlay();

    HandleGameStart();

	//ID STEAM
	FFileHelper::SaveStringToFile(TEXT(RAW_APP_ID), TEXT("steam_appid.txt"));

	SteamAPI_RestartAppIfNecessary(atoi(APP_ID));

    //Initialisation
	if (SteamAPI_Init()) {
		MyId = SteamUser()->GetSteamID();
	}

    //Get name
	const char*name = SteamFriends()->GetPersonaName();

}

