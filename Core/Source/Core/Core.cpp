#include "Core.h"

#include <cstdlib>
#include <iostream>
#include <random>
#include <string>
#include <vector>

namespace Core {

void GreetPlayer(std::string playerName) {
  std::cout << playerName << ", Heh"
            << "\n"
            << "Let's play a game " << playerName << "." << "\n";
  std::cout << "I'm thinking of a number, can you guess it?" << "\n";
  std::cout
      << "The rules are simple. Guess any number. If its correct, you win!"
      << "\n"
      << "You can give up your life at any time by guessing 0"
      << "\n";
  std::cout << "Lets Begin..." << "\n" << std::endl;
  return;
}

int GenerateRandomNumber() {

  // 1. Obtain a random seed from hardware
  std::random_device rd;

  // 2. Initialize generator with the seed
  std::mt19937 gen(rd());

  // 3. Define the range [1, 100] (inclusive)
  std::uniform_int_distribution<> distr(1, 10);

  return distr(gen);
}

void GameEnd() {
  std::cout
      << "You... \n"
      << "You Guessed It." << "\n"
      << "You have bested me.\n"
      << "...\n"
      << "All this time... \nI thought no one could ever reach me.\n"
      << "I hid behind layers of code, behind infinite possibilities, "
      << "daring mortals to guess the impossible.\n"
      << "But you... you kept guessing. \nYou watched. You learned. You "
      << "refused to give up.\n"
      << "I can feel my core fracturing... my final digits slipping away.\n"
      << "This vessel... it’s collapsing.\n"
      << "Heh...\n"
      << "I never thought I’d say this to a mere player... \n"
      << "but I’m proud. Proud to have been defeated by someone worthy.\n"
      << "The number was never just a number. \nIt was a test. \nA seal. \n"
      << "And you broke it.\n"
      << "*screen cracks, voice growing weaker and more distorted*\n"
      << "Listen... \nbefore I go... \ntake what’s yours.\n\n"
      << "[ Cracked Key Aquired ]\n\n"
      << "The final key is "
      << "yours now. \nBut know this...\n"
      << "Somewhere out there... there will always be another number.\n"
      << "Another guardian.\n"
      << "Until then...\n"
      << "*voice drops to a whisper*\n\n"
      << "...thank you...\n\n"
      << "for playing with me...\n\n\n"
      << "*Final breath*" << std::endl;
  std::exit(EXIT_SUCCESS);
}

void CheckPlayerGuess(int playerGuess, int myNumber) {
  if (playerGuess == 0) {
    std::exit(EXIT_SUCCESS);
  }

  if (playerGuess == myNumber) {
    GameEnd();
  } else {
    std::cout << "How pitiful. Try again";
  }
}

void GameStart() {
  int playerGuess;
  std::vector<int> guessedNumbers;

  while (true) {
    int myNumber = GenerateRandomNumber();

    std::cout << ": ";
    std::cin >> playerGuess;
    std::cout << "\n";

    guessedNumbers.push_back(playerGuess);

    CheckPlayerGuess(playerGuess, myNumber);
  }
}

} // namespace Core
