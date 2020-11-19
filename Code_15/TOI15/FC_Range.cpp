/*
    TASK:FC_Range
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
set <long long> s;
set <long long> :: iterator it;
pair <long long,long long> a[300005],b[300005];
int main(){
    long long n,i,l,r,ma=0,mi=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i].first);
        b[i].first=a[i].first*-1;
        a[i].second=b[i].second=i;
    }
    sort(a+1,a+1+n);
    s.insert(0);
    s.insert(n+1);
    for(i=n;i>=1;i--){
        it = s.upper_bound(a[i].second);
        l=*it-a[i].second;
        it--;
        r=a[i].second-*it;
        s.insert(a[i].second);
        ma+=l*r*a[i].first;
    }
    s.clear();
    sort(b+1,b+1+n);
    s.insert(0);
    s.insert(n+1);
    for(i=n;i>=1;i--){
        it = s.upper_bound(b[i].second);
        l=*it-b[i].second;
        it--;
        r=b[i].second-*it;
        s.insert(b[i].second);
        mi+=l*r*b[i].first*-1;
    }
    printf("%lld\n",ma-mi);
}
