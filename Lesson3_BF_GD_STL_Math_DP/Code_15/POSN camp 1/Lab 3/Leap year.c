/*
    TASK:Leap year
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<stdio.h>
int main()
{
    int x,y,a;
    scanf(" %d %d",&x,&y);
    for(a=y;a>=x;a--)
    {
       if(a%4==0 && a%100!=0)
       {
       printf("%d\n",a);
       }else
       if(a%400==0)
       {
       printf("%d\n",a);
       }
    }

    return 0;
}
