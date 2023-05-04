/*************************************************************
 *  Instructor's Name: Mrs. Vernelle Sylvester                                 *
 *  Group Members: Lianni Mathews, Jason Fortik                         *
 *  Project: Hangman                                                                          *
 *  Description: Hangman utilizes object oriented programming    *
 *  to create an object that stores the statistics that are being        *
 *  generated and also uses classes to separate the functions and  *
 *  their declarations as libraries outside the main file                   *
 *  Due Date: March 25,2021                                                             *
 *************************************************************/
#include "player.h"
#include <string>
#include <iostream>

using std::to_string;
typedef unsigned int uint;
using std::string;

//set the username, difficulty level and executes a possible/optional reset to the game
Player::Player(string username, uint level )
{
    setUsername(username);
    setDifficultyLevel(level);
    resetGuessesArray();
}

//check if the user input is within the possible difficulty level provided;
void Player::setDifficultyLevel(uint level)
{
    if(level > 1 && level <= Player::MAX_DIFICULTY_LEVEL)
    {
        difficultyLevel = level;
    }
    difficultyLevel = 1; //else set dificulty to a default of 1
}

//returns the level
int Player::getDifficultyLevel()
{
    return difficultyLevel;
}

//returns the username
string Player::getUsername()
{
    return username;
}

//sets the username
void Player::setUsername(string name)
{
    for (string::size_type i = 0, l = name.length(); i <= l ; i++) //loops through the string and assigns it to the player char array
    {
        username[ i ] = name[ i ];
    }
}

//stores the amount of guesses the player makes
void Player::setGuesses(unsigned int numGuesses)
{
    for (int i = 0; i < 10; i++)
    {
            if(numGuesses == 0 && guessArray[ i ] == 0 ) //if user guesses with one try
                {
                    guessArray[ i ] = 1;
                    break;
                }
            if(guessArray[ i ] == 0 ) //if user guesses with more than one try.
                {
                    guessArray[ i ] = numGuesses;
                    break;
                }
            if(guessArray[ 9 ] != 0) //resets the array back to 0
                resetGuessesArray();
    }
}

//returns player stats after the game ends
string Player::generateStatistics()
{
    string stats = "Guesses: "; //returns the amount of guesses and average of guesses as a string
    int sum = 0;
    int totalGuesses = 0;
    for (int i = 0; i < 10; i++) //calculate the total amount of guesses and the sum of the guesses
    {
        if(guessArray[ 0 ] == 0 )//if the first vale is 0 after the person has guessed then it will initialize both sum and total guesses to 1
            {
                totalGuesses = 1;
                sum = 1;
                break;
            }
        if(guessArray[ i ] == 0) //evaluates whether the guessArray at i contains a zero value
            break;
        sum += guessArray[ i ]; //adds the amount of guesses at each non zero location to the sum
        totalGuesses ++; //increments the number of guesses by 1 for every non zero value
    }

    float average = sum / static_cast<float>(totalGuesses); //calculates the average

    for(int i = 0; i < 10; i++)
    {
        if(guessArray[ i ] != 0)
            {
                stats += to_string(guessArray[i]);
                stats += ' ';
            }
    }
    stats += " \n";
    stats += "Average Guesses: ";
    stats += to_string(average);
    stats += " \n";
    return stats; //returns the entire string that contains the stats that were generated
}

//reset the guesses to zero
void Player::resetGuessesArray()
{
    for (int i = 0; i < 10; i++)
    {
        guessArray[ i ] = 0;
    }
}
