/*
    TASK: Intro02
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
int main()
{
    char x,y;
    scanf(" %c %c",&x,&y);
    if(x<91){x=x+32;}else{x=x-32;}
    if(y<91){y=y+32;}else{y=y-32;}
    printf("%c %c",x,y);
    return 0;
}
