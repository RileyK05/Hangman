#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string> 
#include <conio.h>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <chrono>
#include <thread>
#include <compare>
#include <stdio.h>
#include <windows.h>

class Letter {
public:

	char letter;

};

class Word : public Letter {
public:

	std::string word;

};

int main() {

	std::fstream file("wordsAndPhrases.txt", std::ios::in | std::ios::out | std::ios::app);

	Word word;
	
	int userStart;
	std::cout << "To play game, press 1\n"
		<< "To add new words and phrases, press 2\n"
		<< "Enter Input: ";
	std::cin >> userStart;
	std::cout << std::endl;

	if (userStart == 1) {

		int wrongGuesses = 0;

		std::string hangManArt[7] = {
		" +---+\n"
		" |   |\n"
		"     |\n"
		"     |\n"
		"     |\n"
		"     |\n"
		"==========",
		" +---+\n"
		" |   |\n"
		" O   |\n"
		"     |\n"
		"     |\n"
		"     |\n"
		"==========",
		" +---+\n"
		" |   |\n"
		" O   |\n"
		" |   |\n"
		"     |\n"
		"     |\n"
		"==========",
		" +---+\n"
		" |   |\n"
		" O   |\n"
		"/|   |\n"
		"     |\n"
		"     |\n"
		"==========",
		" +---+\n"
		" |   |\n"
		" O   |\n"
		"/|\\  |\n"
		"     |\n"
		"     |\n"
		"==========",
		" +---+\n"
		" |   |\n"
		" O   |\n"
		"/|\\  |\n"
		"/    |\n"
		"     |\n"
		"==========",
		" +---+\n"
		" |   |\n"
		" O   |\n"
		"/|\\  |\n"
		"/ \\  |\n"
		"     |\n"
		"=========="
		};

		std::cout << hangManArt[0] << std::endl;

		char character;
		int commaCount = 0;

		while (file.get(character)) {
			if (character == ',') {
				commaCount++;
			}
		}

		int randomPhrase;

		srand((unsigned)time(NULL));

		for (int i = 0; i < 1; i++) {
			randomPhrase = rand() % commaCount;
		}

		file.close();
		file.open("wordsAndPhrases.txt", std::ios::in);

		for (int j = 0; j <= randomPhrase; j++) {
			getline(file, word.word, ',');
		}

		int phraseLength = word.word.length();

		for (int k = 1; k <= phraseLength; k++) {
			std::cout << "_";
		}

		std::string wordUse;

		std::string guessedLetters(phraseLength, '_');

		file.close();

		bool run = true;

		while (run) {
			if (_kbhit()) {
				word.letter = _getch();

				system("cls");

				if (word.letter == '.') {
					break;
				}

				bool letterGuessed = false;

				std::string currentGuess = guessedLetters;

				for (int i = 0; i < phraseLength; i++) {
					if (word.word[i] == word.letter) {
						currentGuess[i] = word.letter;
						letterGuessed = true;
					}
				}

				std::cout << std::endl;

				if (letterGuessed) {
					std::cout << currentGuess << std::endl;
				}
				else {
					std::cout << "Incorrect guess" << std::endl
						<< currentGuess << std::endl;

					wrongGuesses++;
				}

				std::cout << hangManArt[wrongGuesses] << std::endl;

				guessedLetters = currentGuess;

				wordUse = currentGuess;
			}

			Sleep(10);

			if (wordUse == word.word) {
				std::cout << "Congrats, you won!" << std::endl;
				run = false;
				break;

			}

			if (wrongGuesses >= 6) {
				std::cout << "You lost :(" << std::endl;
				run = false;
				break;
			}


		}


	}

	else if (userStart == 2) {

		std::string writing;
		std::cout << "To exit writing program, type . " << std::endl;
		bool runProgram = true;

		std::cin.ignore();

		while (runProgram == true) {

			std::cout << "Enter the word or phrase(no commas): ";

			getline(std::cin, writing);
			std::cout << std::endl;


			if (writing == ".") {
				std::cout << "Program break" << std::endl;
				runProgram = false;
				break;
			}
			else {
				file << writing << ',';
			}

		}
		file.close();
	}
	return 0;
}






