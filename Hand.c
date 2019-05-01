/*=============================================================================  
|   Source code:  Hand.c
|        Author:  Roland Aroche
|  
|        Course:  COP 4338 (Advanced Programming)
|
|     I hereby certify that this collective work is my own
|	and none of it is the work of any other person or entity.
|	______________________________________ [Signature]
|  
| --------------------------------------------------------------------------- 
|  
|   Purpose:   Hand.c support a hand and deal operation.              
|        
|  *=========================================================================*/

#include "StudPoker.h"            /* Header File - Constant and Prototypes */


/*----------------------------   deal   ----------------------------
    | Function  void deal(Card [], int , int  , Card [][])
    |
    | Purpose:  Deal cards to each player.
    |  
    | @param    deck[]:  Array holding the deck of cards.
    |           int NumOfPlayers: Number of Players
    |           int NumOfCards: Number of cards per player
    |           Card hand[NumOfPlayers][NumOfCards]: A hand
    |
    | @return   none
*---------------------------------------------------------------------------*/

void deal(Card deck[DECK_SIZE], int NumOfPlayers, int  NumOfCards, 
                Card hand[NumOfPlayers][NumOfCards])
{  
    int playerIndex = 0;
    int cardIndex   = 0;
    int cardCounter = 0;
    
    for(cardIndex = 0; cardIndex < NumOfCards; cardIndex++ )
    {  
        for (playerIndex= 0; playerIndex < NumOfPlayers; playerIndex++)
        { 
           hand[playerIndex][cardIndex] = deck[cardCounter];  
           deck[cardCounter].cardRank = NO_CARD;  
           cardCounter++;
        }
    }     
}

/*----------------------------   initializeHand   ----------------------------
    | Function void initializeHand(int, int, Card [][])
    |
    | Purpose:  Initialize empty hand, all card are set to NO_CARD constant
    |  
    | @param    
    |           int NumOfPlayers: Number of Players
    |           int NumOfCards: Number of cards per player
    |           int hand[NumOfPlayers][NumOfCards]: A hand
    |
    | @return   none
*---------------------------------------------------------------------------*/

void initializeHand(int NumOfPlayers, int NumOfCards, 
                        Card hand[NumOfPlayers][NumOfCards])
{
    int playerIndex = 0;
    int cardIndex   = 0;
    
    // Initialize Hand Array
    for(playerIndex = 0; playerIndex < NumOfPlayers; playerIndex++ )
    {
        for (cardIndex = 0; cardIndex < NumOfCards; cardIndex++)
        {
            hand[playerIndex][cardIndex].cardRank =  NO_CARD;
            hand[playerIndex][cardIndex].cardSuit =  NO_SUIT;
        }
    }  
}

/*----------------------------   displayHand   ----------------------------
    | Function void displayHand(int, int, Card [][])
    |
    | Purpose:  Display players' hands
    |  
    | @param    
    |           int NumOfPlayers: Number of Players
    |           int NumOfCards: Number of cards per player
    |           Card hand[NumOfPlayers][NumOfCards]: Array holding the hands
    |
    | @return   none
*---------------------------------------------------------------------------*/

void displayHands(int NumOfPlayers, int NumOfCards, 
                        Card hands[NumOfPlayers][NumOfCards])
{
    int playerIndex = 0;
    int cardIndex = 0;
    
    for(playerIndex = 0; playerIndex < NumOfPlayers; playerIndex++ )
    {
        printf("[ Player %d ] - ", playerIndex + 1);
        
        for (cardIndex = 0; cardIndex < NumOfCards; cardIndex++)
        {
            displayCard(hands[playerIndex][cardIndex]);   
        }
        puts("");
    }
}

/*----------------------------   sortHands   ----------------------------
    | Function void displayHand( int, int, Card [][])
    |
    | Purpose:  Sort players' hands
    |  
    | @param    
    |           int NumOfPlayers: Number of Players
    |           int NumOfCards: Number of cards per player
    |           Card hand[NumOfPlayers][NumOfCards]: Array holding the hands
    |
    | @return   none
*---------------------------------------------------------------------------*/

void sortHands(int numOfPlayers, int numOfCards, 
                    Card hands[numOfPlayers][numOfCards]) 
{ 
    int playerIndex = 0;
    
    for(playerIndex = 0; playerIndex < numOfPlayers; playerIndex++)
    {
        sortHand(hands[playerIndex]);
    }
} 

/*----------------------------   sortHand   ----------------------------
    | Function void displayHand( Card [])
    |
    | Purpose:  Sort One hand
    |  
    |       Sorting Algorithm used: Insertion Sort
    |       Reference : https://en.wikipedia.org/wiki/Insertion_sort 
    |       Complexity: Worst-case scenario is О(n*n) comparisons and swaps
    |
    | @param    
    |         Card hand[]: Array holding One hands
    |
    | @return   none
*---------------------------------------------------------------------------*/

void sortHand(Card hand[VALID_NUM_CARDS]) 
{
    int holePosition = 0;
    Card cardToInsert = {-1, ' '};
    int cardIndex = 0;
        
    //Insertion Sort Algorithm 
    for (cardIndex = 1; cardIndex < VALID_NUM_CARDS; cardIndex++)
    {
        cardToInsert = hand[cardIndex];
        holePosition = cardIndex;
      	
        while(holePosition > 0 && 
             ((hand[holePosition - 1].cardRank % NUM_OF_RANKS) 
               > (cardToInsert.cardRank) % NUM_OF_RANKS))
        {
            hand[holePosition] = hand[holePosition - 1];
                
            holePosition = holePosition - 1;
        }  
        hand[holePosition] = cardToInsert;  
    }  
}

/*----------------------------   displayTestHands   ----------------------------
    | Function void displayTestHands( )
    |
    | Purpose:  Display test hands. 
    |           One test is perform for each type of Poker's hand.
    |  
    |       Ternary operator (?:) used to make code mor compact and readable. 
    |       Reference: https://en.wikipedia.org/wiki/%3F:
    |
    | @param:   none
    | @return   none
*---------------------------------------------------------------------------*/

void displayTestHands()
{  
   // High Card Test
   displayHand(highCard);
   puts(isHighCard(highCard) ? " - High Card" : " - Not High Card");

   // One Pairs Test
   displayHand(onePairs);
   puts(isOnePair(onePairs) ? " - One Pairs" : " - Not One Pairs");
   
   // Two Pairs Test
   displayHand(twoPairs);
   puts(isTwoPair(twoPairs) ? " - Two Pairs" : " - Not Two Pairs");

  // Three of a Kind Test
   displayHand(threeOfAKind);
   puts(isThreeOfAKind(threeOfAKind) ? " - Three of a Kind" : 
                                                " - Not Three of a Kind");
   // Straight Test
   displayHand(straight);
   puts(isStraight(straight) ? " - Straight" : " - Not Straight");
   
   // Flush Test
   displayHand(flush);
   puts(isFlush(flush) ? " - Flush" : " - Not Flush");
   
   // Full House Test
   displayHand(fullHouse);
   puts(isFullHouse(fullHouse) ? " - Full House" : " - Not Full House");

   // Four of a Kind  Test
   displayHand(fourOfAKind);
   puts(isFourOfAKind(fourOfAKind) ? " - Four of a Kind " : 
                                                  " - Not Four of a Kind ");
   // Straight Flush Test
   displayHand(straightFlush);
   puts(isStraightFlush(straightFlush) ? " - Straight Flush" : 
                                                   " - Not Straight Flush");
}

/*----------------------------   displayHand   ----------------------------
    | Function void displayHand( Card [])
    |
    | Purpose:  Display one hand
    |
    | @param    Card hand[]: Array holding One hands
    |
    | @return   none
*---------------------------------------------------------------------------*/

void displayHand(Card hand[VALID_NUM_CARDS])
{
    int card = 0;
    
    printf("%s", "Hand:");
    
    for (card = 0; card < VALID_NUM_CARDS; card++)
        {
            displayCard(hand[card]);   
        }
}

/*----------------------------   isStraightFlush   ----------------------------
    | Function void isStraightFlush( Card [])
    |
    | Purpose:   Check if hand is "Straight Flush"
    | Reference: https://www.pokerstars.com/poker/games/rules/hand-rankings/
    |
    | @param    Card hand[]: Array holding One hands
    |
    | @return   True is hand is "Straight Flush", False otherwise.
*---------------------------------------------------------------------------*/

enum Boolean isStraightFlush(Card hand[VALID_NUM_CARDS])
{
    const int VALID_S_FLUSH = 4;     //Valid Number of successful comparisons
    int       flushCounter  = 0;
    int       handIndex     = 0;
    
    sortHand(hand);   // Hand must be sorted for this function to work properly.
    
    for(handIndex = 0; handIndex < VALID_NUM_CARDS - 1; handIndex++)
    {
        if(hand[handIndex].cardSuit == hand[handIndex + 1].cardSuit &&
           hand[handIndex].cardRank % NUM_OF_RANKS == 
                (hand[handIndex + 1].cardRank % NUM_OF_RANKS) - 1)
        {
            flushCounter++;  
        }
        else
        {
            return False;   
        }
    }
    
    if(flushCounter == VALID_S_FLUSH)
    {
        return True;
    }
    else
    {  
        return False;   
    }
}

/*----------------------------   isFourOfAKind   ----------------------------
    | Function void isFourOfAKind( Card [])
    |
    | Purpose:   Check if hand is "Four of a Kind"
    | Reference: https://www.pokerstars.com/poker/games/rules/hand-rankings/
    |
    | @param    Card hand[]: Array holding One hands
    |
    | @return   True is hand is "Four of a Kind", False otherwise.
*---------------------------------------------------------------------------*/

enum Boolean isFourOfAKind(Card hand[VALID_NUM_CARDS])
{
    enum Boolean result1 = False;
    enum Boolean result2 = False;
    
    sortHand(hand); // Hand must be sorted for this function to work properly.
    
    if(hand[0].cardRank % NUM_OF_RANKS == hand[1].cardRank % NUM_OF_RANKS
       && hand[1].cardRank % NUM_OF_RANKS == hand[2].cardRank % NUM_OF_RANKS
       && hand[2].cardRank % NUM_OF_RANKS == hand[3].cardRank % NUM_OF_RANKS )
    {
        return True;
    }

    if(hand[1].cardRank % NUM_OF_RANKS == hand[2].cardRank % NUM_OF_RANKS
      && hand[2].cardRank % NUM_OF_RANKS == hand[3].cardRank % NUM_OF_RANKS 
      && hand[3].cardRank % NUM_OF_RANKS == hand[4].cardRank % NUM_OF_RANKS)
    {
        return True;
    }
    
    return False; 
}

/*----------------------------   isFullHouse   ----------------------------
    | Function void isFullHouse( Card [])
    |
    | Purpose:   Check if hand is "Full House"
    | Reference: https://www.pokerstars.com/poker/games/rules/hand-rankings/
    |
    | @param    Card hand[]: Array holding One hands
    |
    | @return   True is hand is "Full House", False otherwise.
*---------------------------------------------------------------------------*/

enum Boolean isFullHouse(Card hand[VALID_NUM_CARDS])
{
    enum Boolean result1 = False;
    enum Boolean result2 = False;
    
    sortHand(hand); // Hand must be sorted for this function to work properly.
    
    if(hand[0].cardRank % NUM_OF_RANKS == hand[1].cardRank % NUM_OF_RANKS
       && hand[2].cardRank % NUM_OF_RANKS == hand[3].cardRank % NUM_OF_RANKS 
       && hand[3].cardRank % NUM_OF_RANKS == hand[4].cardRank % NUM_OF_RANKS
      )
    {
        return True;
    }

    if(hand[0].cardRank % NUM_OF_RANKS == hand[1].cardRank % NUM_OF_RANKS
      && hand[1].cardRank % NUM_OF_RANKS == hand[2].cardRank % NUM_OF_RANKS
      && hand[3].cardRank % NUM_OF_RANKS == hand[4].cardRank % NUM_OF_RANKS)
    {
         return True;
    }

    return False;
}

/*----------------------------   isFlush   ----------------------------
    | Function void isFlush( Card [])
    |
    | Purpose:   Check if hand is "Flush"
    | Reference: https://www.pokerstars.com/poker/games/rules/hand-rankings/
    |
    | @param    Card hand[]: Array holding One hands
    |
    | @return   True is hand is "Flush", False otherwise.
*---------------------------------------------------------------------------*/

enum Boolean isFlush(Card hand[VALID_NUM_CARDS])
{
    int handIndex = 0;
    
    sortHand(hand); // Hand must be sorted for this function to work properly.
    
    for(handIndex = 0; handIndex < VALID_NUM_CARDS - 1; handIndex++)
    {
        if(hand[handIndex].cardSuit != hand[handIndex + 1].cardSuit)  
        {
            return False; 
        }
    }
    return True;

}

/*----------------------------   isStraight   ----------------------------
    | Function void isStraight( Card [])
    |
    | Purpose:   Check if hand is "Straight"
    | Reference: https://www.pokerstars.com/poker/games/rules/hand-rankings/
    |
    | @param    Card hand[]: Array holding One hands
    |
    | @return   True is hand is "Straight", False otherwise.
*---------------------------------------------------------------------------*/

enum Boolean isStraight(Card hand[VALID_NUM_CARDS])
{
    int handIndex = 0;
    
    sortHand(hand); // Hand must be sorted for this function to work properly.
    
    // Special Case:  10  J  Q  K  A
    if(hand[0].cardRank % NUM_OF_RANKS == 0  && 
       hand[1].cardRank % NUM_OF_RANKS == 9  && 
       hand[2].cardRank % NUM_OF_RANKS == 10 && 
       hand[3].cardRank % NUM_OF_RANKS == 11 && 
       hand[4].cardRank % NUM_OF_RANKS == 12)
    {
        return True;
    }
         
    for ( handIndex = 0; handIndex < VALID_NUM_CARDS - 1; handIndex++)
    {
        if ( hand[handIndex].cardRank % NUM_OF_RANKS != 
                (hand[handIndex + 1].cardRank % NUM_OF_RANKS) - 1  )
        {
            return(False); 
        }

    }

    return(True);  
}

/*----------------------------   isThreeOfAKind   ----------------------------
    | Function void isThreeOfAKind( Card [])
    |
    | Purpose:   Check if hand is "Three of a Kind"
    | Reference: https://www.pokerstars.com/poker/games/rules/hand-rankings/
    |
    | @param    Card hand[]: Array holding One hands
    |
    | @return   True is hand is "Three of a Kind", False otherwise.
*---------------------------------------------------------------------------*/

enum Boolean isThreeOfAKind(Card hand[VALID_NUM_CARDS])
{  
    sortHand(hand); // Hand must be sorted for this function to work properly.
    
    // Case: a a a b c
    
    if(hand[0].cardRank % NUM_OF_RANKS == hand[2].cardRank % NUM_OF_RANKS &&
       hand[2].cardRank % NUM_OF_RANKS != hand[3].cardRank % NUM_OF_RANKS &&
       hand[3].cardRank % NUM_OF_RANKS != hand[4].cardRank % NUM_OF_RANKS)
    {
        return True;
    }
	
    // Case: b a a a c
    
    if(hand[1].cardRank % NUM_OF_RANKS == hand[3].cardRank % NUM_OF_RANKS &&
       hand[0].cardRank % NUM_OF_RANKS != hand[1].cardRank % NUM_OF_RANKS &&
       hand[3].cardRank % NUM_OF_RANKS != hand[4].cardRank% NUM_OF_RANKS )
    {
        return True;
    }
    
    // Case: b c a a a
    
    if(hand[2].cardRank % NUM_OF_RANKS == hand[4].cardRank % NUM_OF_RANKS &&
       hand[0].cardRank % NUM_OF_RANKS != hand[1].cardRank % NUM_OF_RANKS &&
       hand[1].cardRank % NUM_OF_RANKS != hand[2].cardRank % NUM_OF_RANKS)
    {
        return True;
    }

    return False;
    
}

/*----------------------------   isTwoPair   ----------------------------
    | Function void isTwoPair( Card [])
    |
    | Purpose:   Check if hand is "Two Pair"
    | Reference: https://www.pokerstars.com/poker/games/rules/hand-rankings/
    |
    | @param    Card hand[]: Array holding One hands
    |
    | @return   True is hand is "Two Pair", False otherwise.
*---------------------------------------------------------------------------*/

enum Boolean isTwoPair(Card hand[VALID_NUM_CARDS])
{ 
    sortHand(hand); // Hand must be sorted for this function to work properly.
    
    // Case: a a  b b c
    
    if(hand[0].cardRank % NUM_OF_RANKS == hand[1].cardRank % NUM_OF_RANKS &&
       hand[2].cardRank % NUM_OF_RANKS == hand[3].cardRank % NUM_OF_RANKS &&
       hand[0].cardRank % NUM_OF_RANKS != hand[2].cardRank % NUM_OF_RANKS &&
       hand[3].cardRank % NUM_OF_RANKS != hand[4].cardRank % NUM_OF_RANKS)
    {
        return True;
    }
    
     // Case: c a a b b
    
    if(hand[1].cardRank % NUM_OF_RANKS == hand[2].cardRank % NUM_OF_RANKS &&
       hand[3].cardRank % NUM_OF_RANKS == hand[4].cardRank % NUM_OF_RANKS &&
       hand[0].cardRank % NUM_OF_RANKS != hand[1].cardRank % NUM_OF_RANKS &&
       hand[2].cardRank % NUM_OF_RANKS != hand[3].cardRank % NUM_OF_RANKS)
    {
        return True;
    }
    
    // Case: a a c b b
    
    if(hand[0].cardRank % NUM_OF_RANKS == hand[1].cardRank % NUM_OF_RANKS &&
       hand[3].cardRank % NUM_OF_RANKS == hand[4].cardRank % NUM_OF_RANKS &&
       hand[1].cardRank % NUM_OF_RANKS != hand[2].cardRank % NUM_OF_RANKS &&
       hand[2].cardRank % NUM_OF_RANKS != hand[3].cardRank % NUM_OF_RANKS)
    {
        return True;
    }

    return False;  
}

/*----------------------------   isOnePair   ----------------------------
    | Function void isOnePair( Card [])
    |
    | Purpose:   Check if hand is "One Pair"
    | Reference: https://www.pokerstars.com/poker/games/rules/hand-rankings/
    |
    | @param    Card hand[]: Array holding One hands
    |
    | @return   True is hand is "One Pair", False otherwise.
*---------------------------------------------------------------------------*/

enum Boolean isOnePair(Card hand[VALID_NUM_CARDS])
{   
    sortHand(hand); // Hand must be sorted for this function to work properly.
    
    // Case: a a  b c d
    if(hand[0].cardRank % NUM_OF_RANKS == hand[1].cardRank % NUM_OF_RANKS &&
       hand[1].cardRank % NUM_OF_RANKS != hand[2].cardRank % NUM_OF_RANKS &&
       hand[2].cardRank % NUM_OF_RANKS != hand[3].cardRank % NUM_OF_RANKS &&
       hand[3].cardRank % NUM_OF_RANKS != hand[4].cardRank % NUM_OF_RANKS)
    {
        return True;
    }
    
    // Case: b a a c d
    if(hand[1].cardRank % NUM_OF_RANKS == hand[2].cardRank % NUM_OF_RANKS &&
       hand[1].cardRank % NUM_OF_RANKS != hand[0].cardRank % NUM_OF_RANKS &&
       hand[1].cardRank % NUM_OF_RANKS != hand[3].cardRank % NUM_OF_RANKS &&
       hand[0].cardRank % NUM_OF_RANKS != hand[3].cardRank % NUM_OF_RANKS &&
       hand[3].cardRank % NUM_OF_RANKS != hand[4].cardRank % NUM_OF_RANKS)
    {
        return True;
    }
    
    // Case: b c a a d
    if(hand[2].cardRank % NUM_OF_RANKS == hand[3].cardRank % NUM_OF_RANKS &&
       hand[2].cardRank % NUM_OF_RANKS != hand[1].cardRank % NUM_OF_RANKS &&
       hand[2].cardRank % NUM_OF_RANKS != hand[4].cardRank % NUM_OF_RANKS &&
       hand[0].cardRank % NUM_OF_RANKS != hand[1].cardRank % NUM_OF_RANKS &&
       hand[1].cardRank % NUM_OF_RANKS != hand[4].cardRank % NUM_OF_RANKS)
    {
        return True;
    }
    
    // Case: b c d a a
    if(hand[3].cardRank % NUM_OF_RANKS == hand[4].cardRank % NUM_OF_RANKS &&
       hand[0].cardRank % NUM_OF_RANKS != hand[1].cardRank % NUM_OF_RANKS &&
       hand[1].cardRank % NUM_OF_RANKS != hand[2].cardRank % NUM_OF_RANKS &&
       hand[2].cardRank % NUM_OF_RANKS != hand[3].cardRank % NUM_OF_RANKS)
    {
        return True;
    }

    return False;  
}

/*----------------------------   isHighCard   ----------------------------
    | Function void isHighCard( Card [])
    |
    | Purpose:   Check if hand is "High Card"
    | Reference: https://www.pokerstars.com/poker/games/rules/hand-rankings/
    |
    | @param    Card hand[]: Array holding One hands
    |
    | @return   True is hand is "High Card", False otherwise.
*---------------------------------------------------------------------------*/

enum Boolean isHighCard(Card hand[VALID_NUM_CARDS])
{
    sortHand(hand); // Hand must be sorted for this function to work properly.
    
    // Case a b c d e 
    
    if(hand[0].cardRank % NUM_OF_RANKS != hand[1].cardRank % NUM_OF_RANKS &&
       hand[1].cardRank % NUM_OF_RANKS != hand[2].cardRank % NUM_OF_RANKS &&
       hand[2].cardRank % NUM_OF_RANKS != hand[3].cardRank % NUM_OF_RANKS &&
       hand[3].cardRank % NUM_OF_RANKS != hand[4].cardRank % NUM_OF_RANKS)
    {
        return True;
    }

    return False; 
}

/*----------------------------   displayWinnerHands   -------------------------
    | Function void displayWinnerHands( int, int, Card [][])
    |
    | Purpose:  Display hands with Labels, Hand type and winner(s) label
    |  
    | @param    
    |           int NumOfPlayers: Number of Players
    |           int NumOfCards: Number of cards per player
    |           Card hand[NumOfPlayers][NumOfCards]: Array holding the hands
    |
    | @return   none
*---------------------------------------------------------------------------*/

void displayWinnerHands(int numOfPlayers, int numOfCards, 
                            Card hands[numOfPlayers][numOfCards])
{
    int playerIndex = 0;
    int cardIndex = 0;
    int playersHandType[numOfPlayers];
    int winners[numOfPlayers];
    enum HandsTypes handType = 0;
    
    initializeWinners( numOfPlayers, winners);     // initialize winners array
    
    classifyhands(numOfPlayers, numOfCards, hands, playersHandType);
    computeWinners(numOfPlayers, playersHandType, winners);
    
    for(playerIndex = 0; playerIndex < numOfPlayers; playerIndex++ )
    {
        printf("[ Player %d ] - ", playerIndex + 1);
        
        for (cardIndex = 0; cardIndex < numOfCards; cardIndex++)
        {
            displayCard(hands[playerIndex][cardIndex]);   
        }

        printf(" - %-15s", handTypes[playersHandType[playerIndex]]);
        
        if(isAWinner(playerIndex, numOfPlayers, winners) == True)
        {
            printf(" <- Winner");
        }
        puts("");
    }   
}

/*----------------------------   identifyHand   ------------------------
    | Function void identifyHand( Card hand[][])
    |
    | Purpose:  Identify the hand type for one hand
    |  
    | @param    Card hand[]: Array holding One hands
    | @return   The type of the hand
*---------------------------------------------------------------------------*/

enum HandsTypes identifyHand(Card hand[VALID_NUM_CARDS])
{   
    if(isStraightFlush(hand))           { return STRAIGHT_FLUSH;  } 
    else if(isFourOfAKind(hand))        { return FOUR_OF_A_KIND;  }
    else if(isFullHouse(hand))          { return FULL_HOUSE;      }
    else if(isFlush(hand))              { return FLUSH;           }
    else if(isStraight(hand))           { return STRAIGHT;        }
    else if(isThreeOfAKind(hand))       { return THREE_OF_A_KIND; }
    else if(isTwoPair(hand))            { return TWO_PAIR;       }
    else if(isOnePair(hand))            { return ONE_PAIR;        }
    else if(isHighCard(hand))           { return HIGH_CARD;       }
    else                                { return -1;              }
}

/*----------------------------   classifyhands   -------------------------
    | Function void classifyhands( int, int, Card [][], int [])
    |
    | Purpose:  Clasify each hand and store it's type on playersHandType[]
    |           Loop hands classifying them into the possible types
    |           Integer representation of the hand types will be 
    |           stored in playersHandType[]
    |  
    | @param    
    |         int NumOfPlayers:      Number of Players
    |         int NumOfCards:        Number of cards per player
    |         Card hand[][]:         Array holding the hands
    |         int playersHandType[]: Array that will hold the hand's type
    |
    | @return  none
*---------------------------------------------------------------------------*/

void classifyhands (int numOfPlayers, int numOfCards, 
                   Card hands[numOfPlayers][numOfCards], 
                   int playersHandType[numOfPlayers])
{
    int playerIndex = 0;
    
    
    for(playerIndex = 0; playerIndex < numOfPlayers; playerIndex++)
    {
        playersHandType[playerIndex] = identifyHand(hands[playerIndex]);
    }
}

/*----------------------------   computeWinners   -------------------------
    | Function void computeWinners( int, int, int [])
    |
    | Purpose:  Determine who the winner(s) is/are.
    |           Winner(s) will be store in array winners, the player number     
    |           will be store in the array.     
    |           if you want to check is a player is a winner just compare if
    |           Player Number ==  winners[Player Number ]
    |
    | @param    
    |         int NumOfPlayers:      Number of Players
    |         int playersHandType[]: Array that will hold the hand's type
    |         int winners[][]:       Array holding the winner(s)
    |
    | @return  none
*--------------------------------------------------------------------------- */

void computeWinners (int numOfPlayers, int playersHandType[numOfPlayers],
                     int winners[numOfPlayers])
{
    int playerIndex = 0;
    int winnerCount = 0;
    int lastWinnerFound = 0;
    
    winners[playerIndex] = playerIndex;
    
    for(playerIndex = 1; playerIndex < numOfPlayers; playerIndex++)
    {
        if(playersHandType[playerIndex] >= playersHandType[lastWinnerFound])
        {
            if(playersHandType[playerIndex] > playersHandType[lastWinnerFound])
            {
                initializeWinners(numOfPlayers, winners);// zeroed winners array
                winnerCount = 0;
                winners[winnerCount] = playerIndex;
                lastWinnerFound = playerIndex;
            }
            else
            {
                winnerCount++; 
                winners[winnerCount] = playerIndex;
            }          
        }     
    }  
}

/*----------------------------   isAWinner   -------------------------
    | Function void isAWinner( int, int, int [])
    |
    | Purpose:  Determine if a player is a winner or not
    |           If player number is in winners array, the player is a winner.     
    |
    | @param    
    |         int playerNumber:     Player Number to check if is a winner
    |         int numOfPlayers:     Number of players
    |         int winners[][]:      Array holding the winner(s)
    |
    | @return  return True is player is a winner, False otherwise. 
*--------------------------------------------------------------------------- */

enum Boolean isAWinner(int playerNumber, int numOfPlayers, int winners[])
{
    int playerIndex = 0;
    
    for(playerIndex = 0; playerIndex < numOfPlayers; playerIndex++)
    {
        if(playerNumber == winners[playerIndex])
        {
            return True;
        }  
    }
    return False;
}

/*----------------------------   initializeWinners   -------------------------
    | Function void initializeWinners( int, int [])
    |
    | Purpose:  Initialize winner array to (-1) so it doe snot match any
    |           player numbers.           
    |
    | @param    
    |          int numOfPlayers:     Number of players
    |          int winners[][]:      Array holding the winner(s)
    |
    | @return  none 
*--------------------------------------------------------------------------- */

void initializeWinners(int numOfPlayers, int winners[numOfPlayers])
{
    int playerIndex = 0;
    
    for(playerIndex = 0; playerIndex < numOfPlayers; playerIndex++)
    {
        winners[playerIndex] = -1;
    }
}


        
