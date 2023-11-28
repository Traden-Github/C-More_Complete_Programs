// BubbleSort modifications: 
// 1. one less comparison each pass 
// 2. end if no swaps occur

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main(void)
{
	int data[SIZE];
	srand(time(NULL));
	
	// store random data in data array
	puts("Unsorted list of randomized data:");
	int i;
	for (i = 0; i < SIZE; i++)
	{
		data[i] = 1 + rand() % 100;	
		if (i != SIZE - 1)
		{
			printf("%i ", data[i]);	
		}
		else
		{
			printf("%i\n", data[i]);	
		}	
	}
	
	// initiate BubbleSort
	int pass, comp;
	int swaps = 0;
	for (pass = 0; pass < SIZE - 1; pass++)
	{
		for (comp = 0; comp < SIZE - 1 - pass; comp++)
		{
			if (data[comp] > data[comp + 1])
			{
				int hold = data[comp];
				data[comp] = data[comp + 1];
				data[comp + 1] = hold;
				swaps++;	
			}	
		}
		if (swaps == 0)
		{
			break;
		}
		swaps = 0;
	}
	puts("");
	puts("Sorted list of randomized data:");
	int j;
	for (j = 0; j < SIZE; j++)
	{
		if (j != SIZE - 1)
		{
			printf("%i ", data[j]);	
		}
		else
		{
			printf("%i\n", data[j]);
		}
	}
	return 0;				
}
