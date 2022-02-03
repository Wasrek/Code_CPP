/*
    TASK:Quadrant
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
int main()
{
    int a;
    scanf(" %d",&a);
    a=a%360;
    if(a<0){a=a+360;}
    if(a==0 || a==180){printf("x-axis");}else
    if(a==90 || a==270){printf("y-axis");}else
    if(a>0 && a<90){printf("1");}else
    if(a>90 && a<180){printf("2");}else
    if(a>180 && a<270){printf("3");}else
    if(a>270 && a<360){printf("4");}
    return 0;
}
