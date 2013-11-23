#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("All data types are implemented.\n");
	printf("---------------------\n");
	short i=5;
	printf("i is short\n");
	printf("---------------------\n");
	unsigned long j;
	j=786758467;
	printf("j is unsigned long\n");
	printf("---------------------\n");
	double k=9.1;
	float l=2.4;
	printf("k is a double with value:");
	printf("%f",k);
	printf("l is a float with value:");
	printf("%f",l);	
	double m=k+l;
	printf("adding a double and float...result is:\n");
	printf("%f",m);
	printf("---------------------\n");
	printf("Program closes");
}
