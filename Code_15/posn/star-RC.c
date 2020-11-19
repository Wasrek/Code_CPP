#include<stdio.h>
int main()
{
int R,C,x,y;
scanf(" %d %d",&R,&C);
for(x=0;x<R;x++)
{
    /*if(x==0  ||  x==(R-1)){
    for(y=0;y<C;y++)
    {printf("*");}
    }else*/

    {for(y=0;y<C;y++)
    {

    if(y==0 || y==(C-1)){
    printf("*");
    }else
    if(x==0  ||  x==(R-1)){
    printf("*");
    }else
    {printf("-");}
    }

    }

    printf("\n");

}

return 0;
}
