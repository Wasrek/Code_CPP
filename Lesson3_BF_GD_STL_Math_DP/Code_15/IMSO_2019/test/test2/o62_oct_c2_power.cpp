/*
    TASK:o62_oct_c2_power
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
};
A a[20010];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
    }
    return 0;
}