#include <stdio.h>
#include <math.h>
#define PI 3.14159


int main(){
	
	FILE *ptrCf;
	int i;
	float y,x;
	float s = 8*PI/81;
	
	if( (ptrCf = fopen("valores.dat","w")) ==  0)
	{
	printf("Error!");
	return -1;
	}
	else{
	for(i = 0; i < 81 ; i++){
		x = s*i;
		y = sin(x) * sin(x);
		fprintf(ptrCf, "%lf, %lf\n", x, y);
	}
	
}
	fclose(ptrCf);
	return 0;
}
	
