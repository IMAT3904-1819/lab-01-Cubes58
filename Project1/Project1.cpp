// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Randomiser.h"

int main() {
	constexpr const int minNumber(1);
	constexpr const int maxNumber(1000);
	constexpr const int numberOfAllowedAttempts(5);

	std::cout << "Guess a number between: " << minNumber << " and " << maxNumber << std::endl;

	int generatedNumber = Randomiser::getInstance().getRand(minNumber, maxNumber);
	int attemptsMade(0);
	int numberGuessed(0);
	bool guessed(false);

	std::cout << "You have " << numberOfAllowedAttempts << " to guess the correct number!" << std::endl;
	while (!guessed && attemptsMade < numberOfAllowedAttempts) {
		std::cout << "What is your guess? ";

		while (!(std::cin >> numberGuessed) || (numberGuessed > maxNumber || numberGuessed < minNumber)) {
			std::cout << "Make sure to enter a number.And make sure it's greater than or equal to " 
				<< minNumber << " and lower than or equal to the " << maxNumber << "\n" 
				<< "Try again: ";
		}

		if (numberGuessed < generatedNumber) {
			++attemptsMade;
			std::cout << "Number of attempts: " << attemptsMade << "\n" 
				<< "Your guess was too low, try guessing higher!" << std::endl;
		}
		else if (numberGuessed > generatedNumber) {
			++attemptsMade;
			std::cout << "Number of attempts: " << attemptsMade << "\n"
				<< "Your guess was too high, try guessing lower!" << std::endl;
		}
		else {
			guessed = true;
			std::cout << "You've succeeded, great job! :)" << std::endl;
		}
	}

	std::cout << "\n\n\n" << std::endl;
	system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
