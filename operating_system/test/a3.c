#include<stdio.h>
int main() 
{
int a=3;
int b=4;
printf("We will do if-else with a<b. a is :");
printf("%d",a);
printf(" and b is :");
printf("%d",b);
printf("\n");
int c;
if(a<b){
	printf("a is less than b\n");
}
else if(a==b){
	printf("a is equal to b\n");
}
else if(a>b)
{
	printf("a is greater than b\n");
}
}
