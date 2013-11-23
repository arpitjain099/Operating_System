#include<stdio.h>

int main()
{
	
	int k=100;
	printf("prime nos less than 100:\n");
	int j;
	int i=2;
	int flag;
	int c;
	while(i<k) {	
	flag=1;
	j=2;
		while(j<i) {

			c=i%j;
			if(c==0) {
				flag=0;
			}
			j++;
		}
		if(flag==1) {
			printf("%d",i);
		}
		i++;
	}
}
