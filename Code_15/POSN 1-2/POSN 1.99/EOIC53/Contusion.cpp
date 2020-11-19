/*
    TASK:Contusion
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int cou[20100];
int main(){
    int n,x,y,c,i,j,now,sum=0,Max=0;
    scanf("%d %d %d %d",&n,&x,&y,&c);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            now=abs(i-x)+abs(j-y);
            cou[now]++;
            Max=max(Max,now);
        }
    }
    for(i=0;i<=Max;i++){
        sum+=cou[i];
        if(sum>=c){printf("%d\n",i);return 0;}
    }
}
