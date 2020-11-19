/*
    TASK:drops
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main(){
    int h,l,n,maxx=0,now;
    scanf("%d %d %d",&h,&l,&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&now);
        if(now<l || now>(h+l))continue;
        mp[now]++;
        if(mp[now]>maxx)maxx=mp[now];
    }
    printf("%d\n",maxx);
}