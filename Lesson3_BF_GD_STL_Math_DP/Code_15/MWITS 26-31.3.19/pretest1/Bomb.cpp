/*
    TASK:Bomb
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int first,second;
    bool operator<(const A&o)const{
    if(first!=o.first)return first>o.first;
    return second<o.second;
    }
};
struct B{
    int first,second;
    bool operator<(const B&o)const{
    if(first!=o.first)return first>o.first;
    return second>o.second;
    }
};
A a[1000100];
priority_queue<B> h;
int mark[1000100];
int main(){
    int n,i,last,lasti,cou=0,aa,bb;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&a[i].first,&a[i].second);
    }
    sort(a+1,a+1+n);
    last=a[1].second;
    for(i=1;i<=n;i++){
        if(a[i].second<last)mark[i]=1;else{
            h.push({a[i].first,a[i].second});
        }
        if(a[i].second>last){
            last=a[i].second;
        }
    }
    while(!h.empty()){
        aa=h.top().first;bb=h.top().second;
        h.pop();
        printf("%d %d\n",aa,bb);
    }
}
/*
5
9 1
8 2
7 3
6 4
5 5
*/
