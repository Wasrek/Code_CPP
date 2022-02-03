/*
    TASK:Peatty Robot
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
#include<string.h>
char o[200];
int main()
{
    gets(o);
    int l,x,f=0,n=0;
    l=strlen(o);
    for(x=0;x<l;x++)
    {
        if(o[x]=='N')
        {
            f=f+1;
        }else
        if(o[x]=='S')
        {
            f=f-1;
        }else
        if(o[x]=='E')
        {
            n=n+1;
        }else
        if(o[x]=='W')
        {
            n=n-1;
        }else
        if(o[x]=='Z')
        {
            n=0;f=0;
        }
    }
    printf("%d %d",n,f);
    return 0;
    }
