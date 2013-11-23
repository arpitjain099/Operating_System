#include <syscall.h>
#include <stdio.h>
//#include "userprog/process.c"

int f(int n)
{
  if(n==0)
    return 0;
  return f(n-1)+1;
}

int
main (void)
{
 	int i,j;
 	char *c;
 	c="b";
 	//j=process_execute(c);
 	for(i=0;i<11;i++)
 	{
	  for(j=0;j<1000000;j+=10000)
		  printf("f(%d)=%d  \n", j, f(j));
 	}
}

