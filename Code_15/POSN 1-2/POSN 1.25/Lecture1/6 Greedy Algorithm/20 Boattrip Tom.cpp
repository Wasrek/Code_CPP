/*
    TASK: Boattrip Tom
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
vector< PII > a;
int main()
{
    int n,m,x,y,i;
    long long sum=0;
    scanf("%d %d",&n,&m);
    while(n--){
        scanf("%d %d",&x,&y);
        if(x<y)continue;
        a.push_back(make_pair(y,x));
    }
    sort(a.begin(),a.end());
    x=0,y=0;
    for(i=0;i<a.size();i++){
        if(a[i].first>y){
            sum+=y-x;
            x=a[i].first;
            y=a[i].second;
        }
        else
            y=max(y,a[i].second);
    }
    sum+=y-x;
    printf("%lld",(long long)m+2*sum);
    return 0;
}
