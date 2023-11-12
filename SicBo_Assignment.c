#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int odd_or_even(void);
int odd(void);
int even(void);
int rollDice(void);


int main(void) {
	srand(time(NULL));
	int amount = 1000;
	int winCount = 0;
	int option = 0;
	int result = 0;
	int i = 1;
	for(;i<=amount;++i) {
		option = odd_or_even();
		if(option == 1) {
			result = odd();	
		}
		else {
			result = even();
		}
		winCount += result;
	}
	
	printf("Win Rate: %.1f %%", ((double)winCount/amount)*100);
	return 0;
}

int odd_or_even(void) {
	return rand() % 2;
}

int odd(void) {
	int a = rollDice();
	int b = rollDice();
	int c = rollDice();
	int total = a + b + c;
	switch(total) {
		case 5:
		case 7:
		case 9:
		case 11:
		case 13:
		case 15:
		case 17:
			if((a==3&&b==3&&c==3)||(a==5&&b==5&&c==5)) {
				return 0;
			}
			else {
				return 1;
			}
			break;
		default:
			return 0;
	}
}

int even(void) {
	int a = rollDice();
	int b = rollDice();
	int c = rollDice();
	int total = a + b + c;
	switch(total) {
		case 4:
		case 6:
		case 8:
		case 10:
		case 12:
		case 14:
		case 16:
			if((a==2&&b==2&&c==2)||(a==4&&b==4&&c==4)) {
				return 0;
			}
			else {
				return 1;
			}
			break;
		default:
			return 0;
	}
}

int rollDice(void) {
	int dice = 1 + (rand() % 6);
	return dice;
}

