/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    double a,b;
    bool operator<(const A & o) const{
        if(b!=o.b) return b<o.b;
        return a<o.a;
    }
};
A a[100100];
double fw[100100],fw1[100100];
void upd(int k,double v){
    for(int i=k;i<=100100;i+=(i&-i)) fw[i]+=v;
}
void upd1(int k){
    for(int i=k;i<=100100;i+=(i&-i)) fw1[i]++;
}
double que(int k){
    double now=0;
    for(int i=k;i>0;i-=(i&-i)) now+=fw[i];
    return now; 
}
double que1(int k){
    int now=0;
    for(int i=k;i>0;i-=(i&-i)) now+=fw1[i];
    return now; 
}
int main()
{
    int n;
    double ans=0,ch;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf %lf",&a[i].a,&a[i].b);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        ch=que1(100100)-que1(a[i].a);
        if(ch)ans+=(double)(ch*a[i].a)+(double)((que(100100)-que(a[i].a)));
        upd(a[i].a,a[i].a);
        upd1(a[i].a);
    }
    printf("%.0lf\n",ans);
    return 0;
}