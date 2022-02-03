/*
    TASK:Time_Arrange
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int s,f;
    bool operator <(const A&o)const{
    if(f!=o.f)return f<o.f;
    else return s<o.s;
    }
};
A a[100100];
int main(){
    int n,i,cou=0,last=-1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&a[i].s,&a[i].f);
    }
    sort(a+1,a+1+n);
    for(i=1;i<=n;i++){
        if(last<=a[i].s)cou++,last=a[i].f;
    }
    printf("%d",cou);
}
/*
7
0 2
3 6
7 10
0 4
5 7
8 10
6 8
*/
