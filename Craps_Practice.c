/* Recreating dice game "Craps"
   Bugs:Enter character to roll and iteration won't terminate
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status { WIN, LOSE, CONTINUE };
int rollDice(void);

int main(void) {
	int roll = 0;
	int sum = 0;
	int point = 0;
	puts("Welcome to the casino game \"Craps\"!");
	enum Status gameResult = CONTINUE;
    puts("Enter 1 to roll dice!"); 
	while(gameResult == CONTINUE) {
		scanf("%d", &roll);
	    if(roll == 1){
		    sum = rollDice();
		    printf("Player rolled a sum of %d\n", sum);
		    switch(sum) {
		        case 7:
		        case 11:
		      	    gameResult = WIN;
			   	    break;
			    case 2:
			    case 3:
			    case 12:
			        gameResult = LOSE;
				    break;
			    default:
				    printf("%d is now your point\n", sum); 
				    point = sum;
			        puts("It's time to prove your point!");
				    puts("Enter 1 to roll dice!");
				    break;
		    }
		    while(gameResult == CONTINUE) {
                scanf("%d", &roll);
		    	if(roll == 1) {
		    	    sum = rollDice();
		    	    printf("Player rolled a sum of %d\n", sum);
		    	    if(sum == point) {
		    		    puts("Wow! You proved your point!");
		    		    gameResult = WIN;
				    }
				    else {
					    puts("Enter 1 to roll dice!");
				    }
			    }
			    else{
		            puts("Oops, please try again!");
			    }
	        }
	    }
	    else{
		    puts("Oops, please try again!");
	    }
    }
    if(gameResult == WIN) {
    	puts("Congradulations! You Won!");
	}
	else {
		puts("Oops! You lost :C");
	}
}
int rollDice(void) {
	srand(time(NULL));
	int rng1 = 1 + (rand() % 6); 
	int rng2 = 1 + (rand() % 6);
	return rng1 + rng2;
}

