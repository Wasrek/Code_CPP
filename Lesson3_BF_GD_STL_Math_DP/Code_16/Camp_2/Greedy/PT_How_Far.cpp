/*
    TASK:PT_How Far
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,v;
    bool operator <(const A & o) const{
        if(v!=o.v)return v<o.v;
        else return i>o.i;
    }
};
A a[1000010];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].v);
        a[i].i=i;
    }
    sort(a+1,a+1+n);
    int ma=0;
    for(int i=1;i<=n;i++){
        ma=max(ma,abs(a[i].i-i));
        if(a[i+1].v!=a[i].v){
            printf("%d %d\n",a[i].v,ma);
            ma=0;
        }
    }
    return 0;
}