/*
    TASK:Array Practice
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
int s[2000];
int main()//เอาไว้นอกเมน เพราะจะเซ็?ค่าเป็น 0 ให้และเก็บได้เยอะกว่า
{
    int n,x,k,h=0;
    scanf("%d",&n);
    for(x=0;x<n;x++)
    {
        scanf("%d",&s[x]);
    }
    scanf("%d",&k);
    for(x=(n-1);x>=0;x--)
    {
        printf("%d ",s[x]);
        if(s[x]==k){h=h+1;}
    }
    printf("\n%d",h);
    return 0;
}
