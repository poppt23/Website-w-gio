/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. poppt@purdue.edu
*  2. tyler31@purdue.edu
*  3. mmullens@purdue.edu
*
*  Lab #: 8
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Thursday, 3:30, Location of Lab: SC 231
*
*  Program Description:
*   User inputs a seed for a random number generator. The program will then
*   proceed to play a hand of blackjack as the player. Once the players hand
*   has either busted, or reached 16 or more, the player will stop playing.
*   The dealer's hand will then play through, and will play until the dealer
*   busts, reaches 16 or more, gets a higher score than the player but less than
*   21. Then the program will print wether or not the dealer won, lost, or
*   busted. The dealer will not play a hand if the player busts.
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double getValue();
void findCard(int card_num);
void findSuit(int card_num);
int playerIterations(double seed);
void dealerIterations(double seed, int playerScore);

int main()
{
  //Local declarations
  int seed; //INPUT SEED VALUE FROM THE USER
  int playerScore; //SCORE OF THE PLAYER'S HAND

  //Executables
  seed = getValue(); //ACCEPTS INPUT FOR SEED VALUE FROM USER
  srand(seed); //GENERATES RANDOM NUMBER FROM SEED
  playerScore = playerIterations(seed); //PROCESSES PLAYERS'S HAND AND RETURNS PLAYER'S SCORE
  dealerIterations(seed, playerScore); //PROCESSES DEALER'S HAND AND RETURNS RESULT OF GAME

  return(0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getValue
*
*  Function Return Type:
*   double
*  Parameters (list data type, name, and comment one per line):
*    1. None
*
*  Function Description:
*     Function prompts user for input of value, than accepts input via scan function.
***************************************************************************/

double getValue()
{
  //Local declarations
  double input; //INPUT VARIABLE FROM USER

  //Executables
  printf("Enter the seed value -> ");
  scanf("%lf", &input);

  return input;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: findCard
*
*  Function Return Type:
*   void
*  Parameters (list data type, name, and comment one per line):
*    1. int card_num
*
*  Function Description:
*     Function finds the card and prints.
***************************************************************************/

void findCard(int card_num)
{
  //Local declerations
  int number; //CARD NUMBER 1 THRU 52 EACH HAS CORRESPONDING VALUE

  //Executables
  number = card_num % 13 + 1; //FINDS THE CORRESPONDING CARD IN THE GIVEN SUIT

  switch(number)
  {
    case 13: printf("Queen");
              break;
    case 12: printf("Jack");
              break;
    case 11: printf("10");
              break;
    case 10: printf("9");
              break;
    case 9: printf("8");
              break;
    case 8: printf("7");
              break;
    case 7: printf("6");
              break;
    case 6: printf("5");
              break;
    case 5: printf("4");
              break;
    case 4: printf("3");
              break;
    case 3: printf("2");
              break;
    case 2: printf("Ace");
              break;
    default: printf("King");
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: findSuit
*
*  Function Return Type:
*   double
*  Parameters (list data type, name, and comment one per line):
*    1. int card_num
*
*  Function Description:
*     Function finds the suit of the card and prints.
***************************************************************************/

void findSuit(int card_num)
{
  //Executables
  if (card_num >= 1 && card_num <= 13) //FINDS SUIT OF CARD BASED ON SEED GENERATED VALUE
  {
    findCard(card_num);
    printf(" of Clubs\n");
  }
  else if (card_num >= 14 && card_num <= 26)
  {
    findCard(card_num);
    printf(" of Diamonds\n");
  }
  else if (card_num >= 27 && card_num <= 39)
  {
    findCard(card_num);
    printf(" of Hearts\n");
  }
  else if (card_num >= 40 && card_num <= 52)
  {
    findCard(card_num);
    printf(" of Spades\n");
  }
  return;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: currentScore
*
*  Function Return Type:
*   int
*  Parameters (list data type, name, and comment one per line):
*    1. int card_num
*
*  Function Description:
*     Function finds the value of the card generated through the random number generator.
***************************************************************************/

int CurrentScore(int card_num)
{
  //Local declerations
  int number; //CARD NUMBER 1 THRU 52 EACH HAS CORRESPONDING VALUE
  int score; //RETURN VALUE OF THE VALUE OF THE CARD

  //Executables
  number = card_num % 13 + 1; //FINDS THE CORRESPONDING CARD IN THE GIVEN GENERATED NUMBER

  if (number == 13) //FINDS VALUE OF EACH CARD FROM GENERATED NUMBER
  {
    score = 10;
  }
  else if (number == 12)
  {
    score = 10;
  }
  else if (number == 11)
  {
    score = 10;
  }
  else if (number == 10)
  {
    score = 9;
  }
  else if (number == 9)
  {
    score = 8;
  }
  else if (number == 8)
  {
    score = 7;
  }
  else if (number == 7)
  {
    score = 6;
  }
  else if (number == 6)
  {
    score = 5;
  }
  else if (number == 5)
  {
    score = 4;
  }
  else if (number == 4)
  {
    score = 3;
  }
  else if (number == 3)
  {
    score = 2;
  }
  else if (number == 2)
  {
    score = 11;
  }
  else
  {
    score = 10;
  }

  return(score);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: playerIterations
*
*  Function Return Type:
*   int
*  Parameters (list data type, name, and comment one per line):
*    1. double seed
*
*  Function Description:
*     Function accepts seed value and players through the players hand until
*   reaches an acceptable hand or busts.
***************************************************************************/

int playerIterations(double seed)
{
  //Local Declerations
  int cardnum; //NUMBER CARD THE PLAYER IS ON
  int card; //VALUE OF THE CARD FROM RANDOM NUMBER GENERATOR
  int currentscore; //SCORE OF THE PLAYER'S HAND
  int aceCounter; //COUNTER FOR NUMBER OF ACES PLAYER IS DEALT

  //Executables
  cardnum = 1; //INITIAL VALUE OF THE CARD PLAYER IS BEING DEALT
  currentscore = 0; //INITIAL VALUE OF SCORE OF PLAYER'S HAND
  aceCounter = 0; //INITIAL VALUE FOR NUMBER OF ACES DEALT
  printf("\n");
  do //LOOP FOR ITERATING PLAYER'S HAND UNTIL CONTROL IS MET
  {
    card = (rand() % 52) + 1; //FINDS VALUE OF CARD FROM NUMBER GENERATOR
    printf("Card #%d: ", cardnum); //PRINTS NUMBER CARD BEING DEALT
    findSuit(card); //FUNCTION CALL TO FIND THE CARD DEALT
    currentscore += CurrentScore(card); //UPDATES SCORE OF PLAYER'S HAND

    if (card == 1 || card == 14 || card == 27 || card == 40) //UPDATES ACE COUNTER
    {
      aceCounter += 1;
    }
    if (aceCounter > 0 && currentscore > 21) //SUBTRACTS IF ACE IS DEALT AND PLAYER BUSTS
    {
      currentscore -= 10;
      aceCounter -= 1;
    }

    cardnum += 1;

  } while (currentscore < 16);

  printf("Player's Score: %d\n", currentscore);
  if (currentscore > 21)
  {
    printf("\nDealer wins!\n");
  }
  return (currentscore);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: dealerIterations
*
*  Function Return Type:
*   void
*  Parameters (list data type, name, and comment one per line):
*    1. double seed
*    2. int playerScore
*
*  Function Description:
*     Function accepts seed value and players through the players hand until
*   beats player, or loses to player. Won't play is player busts.
***************************************************************************/

void dealerIterations(double seed, int playerScore)
{
  //Local Declerations
  int cardnum; //NUMBER CARD THE DEALER IS ON
  int card; //VALUE OF THE CARD FROM RANDOM NUMBER GENERATOR
  int currentscore; //SCORE OF THE DEALER'S HAND
  int aceCounter; //COUNTER FOR NUMBER OF ACES PLAYER IS DEALT

  //Executables
  cardnum = 1; //INITIAL VALUE OF THE CARD DEALER IS BEING DEALT
  currentscore = 0; //INITIAL VALUE OF SCORE OF DEALER'S HAND
  aceCounter = 0; //INITIAL VALUE FOR NUMBER OF ACES DEALT

  if(playerScore <= 21) //IF PLAYER BUSTS DEALER WON'T PLAY
  {
    printf("\n");
    do  //LOOP FOR ITERATING DEALER'S HAND UNTIL CONTROL IS MET
    {
      card = (rand() % 52) + 1; //FINDS VALUE OF CARD FROM NUMBER GENERATOR
      printf("Card #%d: ", cardnum); //PRINTS NUMBER CARD BEING DEALT
      findSuit(card); //FUNCTION CALL TO FIND THE CARD DEALT
      currentscore += CurrentScore(card); //UPDATES SCORE OF PLAYER'S HAND

      if (card == 1 || card == 14 || card == 27 || card == 40) //UPDATES ACE COUNTER
      {
        aceCounter += 1;
      }
      if (aceCounter > 0 && currentscore > 21) //SUBTRACTS IF ACE IS DEALT AND PLAYER BUSTS
      {
        currentscore -= 10;
        aceCounter -= 1;
      }

      cardnum += 1;

    } while (currentscore < playerScore && currentscore < 16);

    printf("Dealers's Score: %d\n", currentscore); //PRINTS DEALER SCORE

    if (currentscore == 21) //CONDITION FOR WHICH PLAYER WINS GAME
    {
      printf("\nDealer wins!\n");
    }
    else if (currentscore == playerScore)
    {
      printf("\nDealer wins!\n");
    }
    else if(currentscore > playerScore && currentscore < 21)
    {
      printf("\nDealer wins!\n");
    }
    else if (currentscore > 21)
    {
      printf("\nDealer busts.\n");
    }
    else if((currentscore < playerScore) && currentscore > 16)
    {
      printf("\nDealer loses!\n");
    }
  }
  return;
}
