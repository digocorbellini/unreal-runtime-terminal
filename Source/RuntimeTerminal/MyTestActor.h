// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyUserWidget.h"
#include "MyTestActor.generated.h"

UCLASS()
class RUNTIMETERMINAL_API AMyTestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool didTickStuff;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void TestPrint();

	TMap<FString, TFunction<void()>> functionsMap;

	void MapFunction(FString strKey, TFunction<void()> callbackLambda);
};
