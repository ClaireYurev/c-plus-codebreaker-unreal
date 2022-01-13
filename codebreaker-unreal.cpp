#include <iostream>    // PREPROCESSOR DIRECTIVE : include access to input and output stream
#include <ctime>       // PREPROCESSOR DIRECTIVE : gain access to the computer's time 
#include <string>      // PREPROCESSOR DIRECTIVE : include strings
using namespace std;

// # Easter Egg: int32 2201010001
// Easter Egg: int64
// 2022

string g_firstName;    // Global: will be used in several functions

void CopyrightNotice()
{
// Prints the description of this program to the terminal
    std::cout << "\nCreated by Claire for the open-source community. Published with the MIT License (C) 1997 - 2021\n";          // EXPRESSION STATEMENT
}

void GameExplanation()
{
// Declares a string variable to store the name of the user:
//  string firstName;
// Prints an explanation of the game for the user:
    std::cout << "\nWhat's your name? (No spaces please): ";
// Records input from the user ("cin" considers any space (i.e. tabs, whitespace, etc) a terminating character, so it can only display a single word
    std::cin >> g_firstName;
// Greets the user:
    std::cout << "\nWelcome to \"The Gateway\", "<< g_firstName;          // EXPRESSION STATEMENT
    std::cout << ".";          // EXPRESSION STATEMENT
}


void PrintIntroduction(int Difficulty)
{
// Print welcome messages to the terminal
    std::cout << " \n";                           // EXPRESSION STATEMENT
    std::cout << "\nYou are a security researcher testing a level " << Difficulty;                    // EXPRESSION STATEMENT
    std::cout << " virtual server instance.\nYou need to enter the correct answer on each level to continue...\n\n";                              // EXPRESSION STATEMENT
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    
    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;                                    // DECLARATION STATEMENT
    const int CodeB = rand() % Difficulty + Difficulty;                                    // DECLARATION STATEMENT
    const int CodeC = rand() % Difficulty + Difficulty;                                    // DECLARATION STATEMENT

    const int CodeSum = CodeA + CodeB + CodeC;              // DECLARATION STATEMENT
    const int CodeProduct = CodeA * CodeB * CodeC;          // DECLARATION STATEMENT

    // Print CodeSum and CodeProduct to the terminal
    std::cout << "> There are 3 numbers in the code.\n";                             // EXPRESSION STATEMENT 
    std::cout << "\n> The codes add up to: " << CodeSum;                             // EXPRESSION STATEMENT
    std::cout << "\n> The codes multiply to give: " << CodeProduct;                  // EXPRESSION STATEMENT
    std::cout << std::endl;  
    std::cout << std::endl;  

    // Store player guess
    int GuessA, GuessB, GuessC;                           // DECLARATION STATEMENT
    std::cin >> GuessA >> GuessB >> GuessC;       // EXPRESSION STATEMENT    HERE THE PROGRAM WILL PAUSE AND WAIT FOR INPUT

    int GuessSum = GuessA + GuessB + GuessC;              // DECLARATION STATEMENT
    int GuessProduct = GuessA * GuessB * GuessC;          // DECLARATION STATEMENT

    // Check whether the player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)        // CONDITION
    { 
        std::cout << "\n*** Well done agent! You've extracted a file! Moving on to the next level... ***";
        return true;
    }
    else
    {
        std::cout << "\n*** Careful "<< g_firstName;
        std::cout << "! You've guessed wrong... Try again, and remember:";
        return false;
    }
    //No need to type return zero because the return type of our function is void, so it returns no data.
}

int main()   // MAIN FUNCTION
{
    srand(time(NULL)); // Creates new random sequence based on the time of day, needs ctime to be included in the header
    
    int LevelDifficulty = 1;
    
    int const MaxDifficulty = 5; 

    CopyrightNotice();

    GameExplanation();
    
    while (LevelDifficulty <= MaxDifficulty) // Loop the game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty); //UNREAL's coding standards require all boolean variable names to be prefixed with b in front of variable name
        std::cin.clear();  // Clears any errors   -NOT NEEDED IN UNREAL
        std::cin.ignore(); // Discards the buffer -NOT NEEDED IN UNREAL

        if (bLevelComplete)
        {
            // increase the level difficulty
            ++LevelDifficulty;
        }       
    }
    
    std::cout << "\n\n*** CONGRATULATIONS ~ YOU WON THE GAME !!! ***\n";
    return 0;   // RETURN STATEMENT
}