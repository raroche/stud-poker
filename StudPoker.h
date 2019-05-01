/* 
| File:        StudPoker.h
| Author:      Roland Aroche

| Course:      COP 4338 (Advanced Programming)
 */

/* Includes */

#include <stdio.h>              /* Required for Input and output    */
#include <stdlib.h>             /* Required to use atoi and srand() function */
#include <time.h>               /* Time will be used to seed srand() */

/* Constants */

#define MAX_NUM_PLAYERS 10
#define MIN_NUM_PLAYERS 1
#define VALID_NUM_CARDS 5
#define DECK_SIZE       52
#define NUM_OF_RANKS    13
#define NUM_OF_SUITS    4
#define NO_CARD        -1         /* Unknown Card or removed from  deck (int) */ 
#define NO_SUIT        '?'        /*  Unknown Suit (char)  */ 
#define NO_ERROR        0         /* Zero for no errors    */
#define VALID_NUM_INPUT 3         /* Valid number of inputs  */
#define NUM_INPUTS           3    /* Number of input via command line */

/* Enumerations */

enum Boolean    { False, True };
enum Input      { PROGRAM_NAME = 0, NUM_CARDS = 1, NUM_PLAYERS = 2};
enum Suit       { CLUBS = 0, DIAMONDS = 1, HEARTS = 2, SPADES = 3};
enum HandsTypes { HIGH_CARD = 1, ONE_PAIR, TWO_PAIR, THREE_OF_A_KIND, STRAIGHT, 
                  FLUSH, FULL_HOUSE , FOUR_OF_A_KIND, STRAIGHT_FLUSH};

/* Structures */

typedef struct Card{
    int  cardRank;
    char cardSuit;
}Card; 

/* Function Prototypes */

void initializeDeck(Card deck[]);
void displayDeck(Card deck[]);
enum Boolean validateInput(int argc, char * argv[], int input[]);
enum Boolean getInput(char * argv[], int input[]);
void invalidInputMsg ();
void displayCard(Card card);
void displayRank(int card);
char computeSuit(int card);
void shuffleDeck (Card deck[]);
void swapCards (Card * card1, Card * card2);
void initializeHand(int numOfPlayers, int numOfCards, Card hands[][*]);
void deal(Card deck[*], int numOfPlayers, int numOfCards, Card hands[][*]);
void displayHands(int numOfPlayers, int numOfCards, Card hands[][*]);
void sortHands(int numOfPlayers, int numOfCards, Card hand[][*]);
void sortHand(Card hand[]);
void displayTestHands();
void displayHand(Card hand[]);
enum Boolean isStraightFlush(Card hand[]);
enum Boolean isFourOfAKind(Card hand[]);
enum Boolean isFullHouse(Card hand[]);
enum Boolean isFlush(Card hand[]);
enum Boolean isStraight(Card hand[]);
enum Boolean isThreeOfAKind(Card hand[]);
enum Boolean isTwoPair(Card hand[]);
enum Boolean isOnePair(Card hand[]);
enum Boolean isHighCard(Card hand[]);
enum HandsTypes identifyHand(Card hand[]);
void displayWinnerHands(int numOfPlayers, int numOfCards, Card hands[][*]);
void classifyhands (int, int , Card [][*], int []); 
void computeWinners (int numOfPlayers, int playersHandType[], int winners[]);
enum Boolean isAWinner(int playerNumber, int numOfPlayers, int winners[]);
void initializeWinners(int numOfPlayers, int winners[numOfPlayers]);

        
/* Helper Arrays */
static char ranks[13] = {'A', '2', '3', '4', '5', '6', 
                    '7', '8', '9', 'T', 'J', 'Q', 'K'};

static char * handTypes[] = {"Unknown Hand", "High Card", "One Pair", 
                            "Two Pairs", "Three of a Kind", "Straight", "Flush", 
                            "Full House", "Four of a Kind", "Straight Flush"};

/* Hands for testing */
// Note: Cards start at zero, A = 0, 2 = 1, ..., K = 12.

static Card highCard[VALID_NUM_CARDS] 
                = {{1,'C'},{8,'D'},{2,'H'},{6,'D'},{10,'S'}};

static Card onePairs[VALID_NUM_CARDS] 
                = {{2,'C'},{4,'D'},{6,'H'},{8,'D'},{8,'S'}}; 

static Card twoPairs[VALID_NUM_CARDS] 
                = {{5,'C'},{8,'D'},{8,'H'},{9,'D'},{9,'S'}};

static Card threeOfAKind[VALID_NUM_CARDS] 
                = {{2,'C'},{9,'D'},{9,'H'},{9,'S'},{8,'S'}};

static Card straight[VALID_NUM_CARDS] 
                = {{8,'H'},{9,'D'},{10,'S'},{11,'C'},{12,'D'}};

static Card flush[VALID_NUM_CARDS] 
                = {{3,'D'},{0,'D'},{1,'D'},{6,'D'},{11,'D'}};

static Card fullHouse[VALID_NUM_CARDS] 
                = {{3,'D'},{3,'C'},{3,'H'},{11,'C'},{11,'S'}};

static Card fourOfAKind[VALID_NUM_CARDS] 
                = {{7,'H'},{2,'C'},{2,'H'},{2,'D'},{2,'S'}};

static Card straightFlush[VALID_NUM_CARDS] 
                = {{5,'H'},{6,'H'},{7,'H'},{8,'H'},{9,'H'}};



