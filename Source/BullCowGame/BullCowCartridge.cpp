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

	const TCHAR HW[] = TEXT("isogram");
	//PrintLine(TEXT("Character 1 of the hidden word is: %c"), HiddenWord[0]);
	for (int i = 0; i < HiddenWord.Len(); ++i)
	{
		PrintLine(TEXT("Character %i of the hidden word is: %c"), i+1, HiddenWord[i]);
	}

	// Prompt Player for Guess
}

void UBullCowCartridge::EndGame()
{
	bGameOver = true;
	ClearScreen();
	PrintLine(TEXT("You have no lives left."));
	PrintLine(TEXT("Press enter to continue."));
}

void UBullCowCartridge::ProcessGuess(const FString& Guess)
{
	if (Guess == HiddenWord)
	{
		PrintLine(TEXT("You win!"));
		EndGame();
		return;
	}



	else
	{
 	
		if (Guess.Len() != HiddenWord.Len())
		{
			PrintLine(TEXT("The hidden word is %i characters long!"), HiddenWord.Len());
		}

		--Lives;
		if (Lives <= 0)
		{
			EndGame();
			return;
		}


	}


	// Check If Isogram
	 if (!IsIsogram(Guess))

	 {
		/* code */
		PrintLine(TEXT("No repeating letters, guess again"));
		return;
	 }

	// Prompt To Guess Again
	// Check Right Number Of Characters
	{	
		PrintLine(TEXT("You lost a life you have %i lives left."), Lives);	
		PrintLine(TEXT("the hidden word is %i letters long"), HiddenWord.Len());
		return;
	}
	// Prompt To Guess Again
	// Remove Life

	// Show Player Bulls and cows
	// Check If Lives > 0
	// Yes PlayAgain
	// If No Show GameOver
	// Press Enter to play again
	// Check User Input
	// Play Again Or Quit

}


bool UBullCowCartridge::IsIsogram(const FString& Word)
{
	for (int32 Index = 0, Comparison = Index + 1; Comparison < Word.Len(); Comparison++)
	{
		if (Word[Index] == Word[Comparison])
		{
			return false;
		}
	}
	//	For each letter.
	//	Strart at element [0].
	//	Until we reach [Word.Len() -1].
	//	if any are the same return false.


	return true;
}
