/*
    TASK:D-Cubes
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[200010];
vector<int> v[100005];
int main()
{
    int n,m,k,l,r,i,ma=0;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        v[a[i]].push_back(i);
    }
    for(i=1;i<=m;i++){
        l=0;r=0;
        if(v[i].size()==0)  continue;
        while(r<=(v[i].size()-1) && l<=r){
            if(v[i][r]-v[i][l]+1-(r-l+1)<=k){
                ma=max(ma,r-l+1);
                r++;
            }else{
                l++;
            }
        }
    }
    printf("%d",ma);
    return 0;
}
