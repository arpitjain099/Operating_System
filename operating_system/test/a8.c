#include <stdio.h>
#include <stdlib.h> 
int main()
{
	int i=1;
	int n=6;
	int fact=1;
	int temp;
	printf("Factorial of ");
	printf("%d",n);
	while(i<n){
		temp=i*fact;
		fact=temp;i++;
	}
	printf("value of fact is ");
	printf("%d",fact);
}
