// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"
#include "Components/EditableTextBox.h"
#include "Components/TextBlock.h"

void UMyUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// TODO: give listeners to input text box delegates
	InputTextBox->OnTextCommitted.AddUniqueDynamic(this, &UMyUserWidget::OnTextCommit);
}

void UMyUserWidget::OnTextCommit(const FText& text, ETextCommit::Type commitMethod)
{
	if (commitMethod == ETextCommit::OnEnter)
	{
		// Only handle/parse input if we pressed enter

		// TODO: see if we have to clear field after enter and how we can 
		// prevent clearing on unfocusing
		InputTextBox->SetText(FText::FromString(""));

		//// Add text to terminal
		TerminalString = FString::Printf(TEXT("> ")) + text.ToString() + FString::Printf(TEXT("\n"));

		// TODO: handle keeping terminal string within bounds of terminal box

		TerminalTextBlock->SetText(FText::FromString(TerminalString));

		// call function if the string key exists
		TFunction<void()> *currFunct = functionsMap.Find(text.ToString());
		if (currFunct)
		{
			// call function
			(*currFunct)();

			TerminalTextBlock->SetText(FText::FromString(TerminalString + " invoked"));
		}
		else
		{
			TerminalTextBlock->SetText(FText::FromString(TerminalString + " not found"));
		}
	}

	// TODO: temporarily just set terminal text to the submitted text commit
	//TerminalTextBlock->SetText(text);
}

void UMyUserWidget::MapFunction(FString strKey, TFunction<void()> callbackLambda)
{
	functionsMap.Add(strKey, callbackLambda);
}