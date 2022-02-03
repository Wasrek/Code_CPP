/*
    TASK:Swift Day I
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int a,b;
    bool operator<(const A & o)const {
        if(a!=o.a)return a<o.a;
        else return b>o.b;
    }
};
A a[100010];
int main(){
    int n,m,i,ma,ch;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d %d",&a[i].a,&a[i].b);
    }
    sort(a+1,a+1+n);
    int last=a[1].b,cou=1;
    for(i=2;i<=n;){
        ma=0;
        if(last==m){printf("%d\n",cou);return 0;}
        while(a[i].a<=last+1 && i<=n){
            ma=max(ma,a[i].b);
            i++;
        }
        cou++;
        last=ma;
        if(last==m){printf("%d\n",cou);return 0;}
    }
}
