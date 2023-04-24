// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestActor.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "RuntimeTerminalGameModeBase.h"


// Sets default values
AMyTestActor::AMyTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	didTickStuff = false;
}

// Called when the game starts or when spawned
void AMyTestActor::BeginPlay()
{
	Super::BeginPlay();
	
	// get reference to runtime terminal
	/*TArray<UUserWidget*> FoundWidgets;
	UWidgetBlueprintLibrary::GetAllWidgetsOfClass(GetWorld(), FoundWidgets, UMyUserWidget::StaticClass());
	if (FoundWidgets.Num() > 0)
	{
		runtimeTerminal = (UMyUserWidget*)FoundWidgets[0];

		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("begin play pass lambda"));

		runtimeTerminal->MapFunction("testPrint", [this]() {TestPrint();});
	}
	else 
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("no widgets found"));
	}*/
	
	/*ARuntimeTerminalGameModeBase* mode = (ARuntimeTerminalGameModeBase *)UGameplayStatics::GetGameMode(GetWorld());
	if (mode)
	{
		if (mode->runtimeTerminal)
			mode->runtimeTerminal->MapFunction(TEXT("testPrint"), []() { GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Red, TEXT("printing in tick"));});
		else
			GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Red, TEXT("runtimeTerminal not initialized yet"));
	}*/


	//functionsMap.Add(TEXT("testPrint"), []() {GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Red, TEXT("test method")); });
	//MapFunction(TEXT("testPrint"), []() {GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Red, TEXT("test method")); });
	//MapFunction(TEXT("testPrint"), [this]() { TestPrint(); });
}

// Called every frame
void AMyTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ARuntimeTerminalGameModeBase* mode = (ARuntimeTerminalGameModeBase*)UGameplayStatics::GetGameMode(GetWorld());
	
	if (mode != nullptr && mode->beginPlayRan == true && !didTickStuff)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("tried to run runtime terminal things"));

		didTickStuff = true;

		if (mode)
		{
			if (mode->runtimeTerminal)
				mode->runtimeTerminal->MapFunction(TEXT("testPrint"), []() { GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, TEXT("testPrint Called"));});
			else
				GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("runtimeTerminal not initialized yet"));
		}
	}
	else
	{
		if (mode == nullptr)
			GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Red, TEXT("can't run runtime terminal things"));
	}

	GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Red, TEXT("printing in tick"));

	//TFunction<void()>* currFunct = functionsMap.Find("testPrint");
	//if (currFunct)
	//{
	//	// call function
	//	//((void (*)(void)) currFunct)();
	//	GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Red, TEXT("maped function found and called"));

	//	(*currFunct)();
	//}
}

void AMyTestActor::TestPrint()
{
	// print out something to console
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("test print called"));
}

void AMyTestActor::MapFunction(FString strKey, TFunction<void()> callbackLambda)
{
	//((void (*)(void)) functionPointer)();
	GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Red, TEXT("map function called"));

	functionsMap.Add(strKey, callbackLambda);
}

