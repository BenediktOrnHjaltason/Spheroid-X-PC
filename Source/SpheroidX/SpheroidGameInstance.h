﻿// copyright Benedikt Orn Hjaltason
// *****---->PC VERSION <----*****

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "SpheroidSaveGame.h"
#include "SpheroidGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SPHEROIDX_API USpheroidGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	USpheroidGameInstance();

	FString SlotName = TEXT("SpheroidOne");
	uint32 UserIndex = 0;

	int NumberOfLevels = 48;

	//99 for opening main menu
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Levels)
		int LevelIndex = 99;

	bool bIsFreshSessionStart = true;
	//This actually saves LevelTimes, LevelsLocked and bPortalHasBeenUnlocked
	UFUNCTION(BlueprintCallable)
		void SaveLevelTimesToDisk();

	UFUNCTION(BlueprintCallable)
	void LoadLevelTimesFromDisk();


	//-----------Level times----------//

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<float> LevelTimes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<bool> LevelsLocked;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FString> LevelTimesString;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float CurrentTimeSeconds = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int CurrentTimesMilliSeconds = 0;

	//--Temp variable--//

	int i_Minutes = 0;
	FString S_Minutes = "";
	int i_Seconds = 0;
	FString S_Seconds = "";
	FString S_Milliseconds = "";
	//------------------//

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float fCurrentLevelTime{ 0.f };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float OldTimeForComparison{ 0.f };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString sCurrentLevelTime{"00 : 00 : 00"};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString sPreviousBestTime{"00 : 00 : 00"};

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool bPortalHasBeenUnlocked = false;

	void ManageNewHighScore(float NewTime);

	void BreakTimeLevelEnd(const float& f_Seconds, const int&p_LevelIndex);

	void BreakTimeLoad(const float& f_Seconds, const int&LevelIndex);

	float GetLevelTime() { return LevelTimes[LevelIndex]; }
	void SetLevelTime(float NewTime) { LevelTimes[LevelIndex] = NewTime; }

	bool DummyTest = true;

};
