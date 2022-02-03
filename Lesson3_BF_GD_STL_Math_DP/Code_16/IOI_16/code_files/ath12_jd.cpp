/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int a,b;
    bool operator <(const A & o) const{
        if(a!=o.a) return a<o.a;
        return b<o.b;
    }
};
A a[100100];
int b[100100];
int main()
{
    int n,now=0,idx;
    while(1){
        scanf("%d",&n);
        if(n==0) return 0;
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a[i].a,&a[i].b);
        }
        sort(a+1,a+1+n);
        now=0;
        for(int i=1;i<=n;i++){
            idx=upper_bound(b,b+now,a[i].b)-b;
            if(now==idx) now++;
            b[idx]=a[i].b;
        }
        memset(b,0,n+1);
        printf("%d\n",now);
    }
    return 0;
}