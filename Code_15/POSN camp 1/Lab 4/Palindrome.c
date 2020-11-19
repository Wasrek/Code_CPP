/*
    TASK:Palindrome
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char a[60000],b[60000];
int main()
{
    int n,len,i,j,k,ch;
    scanf("%d\n",&n);
    for(i=0; i<n; i++)
    {
        gets(a);
        len = strlen(a);
        for(j=0,k=0; j<len; j++)
        {
            if(isalnum(a[j]))
            {
                b[k++]=a[j];
            }
        }
            len = k,ch=1;
            for(j=0; j<len; j++)
            {
                b[j]=tolower(b[j]);
            }
            for(j=0; j<len/2; j++)
            {
                if(b[j]!=b[len-1-j])
                {
                    ch=0;
                    break;
                }
            }
            if(ch)
            {
                for(j=0; j<len/4; j++)
                {
                    if(b[j]!=b[len/2-1-j])
                    {
                        ch=0;
                        break;
                    }
                }
                if(ch)
                {
                    printf("Double Palindrome\n");
                }
                else
                {
                    printf("Palindrome\n");
                }
            }
            else
                printf("No\n");

    }
    return 0;
}
