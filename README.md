# stud-poker
This C program simulate a deck of cards and deal a hand of cards

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
|  Description: This program simulate a deck of cards and deal a hand of cards              
|  
|  Input: Input is provided via command-line arguments
|         Input will specify the numbers of cards per hand  
|         and the numbers of players, in that order. 
|         Execution would look something like: ./MainDeckOFCard.out 7 5
|                
|      Two Integer are expected via command line arguments 
|      - First integer is the number of Cards [5], poker requires 5 cards
|        any other integer value entered different than 5 will be converted to 5 
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
