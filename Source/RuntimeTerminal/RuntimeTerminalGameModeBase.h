// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyUserWidget.h"
#include "RuntimeTerminalGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class RUNTIMETERMINAL_API ARuntimeTerminalGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ARuntimeTerminalGameModeBase();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMyUserWidget *runtimeTerminal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool beginPlayRan;
};
