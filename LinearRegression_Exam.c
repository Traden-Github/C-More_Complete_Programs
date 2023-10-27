// calculate coefficients of linear-optimal of data
#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *cfPtr = NULL;
	int i = 1;
	float a;
	float b;
	float a_up, a_down, b_up, b_down;
	float x = 0;
	float sum_x = 0;
	float y = 0;
	float sum_y = 0;
	float sum_xSquare = 0;
	float sum_xy = 0;
	if((cfPtr = fopen("DATA.txt", "r"))!=NULL) {
		
		for( i=1; i<=41; i++) {
		    fscanf(cfPtr,"%f %f",&x,&y);
		    sum_xy += (x*y);
		    sum_x += x;
		    sum_y += y;
		    sum_xSquare += (x*x);
	    }
	    a_up = (41.0 * sum_xy) - (sum_y * sum_x);
		a_down = (sum_xSquare * 41.0) - (sum_x * sum_x);
		b_up = (sum_xSquare * sum_y) - (sum_x * sum_xy);
		b_down = (sum_xSquare * 41.0) - (sum_x * sum_x);
		a = a_up / a_down;
		b = b_up / b_down;
    }
	printf("a = %.20f, b = %.20f", a, b);
	fclose(cfPtr);
	
	return 0;
}
