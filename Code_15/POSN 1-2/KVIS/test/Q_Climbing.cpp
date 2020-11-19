/*
    TASK:Q_Climbing
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,c,Max=0,l=1,ch;
    scanf("%d",&n);
    scanf("%d %d %d",&a,&b,&c);
    while(n--)
    {
        if(l==1)
        {
            if(b>a && c>a){
                ch=min(c-a,b-a);
            }else
            if(b>a){
                ch=b-a;
            }else
            if(c>a){
                ch=c-a;
            }
            a+=(2*ch),l=2;
        }else
        if(l==2)
        {
            if(c>b && a>b){
                ch=min(c-b,a-b);
            }else
            if(c>b){
                ch=c-b;
            }else
            if(a>b){
                ch=a-b;
            }
            b+=(2*ch),l=3;
        }else
        if(l==3)
        {
            if(b>c && a>c){
                ch=min(a-c,b-c);
            }else
            if(b>c){
                ch=b-c;
            }else
            if(a>c){
                ch=a-c;
            }
            c+=(2*ch),l=1;
        }
        // printf("\n-%d-\n%d\n%d\n%d\n",n,a,b,c);
    }
    printf("%d\n%d\n%d\n",a,b,c);

    return 0;
}
