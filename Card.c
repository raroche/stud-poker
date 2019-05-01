/*=============================================================================  
|   Source code:  Card.c
|        Author:  Roland Aroche
|    Assignment:  Program #4 - Stud Poker
|  
|        Course:  COP 4338 (Advanced Programming)
|
|	I hereby certify that this collective work is my own
|	and none of it is the work of any other person or entity.
|	______________________________________ [Signature]
|  
|  +---------------------------------------------------------------------------- 
|  
|    Purpose:   Card.c support the use of Cards.  (struct Card)
|
|    How suits are ordered on the deck?
|       Clubs    = [0-12]
|       Diamonds = [13-25]
|       Hearts   = [27-38]
|       Spades   = [39-51]
|
|    Suits index  {CLUBS = 0, DIAMONDS = 1, HEARTS = 2, SPADES = 3}
|              
|  *=========================================================================*/

#include "StudPoker.h"            /* Header File - Constant and Prototypes */

/*---------------------------- displayCard ----------------------------
    | Function void displayCard(Card card)
    |
    | Purpose:  Display a card in the format [ Rank - Suit]
    |  
    | @param    int card:  a card number [ 0 - DECK_SIZE ]
    |
    | @return   none
*---------------------------------------------------------------------------*/

void displayCard(Card card)
{
    if(card.cardRank != NO_CARD)
    {
        printf("[ ");
        displayRank(card.cardRank);
        printf("%c ]", card.cardSuit); 
    }
}

/*---------------------------- displayRank ----------------------------
    | Function void displayRank(int card)
    |
    | Purpose:  Display a rank from a given card number
    |  
    | @param    int card:  a card number [ 0 - DECK_SIZE ] 
    |
    | @return   none
*---------------------------------------------------------------------------*/

void displayRank(int card)
{
    printf("%c", ranks[( card ) % NUM_OF_RANKS]);  
}

/*---------------------------- displaySuit ----------------------------
    | Function void displaySuit(int card)
    |
    | Purpose:  Display a suit from a given card number
    |  
    | @param    int card:  a card number [ 0 - DECK_SIZE ] 
    |
    | @return   none
*---------------------------------------------------------------------------*/

char computeSuit(int card)
{  
    
    if(NUM_OF_RANKS != 0)                    // Avoid division by zero
    {
        if((card / NUM_OF_RANKS) <= CLUBS )
        {
            return 'C';
        }
        else if((card / NUM_OF_RANKS) <= DIAMONDS )
        {
            return 'D';
        }
        else if((card / NUM_OF_RANKS) <= HEARTS )
        {
            return 'H';
        }
        else if((card / NUM_OF_RANKS) <= SPADES )
        {
            return 'S';
        }
        else
        {
          return NO_SUIT;   // return unknown suit  
        }
    }
}



