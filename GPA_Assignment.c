// prompt input grade and credit, then determine GPA
#include <stdio.h>

int main() {
	int weightedSum = 0;
	int grade = 0;
	int weightCount = 0;
	int credit = 0;
	FILE *cfPtr = NULL;
	
	if((cfPtr = fopen("scoresheet.txt", "w"))== NULL) {
		printf("%s", "File could not be opened.");
	}
	else {
		puts("Enter grade then credit, then press enter to input.\nEnter the EOF keystroke to end input.");
	    scanf("%d%d", &grade, &credit);
	    
		while(!feof(stdin)) {
		    
			if(grade < 0 || grade > 100){
			   printf("Invalid grade, please try again!\n");
			   scanf("%d%d", &grade, &credit);
		    }
		    else {
			   weightedSum += (grade * credit);
			   weightCount += credit ;
			   fprintf(cfPtr, "%d %d\n", grade, credit);
			   puts("Enter grade then credit, then press enter to input.\nEnter the EOF keystroke to end input.");
			   scanf("%d%d", &grade, &credit);
		    }
	    }
		int weightedGrade = 0;
		if(weightCount != 0) {
		    weightedGrade = weightedSum / weightCount;
		
		    if(weightedGrade >= 90 && weightedGrade <= 100) {
			   fprintf(cfPtr, "%d %c", weightedGrade, 'A');
		    }
		    else if(weightedGrade >= 80 && weightedGrade < 90) {
			   fprintf(cfPtr, "%d %c", weightedGrade, 'B');
		    }
		    else if(weightedGrade >= 70 && weightedGrade < 80) {
			   fprintf(cfPtr, "%d %c", weightedGrade, 'C');
		    }
		    else if(weightedGrade >= 60 && weightedGrade < 70) {
			   fprintf(cfPtr, "%d %c", weightedGrade, 'D');
		    }
		    else if(weightedGrade < 60) {
			   fprintf(cfPtr, "%d %c", weightedGrade, 'F');
		    }
		    else {
			   puts("Oops, your score went wrong :C\n(You probably typed the credits wrong)");
		    }
	    }
	    else {
			puts("No scores were added :C");
	    } 
		
		fclose(cfPtr);  
		
	}
    return 0;
}
