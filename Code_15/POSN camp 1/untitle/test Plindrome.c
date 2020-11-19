/*
    TASK:Palindrome
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
char s[60000],p[60000];
#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,len,x,num=0;
    scanf(" %d",&n);
    for(i=0;i<n;i++)
    {
       scanf(" %s",s);
       len=strlen(s);
       for(x=0;x<len;x++)
       {
          if((64>s[x]<91) || (96>s[x]<123) || (47>s[x]<58))
          {
             p[num]==s[x];
             num++;
          }
       }
       for(x=0;x<len;x++)
       {
          printf("%c",&s[x]);
       }
       for(x=0;x<len;x++)
       {
          printf("%c",&p[x]);
       }

    }

    return 0;
}
