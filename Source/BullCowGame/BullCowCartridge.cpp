// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
	Super::BeginPlay();
	Isograms = GetValidWords(Words);


	SetupGame();// Seting Up Game
	PrintLine(TEXT("The number of possible words is %i."), Words.Num());

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
	HiddenWord = Words[FMath::RandRange(0, Words.Num() - 1)]; // Set HiddenWord
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
		PrintLine(TEXT("Character %i of the hidden word is: %c"), i + 1, HiddenWord[i]);
	}

	// Prompt Player for Guess
}

void UBullCowCartridge::EndGame()
{
	bGameOver = true;
	ClearScreen();
}

void UBullCowCartridge::ProcessGuess(const FString& Guess)
{
	if (Guess == HiddenWord)
	{
		EndGame();
		PrintLine(TEXT("You win!"));
		PrintLine(TEXT("Press enter to continue."));
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
			PrintLine(TEXT("You have no lives left."));
			PrintLine(TEXT("Press enter to continue."));
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
	int32 Bulls, Cows;
	GetBullCows(Guess, Bulls, Cows);

	PrintLine(TEXT("You Have %i Bulls and %i Cows"), Bulls, Cows);
	PrintLine(TEXT("You lost a life you have %i lives left."), Lives);
	PrintLine(TEXT("the hidden word is %i letters long"), HiddenWord.Len());



}


bool UBullCowCartridge::IsIsogram(const FString& Word) const
{
	for (int32 Index = 0; Index < Word.Len(); Index++)
	{
		for (int32 Comparison = Index + 1; Comparison < Word.Len(); Comparison++)
		{
			if (Word[Index] == Word[Comparison])
			{
				return false;
			}
		}
	}

	return true;
}


TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordList) const
{
	TArray<FString> ValidWords;

	for (FString Word : WordList)
	{
		if (Word.Len() >= 4 && Word.Len() <= 8 && IsIsogram(Word))
		{
			ValidWords.Emplace(Word);
		}
	}
	return ValidWords;
}

void UBullCowCartridge::GetBullCows(const FString& Guess, int32& BullCount, int32& CowCount) const
{
	BullCount = 0;
	CowCount = 0;

	// for every index Guess is same as index Hidden, BullCount ++
	// if not a bull was it a cow? if Yes CowCount ++

	for (int32 GuessIndex = 0; GuessIndex < Guess.Len(); GuessIndex++)
	{
		if (Guess[GuessIndex] == HiddenWord[GuessIndex])
		{
			BullCount++;
			continue;
		}

		for (int32 HiddenIndex = 0; HiddenIndex < HiddenWord.Len(); HiddenIndex++)
		{
			if (Guess[GuessIndex] == HiddenWord[HiddenIndex])
			{
				CowCount++;
			}

		}
	}

}
