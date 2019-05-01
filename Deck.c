/*=============================================================================  
|   Source code:  Deck.c
|        Author:  Roland Aroche
|    Assignment:  Program #4 - Stud Poker
|  
|        Course:  COP 4338 (Advanced Programming)
|
|	I hereby certify that this collective work is my own
|	and none of it is the work of any other person or entity.
|	____________________________________ [Signature]
|  
|  +---------------------------------------------------------------------------- 
|  
|    Purpose:   Deck.c support a deck of cards.              
|  
|  *=========================================================================*/

#include "StudPoker.h"            /* Header File - Constant and Prototypes */


/*---------------------------- initializeDeck ----------------------------
    | Function void initializeDeck(Card deck[])
    |
    | Purpose:  Initialize the deck with values from zero to DECK_SIZE - 1
    |  
    | @param    deck[]:  Array which representing the deck of card. 
    |
    | @return   none
*---------------------------------------------------------------------------*/

void initializeDeck(Card deck[])
{
    int cardCounter = 0;
    Card card = {NO_CARD, ' '};     
    
    for(cardCounter = 0; cardCounter < DECK_SIZE; cardCounter++ )
    {
        card.cardRank = cardCounter;
        card.cardSuit = computeSuit(cardCounter);
        deck[cardCounter] = card;
    }  
}

/*---------------------------- displayDeck ----------------------------
    | Function  void displayDeck(Card deck[])
    |
    | Purpose:  Display the deck of cards
    |  
    | @param    deck[]:  Array holding the deck of card. 
    |
    | @return   none
*---------------------------------------------------------------------------*/

void displayDeck(Card deck[])
{
    int cardCounter = 0;
    
    for (cardCounter = 0; cardCounter < DECK_SIZE; cardCounter++ )
    {
        displayCard(deck[cardCounter]);  
        
        if( ((cardCounter + 1) % NUM_OF_RANKS ) == 0)
        {
            printf("\n");      // Blank space to divide each Suit
        }
    }
}

/*---------------------------- shuffleDeck ----------------------------
    | Function  void shuffleDeck (Card deck[])
    |
    | Purpose:  Shuffle the deck of cards using the Fisher-Yates algorithm
    | Source: 
https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle#The_modern_algorithm
      
    | @param    deck[]:  Array holding the deck of cards. 
    | @return   none
*---------------------------------------------------------------------------*/

void shuffleDeck (Card deck[])
{
    int cardCounter = 0;
    
    for(cardCounter = 0; cardCounter < DECK_SIZE; cardCounter ++ )
    {
       int randomCard = (rand() % (DECK_SIZE - 1)); 
       swapCards(&deck[cardCounter], &deck[randomCard]); 
    }
}

/*---------------------------- swapCards ----------------------------
    | Function  void swapCards (Card * card1, Card * card2) 
    |
    | Purpose:  Swap two cards in the deck
    |  
    | @param    Card * card1:  A pointer to the first card
    |           Card * card2:  A pointer to the second card
    |   
    | @return   none
*---------------------------------------------------------------------------*/

void swapCards (Card * card1, Card * card2) 
{ 
    Card temp = * card1; 
    * card1 = * card2; 
    * card2 = temp;      
} 