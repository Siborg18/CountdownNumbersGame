// CountdownNumbersGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <chrono>
#include <iostream>
#include <vector>
#include <random>



std::mt19937 randomSeed()
{

    std::mt19937 mt{ std::random_device{}() };

    return mt;
}

std::vector<int> bigNumberVector(int amount)
{
    std::vector<int> possibleBigNumbers{25, 50, 75, 100};
    auto rng = std::default_random_engine{ randomSeed() };
    std::shuffle(std::begin(possibleBigNumbers), std::end(possibleBigNumbers), rng);
    std::cout << std::endl;
    
    for (int x{ 0 }; x < possibleBigNumbers.size(); x++)
    {
        std::cout << possibleBigNumbers[x];
    }

    for (int x{ 0 }; x < amount; x++)
    {
        int bigNumber{0};
        bigNumber = possibleBigNumbers[possibleBigNumbers.size() - 1];
        std::cout << "Big number: " << bigNumber;
    }

    return possibleBigNumbers;
}

std::vector<int> smallNumberVector(int amount)
{
    std::vector<int> smallNumbers{};
    std::vector<int> possibleNumbers{1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10};
    // Shuffle vector
    auto rng = std::default_random_engine{randomSeed()};
    std::shuffle(std::begin(possibleNumbers), std::end(possibleNumbers), rng);

    for (int x{ 0 }; x < possibleNumbers.size(); x++)
    {
        std::cout << possibleNumbers[x];
    }
    
    // pick number from list
    // numbers available are 2 sets of 1 - 10
    return smallNumbers;
}

int targetNumber(int min, int max)
{
    srand(time(NULL)); // Seed the time
    int randomTarget = rand() % (max - min + 1) + min; // Generate the number, assign to variable.
    return randomTarget;
}

int main()
{
    std::cout << "How many big numbers? (Type 1, 2, 3, or 4)" << std::endl;
    int userInput{ 0 };
    std::cin >> userInput;
    std::cout << targetNumber(101, 999) << std::endl;
    bigNumberVector(userInput);
    std::cout << std::endl;
    smallNumberVector(6 - userInput );
}


