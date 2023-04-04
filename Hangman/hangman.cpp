#include "hangman.h"
#include <fstream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <iostream>
using namespace std;

Hangman::Hangman(string filename, string username) : player(username) //contains an object of another class
{
    loadWordList(filename);
    int level = selectGameLevel();
    player.setDifficultyLevel(level);
}

void Hangman::loadWordList(string filename) //Joseph
{
     string word;
     ifstream infile; //creating a file inputstream object used to connect to a text file
     infile.open (filename);//using the inputstream object to open file
     if (infile.is_open())//checking if the file was successfully opened
     {
         while(!infile.eof())//while not at the end of file eof()
         {
             getline(infile, word);//reading a line from the file and store it in the string variable, word
             wordVector.push_back(word);//inserting string word into the vector
         }//repeat until the end of file is reached

         infile.close();//closing the file after it has been processed
     }
     else // to show that there was a problem opening the file
     {
         cout<<"Unable to open file, "<<filename<<endl; //will notify the user that a problem has occurred
         cout<<"Hangman game will now terminate."<<endl;

         exit(-1);//terminate the program since no words could be loaded, making the game impossible
     }
}

int Hangman::selectGameLevel()//Asks the user to enter a number base on the level he/she desires
{
     int level = 0;
     do
     {
      cout<<"Choose a Level:\n"
            " 1.Easy\n"
            " 2.Medium\n"
            " 3.Difficult\n";
       cout << "=>";
            cin>>level;
            system("cls");
     }
     while (level < 1 || level > 3);//repeates the loop while the user's input is more than 3 or less than 1
     setDifficultyLevel(level);//setDifficultyLevel() is called and the value is passed to as its parameter
     return level;
}

int Hangman::generateRandomNumber()
{
    int level = getDifficultyLevel();
    srand(time(0)); //Initializing the generation of a random number

    if(level == 1)
        {
            int number_1 = rand();
            return (number_1 % 63) + 1;
        }
    else if (level == 2)
        {
            int number_2 = rand();
            number_2 %= 351;
            if(number_2<=63) //evaluates if the number is less than or equal to 65
            {
                number_2 = 63 + (number_2 % 287); //if it is then it will add to 63 to whatever is returned as a remainder from that number generated
            }
            return number_2;
        }
    else if(level == 3)
        {
            int number_3 = rand();
            number_3 %= 485;
            if(number_3<=351)//evaluates if the number is less than or equal to 351
            {
                number_3 = 351 + (number_3 % 113); //if it is then it will add to 351 to whatever is returned as a remainder from that number generated
            }
            return number_3;
        }
    return 1;
}

string Hangman::selectRandomWord(int random_number)
{
    return  wordVector[random_number];//word located at index location random_number of
}

void Hangman::resetAvailableLetters(){ //Francisco

    int count = 0;

    for(char i = 'A'; i <= 'Z' ;i++)
    {
       alphabetArray[count] = i ;
       count++;
    }
}

void Hangman::printMessage(string message, bool printTop, bool printBottom)
{
    /* Function to output message to the screen.
       By default, both second and third parameters are set to true.
       But whenever the function is called and there is no need to print dashes at the top and below the message, both second and third parameters are set to false.
     */

    if(printTop) // checking if printTop is true so as to output dashes
    {
      cout<< "+---------------------------------+" <<endl; //printing dashes to determine the width of the game interface
      cout<< "|";
    }
    else
    {
    cout<< "|";   //if not printing top dashes
    }
    bool fromFront = true; // variable to declare so as to add empty spaces to either side of the message to print

    for(int a = message.length(); a < 33; a++) //looping condition to ensure message printed is centralized
    {
        if(fromFront)
        {
            message = " " + message;  // printing an empty space before the message
        }
        else
        {
          message = message + " "; // printing an empty space after the message
        }
        fromFront = !fromFront; //reversing the value of bool variable to cause a space to be added to either side of the message, everytime the loop runs
    }
    cout<< message.c_str();	//casting string message and printing it

    if(printBottom)  //checking if function third parameter is true
    {
        cout<< "|" <<endl;
        cout<< "+---------------------------------+" <<endl; //printing dashes to complete the bottom part of the game interface
    }
    else
    {
        cout<< "|" <<endl;
    }

}

void Hangman::drawHangman(int guessCount)
{
/*  Function to draw a full hangman image base on every wrong guessed letter
    by the player. Parameter guess count is set to 0 by default, so nothing is printed out.
    But every wrong guess count prints out different character as defined based on the condition
    In this function, printTop and printBottom are not needed.
    Nothing is printed if no guess is made.
*/
    if(guessCount >= 1)    // counting the number of guesses
    {
        printMessage("|", false, false);  //if guessCount >= 1, print only message
    }
    else
    {
        printMessage("", false, false);
    }
    if(guessCount >= 2)
    {
        printMessage("|", false, false);
    }
    else
    {
        printMessage("", false, false);
    }
    if(guessCount >= 3)
    {
        printMessage("O", false, false);
    }
    else
    {
        printMessage("", false, false);
    }
    if(guessCount == 4)
    {
        printMessage("|", false, false);
    }
    if(guessCount == 5)
    {
        printMessage("/| ", false, false);
    }
    if(guessCount >= 6)
    {
        printMessage("/|\\", false, false);
    }
    else
    {
        printMessage("", false, false);
    }
    if(guessCount >= 7)
    {
        printMessage("|", false, false);
    }
    else
    {
        printMessage("", false, false);
    }
    if(guessCount == 8)
    {
        printMessage("/", false, false);
    }
    if(guessCount >= 9)
    {
        printMessage("/ \\", false, false);
    }
    else
        printMessage("", false, false);

    if(guessCount == 0)
        return;
}

void Hangman::setDifficultyLevel(unsigned diffLevel)
{
    difficultyLevel = diffLevel;

    if (difficultyLevel == 1)
        {
            setMaxAllowedAttempts(10);
        }

    else if (difficultyLevel==2)
        {
            setMaxAllowedAttempts(13);
        }

    else if (difficultyLevel==3)
        {
            setMaxAllowedAttempts(10);
        }
}

unsigned Hangman::getDifficultyLevel()
{
    return difficultyLevel;
}

void Hangman::setMaxAllowedAttempts(unsigned allowedAttempts)
{
    maxAllowedAttempts = allowedAttempts; //The function parameter is assigned to maxAllowedattempts
}

unsigned Hangman::getMaxAllowedAttempts()
{
    return maxAllowedAttempts;
}

unsigned Hangman::attemptsMadeSoFar(string wordToGuess, string guessesSoFar)
{
   int numOfErrors = 0;

    for (unsigned i = 0; i < guessesSoFar.length();i++)
    {
         guessesSoFar[ i ] = tolower(guessesSoFar[ i ]); //Converting user guess to lowercase inorder to compare it to wordToGuess which is in lowercase
        if (wordToGuess.find(guessesSoFar[i]) == string::npos)
        {
            numOfErrors++;
        }
    }
    return numOfErrors;
}

void Hangman::printAvailableLetters(string guessesSoFar)
{
    printMessage("Available Letters",true,false); //Printing word and top line but not bottom lines
    string letters = "";
    for (int i = 0; i < ALPHABET_SIZE;i++)
        {
            for (int j = 0, l = guessesSoFar.length(); j < l; j++)
                {
                    if (guessesSoFar[ j ] == alphabetArray[ i ])
                        {
                            alphabetArray[ i ] = ' '; //"removes" the letter guessed
                        }
                }
            letters += alphabetArray[ i ];
        }
    printMessage(letters,false,true); //prints remaining letters along with bottom lines and not top lines
}

void Hangman::printAsciiMessage(string message)
 {

    string temp;
    for (string::size_type i = 0; i < 7; i++) //loops through the rows of the character that w is at
    {
        for(string::size_type w = 0; w < message.size(); w++) // iterates through the letter of the message in order to assign the characters from the array in the current row
            {
                for (string::size_type j = 0; j < 1; j++) // loops through once to populate the string based on the current letter at w
                    {//the conditionals check what letter is at w and populates the temp string with all the characters of the letter array at the column from the current row
                        if(message[ w ] == 'G')
                            {
                                for (string::size_type l = 0; l < 7; l++)
                                        temp += Hangman::G[ i ] [ l ];
                                break;
                            }
                        if(message[ w ] == 'A')
                            {
                                for (string::size_type l = 0; l < 7; l++)
                                        temp += Hangman::A[ i ] [ l ];
                                break;
                            }
                        if(message[ w ] == 'M')
                            {
                                for (string::size_type l = 0; l < 7; l++)
                                        temp += Hangman::M[ i ] [ l ];
                                break;
                            }
                        if(message[ w ] == 'E')
                            {
                                for (string::size_type l = 0; l < 7; l++)
                                        temp += Hangman::E[ i ] [ l ];
                                break;
                            }
                        if(message[ w ] == 'O')
                            {
                                for (string::size_type l = 0; l < 7; l++)
                                        temp += Hangman::O[ i ] [ l ];
                                break;
                            }
                        if(message[ w ] == 'V')
                            {
                                for (string::size_type l = 0; l < 7; l++)
                                        temp += Hangman::V[ i ] [ l ];
                                break;
                            }
                        if(message[ w ] == 'R')
                            {
                                for (string::size_type l = 0; l < 7; l++)
                                    temp += Hangman::R[ i ] [ l ];
                                break;
                            }
                        if(message[ w ] == 'Y')
                            {
                                for (string::size_type l = 0; l < 7; l++)
                                        temp += Hangman::Y[i] [l];
                                break;
                            }
                        if(message[ w ] == 'U')
                            {
                                for (string::size_type l = 0; l < 7; l++)
                                        temp += Hangman::U[ i ] [ l ];
                                break;
                            }
                        if(message[ w ] == 'W')
                            {
                                for (string::size_type l = 0; l < 7; l++)
                                        temp += Hangman::W[ i ] [ l ];
                                break;
                            }
                        if(message[ w ] == 'N')
                            {
                                for (string::size_type l = 0; l < 7; l++)
                                        temp += Hangman::N[ i ] [ l ];
                                break;
                            }
                        if(message[ w ] == '!')
                            {
                                for (string::size_type l = 0; l < 7; l++)
                                        temp += Hangman::exclamation[ i ] [ l ];
                                break;
                            }
                        if(message[ w ] == ' ')
                            {
                                for (string::size_type l = 0; l < 7; l++)
                                    temp += Hangman::space[i][l];
                                break;
                            }
                    }
            }
        temp += " \n";
    }
    cout<< temp;
}

bool Hangman::checkWin(string wordToGuess, string guessesSoFar)
{
    bool won = true;
    string s;
    for (unsigned i = 0; i < wordToGuess.length(); i++)
    {
         wordToGuess[i] = toupper(wordToGuess[i]); //Converting word to guess to uppercase in order to be able to compare it with the alphabet array (Which is in uppercase)
    }
    for (unsigned i = 0; i < wordToGuess.length(); i++)
    {
        if (guessesSoFar.find(wordToGuess[i]) == string::npos)
        {
             won = false;
             s += "_ "; //If letter from wordToGuess not found in available letter, append an underscore

        }
         else
        {
            s += wordToGuess[i]; //Else append the letter
        }
    }
    printMessage(s, false, true); //Printing remaining Letters

    return won;
}

bool Hangman::processResults(string wordToGuess, int guessAttempts, bool hasWon)  //shawn
{
    player.setGuesses(guessAttempts);   //calling the function setGuess and passing guessAttempts
    cout <<player.generateStatistics();
    //using a if statement to check if haswon is true or false
      if(hasWon) //if true the ascii message will print out ‘YOU WON!’
      {
        printAsciiMessage("YOU WON!");
      }
      else
      {
        cout << "Word to guess was: " << wordToGuess << endl;
        printAsciiMessage("GAME OVER!");
      }
    //declaring the data type of play to save user's input
     string play;
    //asking the user to input a letter if they would like to play again
     cout<<"Do you want to play again? Y/N: ";
    //Takes users input as play
      cin>>play;
    // the if statements then start to check if  play is = lowercase ‘y’ or uppercase ‘Y’
      if (play == "Y" || play == "y")// also you can use '||' for 'or'
      {
        //if the user imputed ‘Y’ or ‘y’ the select Gamelevel is called to start the game again
        int difficultyLevel = selectGameLevel();
         //the set difficulty Level is called and difficulty level is being pass to it
        player.setDifficultyLevel(difficultyLevel);
        //if the user imputed lower case or upper y then true is being return
        return true;
      }
      return false;
}

void Hangman::startGame()
{
    string availableLetters;  //Keeps track of the set of all letters that the player has guessed so far.
    string aWordToGuess;		//The word that the user needs to guess.
    int numOfGuessedSoFar = 0 ;	//The total number of guesses made by the user so far, initialized to 0.
    bool youWin = false;			    //Whether the player has won.
    bool wantToPlayAgain = false;		//Whether the player wants to play again.
    char currentGuessedLetter;	//The current letter guess made by the user.
    srand(time(NULL));	//Called to prevent each random number generated from repeating itself
    do
    {   //do while loop to allow players to play again
        availableLetters = ""; // Initialized to an empty string
        aWordToGuess = ""; // Initialized to an empty string
        int num = generateRandomNumber();   //Storing return value of function
        aWordToGuess = selectRandomWord(num);  //Passing random number obtained
        resetAvailableLetters();    //Calling function to reset the array containing all the letters
        do
        {
            system("cls");      //Clears the screen
            printMessage("HANGMAN"); //Printing the message "HANGMAN with both top and bottom lines"
            drawHangman(numOfGuessedSoFar);  //Calling drawHangman to hold the variable that keeps track of all guesses made
            printAvailableLetters(availableLetters); //passing variable allLettersGuessedSoFar
            printMessage("Guess the word",false); //Printing message and bottom lines but not top lines
            //printMessage(aWordToGuess); //Output word to be guess *Testing purposes
            youWin = checkWin(aWordToGuess, availableLetters); //Assigning return value of checkWin and Passing variables into function checkWin
            if(youWin) //checking if the guess made was correct
            {
                break;     //No need for more guesses
            }
            cout <<"=>";  //Expecting another guess from the player
            cin >>currentGuessedLetter;    //Storing Player's guess in variable currentGuessedLetter
            currentGuessedLetter = toupper(currentGuessedLetter); //Converting every letter guessed to uppercase
            if(availableLetters.find(currentGuessedLetter) == string::npos)  //Checking if currentGuessedLetter is found within the string availableLetters
            {
               availableLetters += currentGuessedLetter;  // Appending currentGuessedLetter to the string of availableLetters
            }
            numOfGuessedSoFar = attemptsMadeSoFar(aWordToGuess, availableLetters);
         } while(numOfGuessedSoFar < getMaxAllowedAttempts()); //Condition for nested loop to ensure that the user doesn't input more than the max allowed attempts
         wantToPlayAgain = processResults(aWordToGuess, numOfGuessedSoFar, youWin);
    } while (wantToPlayAgain); //condition for outer do while loop to check if player want to play again
    system("pause");  //Pausing the game and wait for user's input
    getchar();             //To read data from the keyboard
}




