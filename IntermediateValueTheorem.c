#include <stdio.h>
#include <math.h>

double function(double x); 

int main(void) {
	double a = -15.0;
	double b = 15.0;
	double answer = 0.0;
	
	while (1){
		// 1.
		double c = (a + b) / 2;
		// 2.
		double value = function(c);
		double leftValue = function(a);
		double rightValue = function(b);
		double accuracy = 0.00001;
		// 3. 
		if(leftValue * value < 0) {
			if(abs(value) < accuracy) {
				answer = c;
				break;
			}
			b = c;
		}
		
		if(value * rightValue < 0) {
			if(abs(value) < accuracy) {
				answer = c;
				break;
			}
			a = c;
		}
	}
	
	printf("The root value is %lf", answer);
	return 0;
}

double function(double x) {
	double f_of_x = 0.0021 * pow(x, 5) + 0.00067 * pow((x-13), 4) + 46.7 * x -100; 
	return f_of_x;
}
