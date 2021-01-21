#include<bits/stdc++.h>
using namespace std;
map<long long ,long long > mapp;
pair <long long ,long long > fire[1100];
pair <long long ,long long > tiger[1100];
long long t[1100];
long long dist(pair<long long ,long long > a,pair<long long ,long long > b){
    return abs((a.first-b.first))+abs(a.second-b.second);
}
int main(){
    long long n,m,maxx=-1e9;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld %lld",&fire[i].first,&fire[i].second);
    }
    for(long long i=1;i<=m;i++){
        t[i]=2e9;
        scanf("%lld %lld",&tiger[i].first,&tiger[i].second);
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            t[j] = min(dist(fire[i],tiger[j]),t[j]);
        }
    }
    for(long long j=1;j<=m;j++){
        mapp[t[j]]++;
        maxx = max(mapp[t[j]],maxx);
    }
    printf("%lld\n",maxx);
    return 0;
}
