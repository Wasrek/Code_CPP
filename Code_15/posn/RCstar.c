#include<stdio.h>
int main()
{
int R,C,x,y;
scanf(" %d %d",&R,&C);
for(x=0;x<R;x++)
{
    for(y=0;y<C;y++)
    {
    printf("*");
    }
    printf("\n");
}

return 0;
}
