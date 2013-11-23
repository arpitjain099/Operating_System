#include<stdio.h>
int main() 
{
printf("Main purpose is evaluation of bitwise operations\n");
int d=3;int c=4;int e;
printf("bitwise left shift\n");
printf("We will do d<<1. d is :");
printf("%d",d);
printf("\n");
d=d<<1;
printf("Now d is: ");
printf("%d", d);
printf("\n");
printf("---------------------\n");
printf("bitwise right shift\n");
printf("We will do d>>1. d is :");
printf("%d",d);
printf("\n");
d=d>>1;
printf("%d", d);
printf("\n");
printf("---------------------\n");
printf("bitwise and\n");
printf("We will do e=d&c. d is :");
printf("%d",d);
printf(" and c is :");
printf("%d",c);
printf("\n");
e=d&c;
printf("e is :");
printf("%d",e);
printf("\n");
printf("\n");
printf("---------------------\n");

printf("bitwise or\n");
printf("We will do e=d|c. d is :");
printf("%d",d);
printf(" and c is :");
printf("%d",c);
printf("\n");
e=d|c; 
printf("e is :");
printf("%d",e);
printf("\n");
printf("\n");
printf("---------------------\n");
printf("bitwise xor\n");
e=d^c;
printf("e is :");
printf("%d",e);
printf("\n"); 

}
