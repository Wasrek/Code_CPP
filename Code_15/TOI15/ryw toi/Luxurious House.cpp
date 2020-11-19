/*
    TASK:Luxurious House
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue< int > h;
vector< int > g[100100];
int main(){
    int n,a,b,d=0,cnt=0;
    long long sum=0;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        d=max(d,a);
    }
    //printf("%d\n",d);
    while(d>0){
        for(auto x:g[d]){
            if(x>0)
            h.push(x);
        }
        if(!h.empty()){
        sum+=h.top();
        h.pop();
        cnt++;
        }
        d--;
    }
    printf("%lld\n%d\n",sum,cnt);
    return 0;
}
/*
4
1 17
5 15
2 10
2 11
*/
