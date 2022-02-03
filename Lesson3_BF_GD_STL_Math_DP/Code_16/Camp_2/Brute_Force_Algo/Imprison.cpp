/*
    TASK:Imprison
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int a,b;
};
A p[15];
int cnt[15];
int main()
{
    int n,m,pp,now,mi;
    scanf("%d %d %d",&n,&m,&pp);
    for(int i=1;i<=pp;i++){
        scanf("%d %d",&p[i].a,&p[i].b);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            mi=1e9;
            for(int k=1;k<=pp;k++){
                if(abs(p[k].a-i)+abs(p[k].b-j)<mi){
                    now=k;
                    mi=abs(p[k].a-i)+abs(p[k].b-j);
                }
            }
            cnt[now]++;
        }
    }
    for(int i=1;i<=pp;i++){
        printf("%d\n",cnt[i]);
    }
    return 0;
}