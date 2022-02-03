/*
    TASK:Enigma
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
int main()
{
    int n;
    scanf(" %d",&n);
    n=(2*n)-1;
    int x,y,p;
    for(x=1;x<=n;x+=2)
    {
        p=(n-x)/2;
        for(y=0;y<p;y++)
        {
            printf("+");
        }
        for(y=0;y<x;y++)
        {
            printf("0");
        }
        for(y=0;y<p;y++)
        {
            printf("+");
        }
        printf("\n");
    }
        for(x=(n-2);x>=1;x-=2)
    {
        p=(n-x)/2;
        for(y=0;y<p;y++)
        {
            printf("+");
        }
        for(y=0;y<x;y++)
        {
            printf("0");
        }
        for(y=0;y<p;y++)
        {
            printf("+");
        }
        printf("\n");
    }
    return 0;
}
