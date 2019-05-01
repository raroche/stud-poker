 
# File:        Makefile
# Author:      Roland Aroche

# Course:      COP 4338 (Advanced Programming)


CC = gcc
FILES = StudPokerMain.c Deck.c Card.c Hand.c
OUT_EXE = StudPokerMain.out

build: $(FILES)
	$(CC) $(FILES) -o $(OUT_EXE) 

clean:
	rm -f *.o core

rebuild: clean build
