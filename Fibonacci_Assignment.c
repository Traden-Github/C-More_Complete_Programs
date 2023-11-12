// fibonacci with repetition structure

#include <stdio.h>

int main(void) {
	printf("%s", "Enter an integer: ");
	int input = 0;
	scanf("%d", &input);
	int fibonacci_0 = 0;
	int fibonacci_1 = 1;
	unsigned long long int result = 0;
	if(input==0) {
		result = fibonacci_0;
	}
	else if(input==1) {
		result = fibonacci_1;
	}
	else if(input>=2) {
		int count = 1;
		int first = 0;
		int second = 1;
		while(count<=input-1) {
			int hold = second;
			second += first;
			first = hold;
			++count;
		}
		result = second;
	}
	else {
		puts("Invalid input");
		return 1;
	}
	printf("Fibonacci(%d) = %llu", input, result);
	return 0;
}
