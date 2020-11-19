/*
    TASK:Peatty Robot Gen2
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
    int l,x,cr=0,n=0,y,r,an=0;
    l=strlen(o);
    for(x=0;x<l;x++)
    {
        if(x==0)
        {
            if(o[x]=='N')
            {
                printf("F");
            }else if(o[x]=='S')
            {
                printf("RRF");
            }else if(o[x]=='E')
            {
                printf("RF");
            }else if(o[x]=='W')
            {
                printf("RRRF");
            }else if(o[x]=='Z')
            {
                printf("Z");
            }
        }else if(o[x]!=0)
        {
            if(o[x]=='N')
        {
            if(o[x-1]=='N' || o[x-1]=='Z')
            {
                printf("F");
            }else if(o[x-1]=='S')
            {
                printf("RRF");
            }else if(o[x-1]=='E')
            {
                printf("RRRF");
            }else if(o[x-1]=='W')
            {
                printf("RF");
            }
        }else if(o[x]=='E')
        {
            if(o[x-1]=='N' || o[x-1]=='Z')
            {
                printf("RF");
            }else if(o[x-1]=='S')
            {
                printf("RRRF");
            }else if(o[x-1]=='E')
            {
                printf("F");
            }else if(o[x-1]=='W')
            {
                printf("RRF");
            }
        }
        else if(o[x]=='W')
        {
            if(o[x-1]=='N' || o[x-1]=='Z')
            {
                printf("RRRF");
            }else if(o[x-1]=='S')
            {
                printf("RF");
            }else if(o[x-1]=='E')
            {
                printf("RRF");
            }else if(o[x-1]=='W')
            {
                printf("F");
            }
        }
        else if(o[x]=='S')
        {
            if(o[x-1]=='N' || o[x-1]=='Z')
            {
                printf("RRF");
            }else if(o[x-1]=='S')
            {
                printf("F");
            }else if(o[x-1]=='E')
            {
                printf("RF");
            }else if(o[x-1]=='W')
            {
                printf("RRRF");
            }
        }
        else if(o[x]=='Z')
        {
            printf("Z");
        }
    }
    }
    return 0;
    }
