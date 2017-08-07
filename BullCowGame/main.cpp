#include <iostream>
#include <string>	
#include "FBullCowGame.h"

FBullCowGame BCGame; 


void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

int MaxTries = BCGame.GetMaxTries();
int CurrentTry = BCGame.GetCurrentTry();



// the entry point for our application
int main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);

	return 0; // exit the application
}


// introduce the game
void PrintIntro()
{
	constexpr int WORLD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}


void PlayGame()
{
	
	for (int CurrentTry; CurrentTry <= MaxTries; CurrentTry++) 
	{
		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}


std::string GetGuess()
{
	// get a guess from the player
	std::cout << "Try number: " << CurrentTry ;
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
