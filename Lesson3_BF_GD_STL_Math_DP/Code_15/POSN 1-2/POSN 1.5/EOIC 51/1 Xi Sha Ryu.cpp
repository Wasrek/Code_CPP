/*
    TASK:Xi Sha Ryu
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[100050];
int main()
{
    int len,i,j,ch=0;
    long long sum=0;
    scanf(" %s",&a);
    len=strlen(a);
    for(i=0;i<len;i++){
        if(a[i]=='0')
        ch=1;
        if(a[i]=='1')
        sum+=1;
        if(a[i]=='2')
        sum+=2;
        if(a[i]=='3')
        sum+=3;
        if(a[i]=='4')
        sum+=4;
        if(a[i]=='5')
        sum+=5;
        if(a[i]=='6')
        sum+=6;
        if(a[i]=='7')
        sum+=7;
        if(a[i]=='8')
        sum+=8;
        if(a[i]=='9')
        sum+=9;
    }
    if(ch==0)
    {printf("-1\n");return 0;}
    else{
        if(sum%3==0){
            sort(a,a+len);
            for(i=len-1;i>=0;i--)
            printf("%c",a[i]);
        }else{printf("-1\n");return 0;}
    }

    return 0;
}
