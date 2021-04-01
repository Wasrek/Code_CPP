/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010];
map<int,int> mp;
int main()
{
    int q,n,ans,l;
    scanf("%d",&q);
    for(int Q=1;Q<=q;Q++){
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            mp[a[i]]=i;
        }
        for(int i=1;i<n;i++){
            ans+=mp[i]-(i-1);// 8-3+1=6
            // printf("%d\n",mp[i]);
            l=mp[i];
            for(int j=i;j<=i+(l-i)/2;j++){// 3 -> 3+(8-3)/2=5
                // printf("%d %d\n",j,(i+l)-j);
                swap(a[j],a[(i+l)-j]);
                mp[a[j]]=j;
                mp[a[(i+l)-j]]=(i+l)-j;
            }
        }
        printf("Case #%d: %d\n",Q,ans);
    }
    return 0;
}
// 3 5 2 1 4  4   1 2 5 3 4  1    1 2 3 5 4   2   1 2 3 4 5  2