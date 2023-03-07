// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

UENUM()
enum class EParamType : uint8
{
	FLOAT,
	INT,
	BOOL,
	STRING,
	CHAR,
};

/**
 * 
 */
UCLASS()
class DEBUGTERMINALPLUGIN_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* TerminalTextBlock;

	UPROPERTY(meta = (BindWidget))
		class UEditableTextBox* InputTextBox;

	// works like a constructor
	void NativeConstruct() override;

	UFUNCTION()
		void OnTextCommit(const FText& text, ETextCommit::Type commitMethod);

	FString TerminalString;

	const int MAX_NUM_LINES = 9;
	const int MAX_CHAR_PER_LINE = 50;

//public:
//	// TODO: have a way to take in function pointers
//	UFUNCTION()
//		void MapFunction(FString stringKey, UObject* userObject);
};
