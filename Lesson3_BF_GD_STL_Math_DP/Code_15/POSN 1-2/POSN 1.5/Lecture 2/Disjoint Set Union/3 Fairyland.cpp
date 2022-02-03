/*
    TASK:Fairy land
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int p[100100];
int fin(int i){
   if(p[i]==i) return i;
   return p[i]=fin(p[i]);
}
int main()
{
    int n,m,i,r,s,q;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) p[i]=i;
    while(m--){
        scanf("%d %d",&r,&s);
        p[fin(r)]=fin(s);
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&r,&s);
        printf((fin(r)==fin(s))?"YES\n":"NO\n");
    }

    return 0;
}
