#include <syscall.h>
#include <stdio.h>
int
main (void)
{
 int i,j;
 for(i=0;i<11;i++)
 {
 	for(j=0;j<100000;j++);
 	if(i==10)
 	{
 		i=0;
 	}
 	printf("a%d  ",i);
 }
}
