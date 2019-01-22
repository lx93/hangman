#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main() {

	srand(time(NULL));

	char guessWords[][16]={"green","yellow","purple","windows","linux","apple"};
	//index for random word
	int randomIndex = rand() % 6;

	int numLives = 5;
	int numCorrect = 0;
	int oldCorrect = 0;
	
	int lengthOfWord = strlen(guessWords[randomIndex]);

	int letterGuessed[9] = {0,0,0,0,0,0,0,0,0};

	int quit = 0;
	
	int loopIndex = 0;

	char guess[16];

	char letterEntered;

	/*printf("guessWords:%s randomIndex:%d lengthOfWord:%d\n",
			guessWords[randomIndex],
			randomIndex,
			lengthOfWord);*/
	
	// game loop
	while (numCorrect < lengthOfWord) {
		// prints out what has been guessed so far
		
		printf("\nnew turn! hangman word is: ");

		for (loopIndex=0;loopIndex<lengthOfWord;loopIndex++){
			if (letterGuessed[loopIndex] == 1){
				printf("%c",guessWords[randomIndex][loopIndex]);
			} else {printf("*");}
		}

		printf("\nnumCorrect so far is: %d\n",numCorrect);
		printf("Enter a guess letter\n");
		fgets(guess,16,stdin);

		if (strncmp(guess,"quit",4) == 0){
			quit = 1;
			break;
		}

		oldCorrect = numCorrect;
		
		letterEntered = guess [0];
		printf("letterEntered: %c\n",letterEntered);
		
		for (loopIndex=0;loopIndex<lengthOfWord;loopIndex++){
			
			if (letterGuessed[loopIndex] == 1) {
				continue;
			}

			if (letterEntered == guessWords[randomIndex][loopIndex]){
				letterGuessed[loopIndex] = 1;
				numCorrect++;
			}
		}

		if (oldCorrect == numCorrect) {
			numLives--;
			printf("Sorry you just lost a life, life left: %d\n",numLives);
			if (numLives == 0) {break;}
		} else {
			printf("Correct :)\n");
		}
		
	}
	

	if (quit == 1) {printf("\nthe user quits early\n");}
	else if (numLives == 0) {printf("Sorry you lose, the word was: %s\n",guessWords[randomIndex]);}
	else {printf("\nYOU WIN!!\n");}




	return 0;
}
