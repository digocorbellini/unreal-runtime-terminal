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
	}

	// TODO: temporarily just set terminal text to the submitted text commit
	TerminalTextBlock->SetText(text);
}