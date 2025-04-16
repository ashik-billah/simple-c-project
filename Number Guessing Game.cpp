#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getValidatedInput(int min, int max) {
    int input;
    while (true) {
        cin >> input;
        if (cin.fail() || input < min || input > max) {
            clearInput();
            cout << "Invalid input! Please enter a number between " << min << " and " << max << ": ";
        } else {
            break;
        }
    }
    return input;
}

int chooseDifficulty() {
    cout << "\nSelect Difficulty Level:\n";
    cout << "1. Easy (1 - 50)\n";
    cout << "2. Medium (1 - 100)\n";
    cout << "3. Hard (1 - 200)\n";
    cout << "Enter your choice (1-3): ";

    return getValidatedInput(1, 3);
}

void playGame(int maxRange) {
    int numberToGuess, userGuess, attempts = 0;
    srand(time(0));
    numberToGuess = rand() % maxRange + 1;

    cout << "\n Game Started! Guess a number between 1 and " << maxRange << ".\n";

    do {
        cout << "Enter your guess: ";
        userGuess = getValidatedInput(1, maxRange);
        attempts++;

        if (userGuess > numberToGuess) {
            cout << " Too high! Try again.\n";
        } else if (userGuess < numberToGuess) {
            cout << " Too low! Try again.\n";
        } else {
            cout << " Congratulations! You guessed the number in " << attempts << " attempts.\n";
        }
    } while (userGuess != numberToGuess);
}

int main() {
    cout << "            Welcome to  Number Guessing Game! \n";

    bool playAgain = true;
    while (playAgain) {
        int difficulty = chooseDifficulty();
        int maxRange = (difficulty == 1) ? 50 : (difficulty == 2) ? 100 : 200;

        playGame(maxRange);

        cout << "\nDo you want to play again? (1 = Yes, 0 = No): ";
        playAgain = getValidatedInput(0, 1);
    }

    cout << " Thanks for playing! Goodbye!\n";
    return 0;
}
