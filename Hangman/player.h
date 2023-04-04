#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
using namespace std;


class Player
{
private:
    int guessesArray[10];// GuessesArray contains 10 available locations
    char username[20];//Username array contains 20 available locations
    unsigned int difficultyLevel;
    static const unsigned int MAX_DIFFICULTY_LEVEL = 3;  //sets the highest possible difficulty level

public:
    Player(string username, unsigned int level = 1);
    void setDifficultyLevel(unsigned int level);
    int getDifficultyLevel();
    string getUsername();
    void setUsername(string name);
    void setGuesses(unsigned int numGuesses);
    string generateStatistics();
    void resetGuessesArray();
    //7 functions-Jenny

};

#endif // PLAYER_H
