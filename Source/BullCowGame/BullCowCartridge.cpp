// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

	SetupGame();// Seting Up Game

}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
	ClearScreen();

	// Checking The players Guess
	

	if (bGameOver)
	{
		ClearScreen();
		SetupGame();
	}
	else
	{
		ProcessGuess(Input);
	}

}

void UBullCowCartridge::SetupGame()
{
	HiddenWord = TEXT("isogram"); // Set HiddenWord
	Lives = HiddenWord.Len(); // Set lives
	bGameOver = false;

	// Welcome The Player
	PrintLine(TEXT("WELCOME TO BULL COWS."));
	//PrintLine(TEXT("The HiddenWord is: %s.\r\nIt is %i characters long."), *HiddenWord, HiddenWord.Len());
	PrintLine(TEXT("Guess the %i letter word."), HiddenWord.Len());
	PrintLine(TEXT("You have %i lives."), Lives);
	PrintLine(TEXT("Type something and press enter."));

	// Prompt Player for Guess
}

void UBullCowCartridge::EndGame()
{
	bGameOver = true;
	PrintLine(TEXT("Press enter to continue."));
}

void UBullCowCartridge::ProcessGuess(const FString& Guess)
{
	if (Guess == HiddenWord)
	{
		PrintLine(TEXT("You win!"));
		EndGame();
	}
	else
	{
		if (Guess.Len() != HiddenWord.Len())
		{
			PrintLine(TEXT("The hidden word is %i characters long!"), HiddenWord.Len());
		}

		--Lives;
		if (Lives > 0)
		{
			PrintLine(TEXT("You lost a life you have %i lives left."), Lives);
		}
		else
		{
			PrintLine(TEXT("You lose."));
			EndGame();
		}

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
