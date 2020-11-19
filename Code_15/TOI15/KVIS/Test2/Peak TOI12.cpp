/*
    TASK:Peak TOI12
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<long long>ans,ans1,h;
long long a[5000100];
int main(){
    long long n,k,kk,i,now=-1,ii,cou=0;
    scanf("%lld %lld",&n,&k);
    kk=k;
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(i=1;i<=n;i++){
        if(a[i]>a[i-1] && a[i]>a[i+1])h.push(a[i]);
    }
    if(h.empty()){printf("-1\n");return 0;}
    while(!h.empty() && k--){
            ii=h.top();
            ans.push(ii);
            ans1.push(ii*-1);
            cou++;
            //printf("%lld\n",h.top().v);
            now = h.top();
            h.pop();
            while(!h.empty() && h.top()==now)h.pop();
    }
    if(cou==kk){
    while(!ans.empty()){
        i=ans.top();
        ans.pop();
        printf("%lld\n",i);
    }
    }else{
    while(!ans1.empty()){
        i=ans1.top()*-1;
        ans1.pop();
        printf("%lld\n",i);
    }
    }
    return 0;
}
/*
10
2
40
10
90
5
45
50
65
90
35
45

10
3
45
20
20
5
45
50
65
90
35
45

7
3
4
6
6
6
8
9
9
*/
