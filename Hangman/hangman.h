#ifndef HANGMAN_H
#define HANGMAN_H

#include<iostream>
using namespace std;
#include<vector>
using std::vector;
#include <player.h>



/*
 * Program to create a Hangman Game
 * Created by Jenny Itza, Olusegun Joseph Ajibola, Francisco Tun, Shawn Escobar
 * Modified by Jenny Itza on the 3/27/2023
 */


class Hangman
{
public:
  const static int ALPHABET_SIZE = 26;//num of rows for alphabet array
  const static int ASCII_ROWS = 7;
  const static int ASCII_COLS = 8;
  Hangman(string filename, string username);//Jenny
  int selectGameLevel();
  int generateRandomNumber();
  string selectRandomWord(int random_number);
  void loadWordList(string fileName);//Joseph
  void startGame();
  void printMessage(string message, bool printTop = true, bool printBottom = true);
  void drawHangman(int guessCount = 0);
  void resetAvailableLetters();//Fransisco
  void printAsciiMessage(string message);
  void printAvailableLetters(string taken);
  bool checkWin(string wordToGuess, string guessesSoFar);
  bool processResults(string wordToGuess, int guessAttempts, bool hasWon);//Shawn
  void setDifficultyLevel(unsigned diffLevel);
  unsigned getDifficultyLevel();
  void setMaxAllowedAttempts(unsigned allowedAttempts);
  unsigned getMaxAllowedAttempts();
  unsigned attemptsMadeSoFar(std::string wordToGuess, std::string guessesSoFar);



private:
  Player player;
  vector<string> wordVector;
  unsigned difficultyLevel;
  unsigned maxAllowedAttempts;
  char alphabetArray[ALPHABET_SIZE + 1];
  constexpr static char G[ASCII_ROWS][ASCII_COLS]=
  {
     "  #### ", //Row=0
     " #     ", //Row=1
     " #     ", //Row=2
     " # ### ", //Row=3
     " #   # ", //Row=4
     " #   # ", //Row=5
     " ##### "};//Row=6

    constexpr static char A[ASCII_ROWS][ASCII_COLS]=
 {
     "  ###  ",   //row=0
     " #   # ",  //row=1
     " #   # ",  //row=2
     " ##### ",  //row=3
     " #   # ",  //row=4
     " #   # ",  //row=5
     " #   # "}; //row=6

 constexpr static char M[ASCII_ROWS][ASCII_COLS]=
 {
     " #   # ",  //row=0
     " # # # ",  //row=1
     " # # # ",  //row=2
     " #   # ",  //row=3
     " #   # ",  //row=4
     " #   # ",  //row=5
     " #   # "}; //row=6

 constexpr static char E[ASCII_ROWS][ASCII_COLS]=
 {
     " ##### ",   //row=0
     " #     ",   //row=1
     " #     ",   //row=2
     " ##### ",   //row=3
     " #     ",   //row=4
     " #     ",   //row=5
     " ##### "};  //row=6

 constexpr static char O[ASCII_ROWS][ASCII_COLS]=
 {
     "  ###  ",   //row=0
     " #   # ",   //row=1
     " #   # ",   //row=2
     " #   # ",   //row=3
     " #   # ",   //row=4
     " #   # ",   //row=5
     "  ###  "};  //row=6

 constexpr static char V[ASCII_ROWS][ASCII_COLS]=
 {
     " #   # ",  //row=0
     " #   # ",  //row=1
     " #   # ",  //row=2
     " #   # ",  //row=3
     " #   # ",  //row=4
     "  # #  ",  //row=5
     "   #   "}; //row=6

 constexpr static char R[ASCII_ROWS][ASCII_COLS]=
 {
     "  ###  ", //row=0
     " #   # ", //row=1
     " #   # ", //row=2
     " #  #  ", //row=3
     " # #   ", //row=4
     " #  #  ", //row=5
     " #   # "}; //row=6

  //vernelle did this , Row 0 to 6 needs to be for all
 constexpr static char Y[ASCII_ROWS][ASCII_COLS]=
 {   " #   # ", //Row=0
     " #   # ", //Row=1
     " #   # ", //Row=2
     "  ###  ", //Row=3
     "   #   ", //Row=4
     "   #   ", //Row=5
     "   #   "};//Row=6

 constexpr static char U[ASCII_ROWS][ASCII_COLS]=
 {
     " #   # ",  //row=0
     " #   # ",  //row=1
     " #   # ",  //row=2
     " #   # ",  //row=3
     " #   # ",  //row=4
     " #   # ",  //row=5
     " ##### "}; //row=6

 constexpr static char W[ASCII_ROWS][ASCII_COLS]=
 {
     " #   # ",  //row=0
     " #   # ",  //row=1
     " #   # ",  //row=2
     " #   # ",  //row=3
     " # # # ",  //row=4
     " ## ## ", //row=5
     " #   # "};//row=6

 constexpr static char N[ASCII_ROWS][ASCII_COLS]=
 {
     " #   # ",  //row=0
     " ##  # ",  //row=1
     " ### # ",  //row=2
     " # # # ",  //row=3
     " #  ## ",  //row=4
     " #  ## ",  //row=5
     " #   # "}; //row=6

 constexpr static char exclamation[ASCII_ROWS][ASCII_COLS]=
 {
     "  ##  ",  //row=0
     "  ##  ",  //row=1
     "  ##  ",  //row=2
     "  ##  ",  //row=3
     "  ##  ",  //row=4
     "      ",  //row=5
     "  ##  "}; //row=6


 constexpr static char space[ASCII_ROWS][ASCII_COLS]=
  {
     "     ",   //row=0
     "     ",   //row=1
     "     ",   //row=2
     "     ",   //row=3
     "     ",   //row=4
     "     ",   //row=5
     "     "};  //row=6

};
#endif // HANGMAN_H


