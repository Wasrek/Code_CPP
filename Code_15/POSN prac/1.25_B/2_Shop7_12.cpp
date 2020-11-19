/*
    Prac
    TASK:Shop7_12
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int n[10200];
int main()
{
    int a,b,k,l,h;
    scanf("%d %d %d",&a,&b,&k);
    n[0]=1;
    if(a<b){l=a;}else{l=b;}
    int i;
    for(i=l;i<=10000;i++){
        if(i>=a && n[i-a]==1)n[i]=1;
        if(i>=b && n[i-b]==1)n[i]=1;
    }
    while(k--)
    {
        scanf("%d",&h);
        if(h<l){printf("%d\n",l);continue;}
        for(i=l;i<=10000;i++){
        if(n[i])
        if(i>=h){printf("%d\n",i);break;}
    }
    }
}
