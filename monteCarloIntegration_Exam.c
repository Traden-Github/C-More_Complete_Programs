#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double function(double x, double y);
double max(double a, double b);

int main(void)
{
	srand(time(NULL));
	double x;
	puts("What's x? ");
	scanf("%lf", &x);
	double y;
	puts("What's y? ");
	scanf("%lf", &y);
	double f_of_x = function(x, y);
	
	printf("f(x,y) = %lf\n", f_of_x);
	
	if (x < 0 || x > 10)
	{
		do
		{
			puts("Please enter x again for 0 <= x <= 10");
			scanf("%lf", &x);	
		}
		while (x < 0 || x > 10);
	}
	if (y < 0 || y > 10)
	{
		do
		{
			puts("Please enter y again for 0 <= y <= 10");
			scanf("%lf", &y);	
		}
		while (y < 0 || y > 10);
	}
	if (f_of_x < 0 || f_of_x > 14)
	{
		puts("Oops, something went wrong");
		return 1;
	}
	if (function(x, y) != f_of_x)
	{
		printf("New f(x, y) = %lf\n", function(x, y));
	}
	f_of_x = function(x, y);
	double error = 0.0001;
	double y_max = 14 + error;
	double x_max = max(x, y);
	unsigned long long int trials;
	do
	{
		puts("Number of trials(range from 10,000 to 1,000,000): ");
		scanf("%llu", &trials);
	}
	while (trials < 10000 || trials > 1000000);
	
	int i;
	int accept = 0;
	for (i = 0; i < trials; i++)
	{
		int temp_x = (double)rand() / RAND_MAX * x_max;
		int	temp_y = (double)rand() / RAND_MAX * y_max;
		
		if (temp_y > f_of_x)
		{
			continue;
		}
		accept++;
	}
	
	double integral = (double)accept / trials * x_max * y_max;
	
	printf("Integral of f(x, y) = %f", integral);
	return 0; 
}

double function(double x, double y)
{
	double power_1 = -pow(x - 3.1, 2) / 7.9 - pow(y - 4.3, 2) / 12.0;
	double power_2 = -pow(x - 7.1, 2) / 2.0 - pow(y - 8.2, 2) / 6.0;
	return 9.8 * exp(power_1) + 12.0 * exp(power_2);
}

double max(double a, double b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
