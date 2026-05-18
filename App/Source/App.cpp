#include "Core/Core.h"
#include <iostream>
#include <string>

int main() {
  std::string playerName;
  std::cout << "A mere mortal dare approach me!\nWhat is your name: ";
  std::cin >> playerName;
  std::cout << "\n";
  Core::GreetPlayer(playerName);
  Core::GameStart();
}
