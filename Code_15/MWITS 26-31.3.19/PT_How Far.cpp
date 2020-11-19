/*
    TASK:PT_How Far
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int n,i;
    bool operator <(const A&o) const{
        if(n!=o.n)return n<o.n;
        return i>o.i;
    }
};
A a[1000100];
int main(){
    int n,i,last,Max;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i].n);
        a[i].i=i;
    }
    sort(a+1,a+1+n);
    last=a[1].n,Max=0;
    for(i=1;i<=n;i++){
        if(a[i].n!=last)printf("%d %d\n",last,Max),Max=0,last=a[i].n;
        if(abs(a[i].i-i)>Max)Max=abs(a[i].i-i);
    }
    printf("%d %d\n",a[n].n,Max);
    return 0;
}
/*
12
4 3 2 1 5 1 2 1 3 6 5 4
*/
