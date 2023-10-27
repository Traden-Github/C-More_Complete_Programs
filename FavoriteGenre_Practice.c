// Will be a lot easier to code this program with arrays
// 100% Simplicity 0% efficiency :C

#include <stdio.h>
#include <math.h>

int main(void) {
    
   int code1, code2, code3;
   code1 = code2 = code3 = 0;
   int psychological, fantasy, drama, supernatural, mystery, comedy, action, political, romance;
   psychological = fantasy = drama = supernatural = mystery = comedy = action = political = romance = 0;
   FILE *cfPtr = NULL;
   
   if((cfPtr = fopen("FavoriteFictionalGenre.txt", "w"))!= NULL) {
      printf("%s", "Enter the code for 3 of the preferred stories below to see what genre you like the most!\n");
      printf("%35s","Omori-1"),printf("%35s","Mr.Robot-2"),printf("%45s","Monogatari Series-3\n");
      printf("%35s","Attack on Titan-4"),printf("%35s","Berserk-5"),printf("%45s","Undertale + Deltarune-6\n");
      printf("%35s","The House in Fata Morgana-7"),printf("%35s","Gintama-8"),printf("%45s","Breaking Bad + Better Call Saul-9\n");
      scanf("%d%d%d", &code1, &code2, &code3);
      
      while((code1 < 1 || code1 > 9) || (code2 < 1 || code2 > 9)|| (code3 < 1 || code3 > 9)) {
      	puts("Oops! You entered wrong code for at least one of the stories! Try again!");
      	scanf("%d%d%d", &code1, &code2, &code3);
      }
	  switch(code1) {
         case 1:
            psychological++;
			fantasy++;
			supernatural++;
			break;
		 case 2:	
		    drama++;
		    mystery++;
		    political++;
		    break;
		 case 3:
		    mystery++;
		    comedy++;
		    supernatural++;
		    romance++;
		    break;
		 case 4:
		    action++;
		    political++;
		    supernatural++;
		    break;
		 case 5:
		    drama++;
		    fantasy++;
		    psychological++;
		    romance++;
		    break;
		 case 6:
		    comedy++;
		    psychological++;
		    mystery++;
		    break;
		 case 7:
		    mystery++;
		    romance++;
		    drama++;
		    break;
		 case 8:
		    comedy++;
		    action++;
		    fantasy++;
		    political++;
		    break;
		 case 9:
		    drama++;
		    action++;
		    break;
      }
      switch(code2) {
         case 1:
            psychological++;
			fantasy++;
			supernatural++;
			break;
		 case 2:	
		    drama++;
		    mystery++;
		    political++;
		    break;
		 case 3:
		    mystery++;
		    comedy++;
		    supernatural++;
		    romance++;
		    break;
		 case 4:
		    action++;
		    political++;
		    supernatural++;
		    break;
		 case 5:
		    drama++;
		    fantasy++;
		    psychological++;
		    romance++;
		    break;
		 case 6:
		    comedy++;
		    psychological++;
		    mystery++;
		    break;
		 case 7:
		    mystery++;
		    romance++;
		    drama++;
		    break;
		 case 8:
		    comedy++;
		    action++;
		    fantasy++;
		    political++;
		    break;
		 case 9:
		    drama++;
		    action++;
		    break;
      }
      switch(code3) {
         case 1:
            psychological++;
			fantasy++;
			supernatural++;
			break;
		 case 2:	
		    drama++;
		    mystery++;
		    political++;
		    break;
		 case 3:
		    mystery++;
		    comedy++;
		    supernatural++;
		    romance++;
		    break;
		 case 4:
		    action++;
		    political++;
		    supernatural++;
		    break;
		 case 5:
		    drama++;
		    fantasy++;
		    psychological++;
		    romance++;
		    break;
		 case 6:
		    comedy++;
		    psychological++;
		    mystery++;
		    break;
		 case 7:
		    mystery++;
		    romance++;
		    drama++;
		    break;
		 case 8:
		    comedy++;
		    action++;
		    fantasy++;
		    political++;
		    break;
		 case 9:
		    drama++;
		    action++;
		    break;
         }
   		 fprintf(cfPtr, "Your favorite genre(s):\n  ");
		 
		 if (psychological > 1) {
		 	fprintf(cfPtr, "%s","Psychological  ");
		 }
		 if (fantasy > 1) {
		 	fprintf(cfPtr, "%s","Fantasy  ");
		 }
		 if (drama > 1) {
		 	fprintf(cfPtr, "%s","Drama  ");
		 }
		 if (supernatural > 1) {
		 	fprintf(cfPtr, "%s","Supernatural  ");
		 }
		 if (mystery > 1) {
		 	fprintf(cfPtr, "%s","Mystery  ");
		 }
		 if (comedy > 1) {
		 	fprintf(cfPtr, "%s","Comedy  ");
		 }
		 if (action > 1) {
		 	fprintf(cfPtr, "%s","Action  ");
		 }
		 if (political > 1) {
		 	fprintf(cfPtr, "%s","Political  ");
		 }
		 if (romance > 1) {
		 	fprintf(cfPtr, "%s","Romance  ");
		 fclose(cfPtr);
	     }
	     puts("Check for txt file!");
	     return 0;
   }
   else {
      puts("Could not open file :C");	      
   return 1;
   }
}

