// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestActor.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

// Sets default values
AMyTestActor::AMyTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyTestActor::BeginPlay()
{
	Super::BeginPlay();
	
	// get reference to runtime terminal
	TArray<UUserWidget*> FoundWidgets;
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
	}
}

// Called every frame
void AMyTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Red, TEXT("printing in tick"));
}

void AMyTestActor::TestPrint()
{
	// print out something to console
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("test print called"));
}

