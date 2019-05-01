/*=============================================================================
|   Source code:  StudPokerMain.c
|        Author:  Roland Aroche
|  
|        Course:  COP 4338 (Advanced Programming)
|
|	I hereby certify that this collective work is my own
|	and none of it is the work of any other person or entity.
|	______________________________________ [Signature]
|  
|       Language:  C
|
|       How to Compile:
| 	gcc MainDeckOfCards.c Deck.c Card.c Hand.c  -o MainDeckOfCards.out
|
|       Using Makefile
|       $ make
| 	
|       How to Run:
|       ./MainDeckOfCards.out 5 7
|
|       The header file "DeckofCards.h" must be in the project directory
|  +---------------------------------------------------------------------------- 
|  
|  Description: This program simulates a deck of cards and deal a hand of cards              
|  
|  Input: Input is provided via command-line arguments
|         Input will specify the numbers of cards per hand  
|         and the numbers of players, in that order. 
|         Execution would look something like: ./MainDeckOFCard.out 7 5
|                
|      Two Integer are expected via command line arguments 
|      - First integer is the number of Cards [5], poker requires 5 cards
|      any other integer value entered different than 5 will be converted to 5
|      - Second Integer is the number of players [1-10]              
| 
|  Output:   The program will display the following information:
|
|                 - The original deck of cards (ordered)  
|                 - The shuffled deck of cards (random)
|                 - Each of the player’s hands of cards
|                 - Players' hand sorted in ascending order.
|                 - Players' hand with labels, type of hand and winners.
|                 - Poker hands test. 
|
|  Process:  The program's steps are as follows:  
|  
|              1.  Create the deck of cards
|              2.  Display the original deck (ordered) 
|              3.  Shuffle the deck
|              4.  Display the shuffled deck (random) 
|              5.  Deal card from the top of the deck
|              6.  Display players' hands. 
|              7.  Sort and Display players' hands
|              8.  Classify players' hands
|              9.  Compute winner(s)
|             10.  Display players' hands with hand type and winner labels
|             11.  Test method to classify hands, display test's hands
|                   
|   Required Features Not Included:  none
|   Known Bugs:  None; the program operates correctly. 
|
|*=========================================================================  */

#include "StudPoker.h"           /* Header File - Constant, Prototypes, etc. */

int main(int argc, char *argv[])
{
    int input[NUM_INPUTS] = {0};
    srand ( time(NULL) ); 
    
    if(validateInput(argc, &argv[0], input) == False)
    {
        invalidInputMsg ();
        return NO_ERROR;
    }
    
    const int NUM_OF_CARDS   = input[NUM_CARDS];
    const int NUM_OF_PLAYERS = input[NUM_PLAYERS];

    Card deck[DECK_SIZE] = {0};                  // Deck of cards
    initializeDeck(deck);
    
    printf("\nOriginal Ordered Deck: \n\n");
    displayDeck(deck);
    
    printf("\nRandom Shuffled Deck: \n\n");
    shuffleDeck(deck);
    displayDeck(deck);
    
    printf("\nPlayer Hands: \n\n");
    Card hands[NUM_OF_PLAYERS][NUM_OF_CARDS];       
    initializeHand(NUM_OF_PLAYERS, NUM_OF_CARDS, hands);
    deal(deck, NUM_OF_PLAYERS, NUM_OF_CARDS, hands);
    displayHands(NUM_OF_PLAYERS, NUM_OF_CARDS, hands);
    
    printf("\nPlayer Hands: Sorted \n\n");
    sortHands(NUM_OF_PLAYERS, NUM_OF_CARDS, hands);
    displayHands(NUM_OF_PLAYERS, NUM_OF_CARDS, hands);
    
    printf("\n Player Hands: winner(s)\n\n");
    displayWinnerHands(NUM_OF_PLAYERS, NUM_OF_CARDS, hands);
    
    printf("\nPoker Hands: test\n\n");
    displayTestHands();
    
    return NO_ERROR;
}

/*---------------------------- validateInput ----------------------------
    | Function enum Boolean validateInput(int argc, char *argv[], int input[])
    |
    | Purpose:  Validate command line input
    |  
    | @param    argc:    Number of input(s) entered via command line arguments.
    |           argv[]:  String array containing the input(s).
    |           input[]: Array where the input will be stored if it is valid.
    |
    | @return   True if input is valid, False otherwise.
*---------------------------------------------------------------------------*/

enum Boolean validateInput(int argc, char *argv[], int input[])
{
    if(argc == VALID_NUM_INPUT)
    {
        if(getInput(&argv[0], input) == False)
        {
            return False;
        }
        else
        {
            return True;
        }
    }
    else
    {
        return False;
    }   
}

/*---------------------------- getInput ----------------------------
    | Function: enum Boolean getInput(char *argv[], int input[])
    |
    | Purpose:  Store input(s) into array input[] if the input is valid.
    |           Validate input(s)
    |
    | @param
    |           argv[]:  String array containing the input
    |           input[]: Array where the input will be stored if it is valid.
    |
    | @return   True if input is valid, False otherwise.
*---------------------------------------------------------------------------*/

enum Boolean getInput(char *argv[], int input[])
{
    if(atoi(argv[NUM_PLAYERS]) && atoi(argv[NUM_CARDS]))
    {
        input[NUM_PLAYERS] = atoi(argv[NUM_PLAYERS]);
        input[NUM_CARDS] = atoi(argv[NUM_CARDS]);
        
        if( input[NUM_CARDS] != VALID_NUM_CARDS)
        {
            input[NUM_CARDS] = 5;
        }
            
        if(input[NUM_PLAYERS] >= MIN_NUM_PLAYERS 
                && input[NUM_PLAYERS] <= MAX_NUM_PLAYERS)       
            { 
                return True;  
            }
            else
            {
                return False;
            }
    }   
    else
    {
        return False;
    }  
}

/*---------------------------- invalidInputMsg ----------------------------
    | Function  void invalidInputMsg ()
    |
    | Purpose:  Display error message due to invalid input
    |  
    | @param    none
    | @return   none
*---------------------------------------------------------------------------*/

void invalidInputMsg ()
{
    printf("\nInvalid input entered via command line\n"
           "Execution Example: ./MainDeckOFCard.out 7 5 \n"
           "Two integer must be entered, the number of cards per hand and \n"
           "the number of hands(players), in that order.\n"
           "Number of card in poker is %d \n"
           "Number of players need to be between [%d-%d]\n\n"
            , VALID_NUM_CARDS, MIN_NUM_PLAYERS, MAX_NUM_PLAYERS);
}
