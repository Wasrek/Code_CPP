/*
    TASK:Special Number
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char a[10];
int main()
{
    int i,len,j,sum,num;
    for(i=0;i<5;i++){
    scanf("%s",a);
    len=strlen(a);
    sum=0;
    for(j=0;j<len;j++)
    {
       sum+=pow(a[j]-'0',j+1);//ascii 0 48
    }
    num=atoi(a);//array to int
    if(sum==num){printf("Y");}else{printf("N");}
    }

    return 0;
}
