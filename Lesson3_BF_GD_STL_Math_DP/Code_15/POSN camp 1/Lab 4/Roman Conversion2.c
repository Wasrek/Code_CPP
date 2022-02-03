/*
    TASK:Palindrome
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
#include<string.h>
char a[500];
int main()
{
    int q,i,len,r,ans=0;
    scanf(" %d",&q);
    for(i=0; i<q; i++)
    {
        scanf(" %s",a);
        len=strlen(a);
        for(r=0; r<len; r++)
        {
            if(a[r]=='M')
            {
                ans+=1000;
            }
            else if(a[r]=='D')
            {
                ans+=500;
            }
            else if(a[r]=='C')
            {
                if(a[r+1]!='M' && a[r+1]!='D')
                {
                    ans+=100;
                }
                else if(a[r+1]=='M' || a[r+1]=='D')
                {
                    ans-=100;
                }
            }
            else if(a[r]=='L')
            {
                ans+=50;
            }
            else if(a[r]=='X')
            {
                if(a[r+1]!='C' && a[r+1]!='L')
                {
                    ans+=10;
                }
                else if(a[r+1]=='C' || a[r+1]=='L')
                {
                    ans-=10;
                }
            }
            else if(a[r]=='V')
            {
                ans+=5;
            }
            else if(a[r]=='I')
            {
                if(a[r+1]!='V' && a[r+1]!='X')
                {
                    ans+=1;
                }
                else if(a[r+1]=='V' || a[r+1]=='X')
                {
                    ans-=1;
                }
            }
        }
       printf("%d",ans);
        ans=0;

    }
    return 0;
}
