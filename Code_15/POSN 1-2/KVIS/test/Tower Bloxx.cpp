/*
    TASK:Tower Bloxx
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int d[100010];
int main()
{
    int i;
    d[1]=1;
    d[0]=0;
    d[2]=2;
    for(i=3;i<=100000;i++){
        d[i]=(d[i-2]+d[i-1])%10000019;
    }
    int q,a;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&a);
        printf("%d\n",d[a]);
    }
}
