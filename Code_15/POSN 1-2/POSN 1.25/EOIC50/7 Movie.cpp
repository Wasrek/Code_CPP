#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
PII a[6000];
int main()
{
    int n,i,st,en,ans1=0,ans2=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d",&a[i].first,&a[i].second);
    sort(a,a+n);
    st=a[0].first,en=a[0].second;
    for(i=1;i<n;i++){
        if(a[i].first <= en)
            en=max(en,a[i].second);
        else{
            ans1 = max(ans1, en-st);
            ans2 = max(ans2, a[i].first-en);
            st=a[i].first,en=a[i].second;
        }
    }
    ans1 = max(ans1, en-st);
    printf("%d\n%d\n",ans1,ans2);
}
