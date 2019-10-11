// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

	// Welcome The Player
	PrintLine(TEXT("WELCOME TO BULL COWS."));
	PrintLine(TEXT("Type something and press enter."));


	InitGame();// Seting Up Game
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
	ClearScreen();

	// Checking The players Guess


	


	if (Input == HiddenWord)
	{
		PrintLine(TEXT("You guessed it!"));
		
	}
	else
	{
		PrintLine(TEXT("Your were wrong!"));


		
	}
	// Check If Isogram
	// Prompt To Guess Agian
	// Check Right Number Of Characters
	// Prompt To Guess Agian

	// Remove Life


	// Check If Lives > 0
	// Yes PlayAgain
	// If No Show GameOver
	// Press Enter to play again
	// Check User Input
	// Play Again Or Quit

}

void UBullCowCartridge::InitGame()
{
	HiddenWord = TEXT("isogram"); // Set HiddenWord
	Lives = 4; // Set lives

	// Prompt Player for Guess
}


