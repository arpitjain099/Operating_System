#include<stdio.h>
#include<stdlib.h>
struct _newstruct{
int a;
int b;
};
int main()
{
struct _newstruct n;
n.a=4;
n.b=1;//invalid call to struct member as no instance of type _newstruct has been created so far!!
int i=5;

}
