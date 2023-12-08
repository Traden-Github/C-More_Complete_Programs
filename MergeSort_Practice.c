#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge_sort(int a[], int length);
void merge_sort_recursion(int a[], int l, int r);
void merge_sorted_arrays(int a[], int l, int m, int r);

int main(void)
{
	srand(time(NULL));
	int n;
	do
	{
		printf("%s", "Choose array size: ");
		scanf("%d", &n);
	}
	while (n <= 0);
	
	int array[n];
	int i;
	puts("Randomized array:");
	printf("%12s%8s\n", "Subscript", "Value");
	for (i = 0; i < n; i++)
	{
		array[i] = 1 + rand() % 100;
		printf("%12d%8d\n", i, array[i]);
	}
	
	merge_sort(array, n);
	
	puts("Sorted array:");
	printf("%12s%8s\n", "Subscript", "Value");
	for (i = 0; i < n; i++)
	{
		printf("%12d%8d\n", i, array[i]);
	}
	return 0;
}

void merge_sort(int a[], int length)
{
	merge_sort_recursion(a, 0, length - 1);
	return;
}

void merge_sort_recursion(int a[], int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
	
		merge_sort_recursion(a, l, m);
		merge_sort_recursion(a, m + 1, r);
		merge_sorted_arrays(a, l, m, r);	
	}
	return;
}

void merge_sorted_arrays(int a[], int l, int m, int r)
{
	int left_length = m - l + 1;
	int right_length = r - m;
	
	int temp_left[left_length];
	int temp_right[right_length];
	
	int i, j, k;
	
	for (i = 0; i < left_length; i++)
	{
		temp_left[i] = a[l + i];	
	}
	
	for (i = 0; i < right_length; i++)
	{
		temp_right[i] = a[m + 1 + i]; 
	}
	
	for (i = 0, j = 0, k = l; k <= r; k++)
	{
		if (i == left_length)
		{
			a[k] = temp_right[j];
			j++;
			continue;
		}
		if (j == right_length)
		{
			a[k] = temp_left[i];
			i++;
			continue;
		}
		if (temp_left[i] <= temp_right[j])
		{
			a[k] = temp_left[i];
			i++;
		}
		else
		{
			a[k] = temp_right[j];
			j++;
		}
	}
	return;
}


