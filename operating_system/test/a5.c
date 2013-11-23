#include<stdio.h>
int main()
{
    int result=1,term1=0,term2=1,i=1;
    printf("%d",result);
    while(i<10)
    {
        result = term1 + term2;
        printf("%d",result);
        term1 = term2;
        term2 = result;
        i++;
    }
}
