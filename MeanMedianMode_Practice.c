// input 20 scores for a TV show from user
// calculate mean, median, mode of data
// for dynamic arrays: need to learn pointers

#include <stdio.h>
#define SIZE 20

void mean(const int scores_mean[]);
void median(int scores_med[]);
void mode(int frequency[], const int scores_mode[]);
void bubbleSort(int scores_bub[]);

int main(void) {

    printf("||| TV SHOW AUDIENCE SCORE CALCULATING SYSTEM |||\n\n"
           "    Enter 20 audience scores(0-10)for us to\n    calculate "
		   "mean, median, and mode of these\n    scores.\n\n\n");
	int score = 0;
	int scores[SIZE] = {0};
	size_t i1 = 0;
	int count = 0;	
    for(;i1<SIZE;++i1) {
    	printf("    Input score number %d\n    ", i1+1);
		scanf("%d", &score);
		if(score >= 0 && score <= 10) {
			scores[i1] = score;
			++count;
		}
	}
	if(count != SIZE) {
		puts("\n    Oops, your input wasn't correct :C\n");
		puts("    Please restart program!");
	}
	else {
		int frequency[11]={0};
		mean(scores); 
		median(scores);
		mode(frequency, scores);
	}
}

void mean(const int scores_mean[]) {
	int sum = 0;
	size_t i2 = 0;
	for(;i2<SIZE;++i2) {
		sum += scores_mean[i2];
	}
	double mean = (double)sum / SIZE;
	printf("%s","    --------\n      Mean\n    --------\n\n");
	printf("    The mean score: %.2lf\n\n", mean);
}

void median(int scores_med[]) {
	bubbleSort(scores_med);
	printf("%s","    --------\n     Median\n    --------\n\n");
	printf("    The median score: %.2lf\n\n", ((double)(scores_med[SIZE/2] + scores_med[SIZE/2-1]))/2);
} 

void bubbleSort(int scores_bub[]) {
	int pass = 1;
	for(; pass < SIZE; ++pass) {
		size_t i3 = 0;
		for(; i3 < SIZE - 1; ++i3) {
			
			if(scores_bub[i3] > scores_bub[i3+1]) {
				int hold = scores_bub[i3];
				scores_bub[i3] = scores_bub[i3+1]; 
				scores_bub[i3+1] = hold;
			}
		}
	}
}

void mode(int frequency_mode[], const int scores_mode[]) {
	size_t i4 = 0;
	for(; i4 < SIZE; ++i4) {
		++frequency_mode[scores_mode[i4]];
	}
	int largest = 0;
	int modeValue = 0;
	int modeCount = 1;
	
	size_t i5 = 0;
	for(; i5 < 11; ++i5) {
		if(frequency_mode[i5] > largest) {
			largest = frequency_mode[i5];
			modeValue = i5;
		}
	}
	printf("%s","    --------\n      Mode\n    --------\n\n");
	printf("    The mode value(s): %d", modeValue);
	size_t i6 = 0;
	for(; i6 < 11; ++i6) {
		if(largest == frequency_mode[i6] && i6 != modeValue) {
			printf(", %zu", i6);
			++modeCount;
		}
	}
	if(modeCount == 1) {
		printf(", which appears %d times.\n", frequency_mode[modeValue]);
	}
	else if(modeCount == 2) {
		printf(", both of which appear %d times.\n", frequency_mode[modeValue]);
	}
	else {
		printf(", all of which (%d modes) appear %d times.\n", modeCount, frequency_mode[modeValue]);
	}
}   
    
    
    
	       

