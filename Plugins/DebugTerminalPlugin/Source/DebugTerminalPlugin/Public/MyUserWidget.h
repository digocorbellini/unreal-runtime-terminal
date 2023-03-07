// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

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
};
