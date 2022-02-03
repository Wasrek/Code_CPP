/*
    TASK:Bomb
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y,i;
    bool operator <(const A & o) const{
        if(x!=o.x)return x>o.x;
        return y>o.y;
    }
}
A a[1000100];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i].x,&a[i].y);
        a[i].i=i;
    }
    sort(a+1,a+1+n);
    
    return 0;
}