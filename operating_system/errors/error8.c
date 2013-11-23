#include<stdio.h>
#include<stdlib.h>
enum _fruits{
apple;
banana;
oranges;
}fruits;
int main()
{
enum fruits n=apple;
n=apple;
//n.banana=1;
//n.oranges=3;

//invalid call to struct member as no instance of type _newstruct has been created so far!!
int i=5;

}
