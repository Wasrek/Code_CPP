/*
    TASK:TOI8_sport
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int ans[110];
void play(int k,int wi,int lo, int st){
    if(wi==k || lo==k){
        for(int i=0;i<st;i++){
            printf((ans[i]==1)?"W ":"L ");   
        }
        printf("\n");
        return ;
    }
    ans[st]=1;
    play(k,wi+1,lo,st+1);
    ans[st]=2;
    play(k,wi,lo+1,st+1);
}
int main()
{
    int k,a,b;
    scanf("%d %d %d",&k,&a,&b);
    play(k,a,b,0);
    return 0;
}