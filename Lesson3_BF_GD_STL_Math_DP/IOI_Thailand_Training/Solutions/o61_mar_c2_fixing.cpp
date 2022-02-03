/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010];
vector<int> dis;
int main()
{
    int n,m,k,now;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
    }
    int cnt=0;
    for(int i=2;i<=m;i++){
        if(a[i]-a[i-1]!=1) dis.push_back(a[i]-a[i-1]-1),cnt++;
    }
    cnt++;
    if(cnt<=k){ printf("0\n");return 0;}
    int l=0,r=n,mid,la,sum=0;
    sort(dis.begin(),dis.end());
    for(int i=0;i<cnt-k;i++){
        sum+=dis[i];
    }
    printf("%d\n",sum);
    return 0;
}