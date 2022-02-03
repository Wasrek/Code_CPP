/*
    TASK:Time Arrange
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int s,e;
    bool operator <(const A & o) const{
        if(e!=o.e) return e<o.e;
        return s<o.s;
    }
};
A a[100010];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i].s,&a[i].e);
    }
    int cnt=0,last=-1;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(last<=a[i].s) cnt++,last=a[i].e;
    }
    printf("%d\n",cnt);
    return 0;
}