/*
    TASK:57_SantaPeatt
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
map<int,int> mp,re;
int a[100010],l[100010],r[100010],b[100010];
vector< int > ans;
int main()
{
    int n,m,now,u,v,k,sum;
    r[0]=1;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&now);
        mp[now]=i;
        re[i]=now;
        l[i]=i-1;
        r[i]=i+1;
        k=i;
    }
    r[n]=-1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    // now=r[0];
    // while(now!=-1){
    //     printf("%d\n",now);
    //     now=r[now];
    // }
    while(m--){
        scanf("%d %d",&u,&v);
        mp[u]=++k;
        re[k]=u;
        now=mp[v];
        // printf("%d %d %d\n",mp[u],re[k],now);
        r[l[now]]=k;
        l[k]=l[now];
        r[k]=now;
        l[now]=k;
        // printf("%d %d %d %d %d\n",k,l[k],r[k],r[l[k]],l[r[k]]);
        b[now]++;
        now=r[0];
        // while(1){
        // // printf("%d %d %d\n",l[now],now,r[now]);
        // now=r[now];
        // if(now==-1) break;
        // }
    }
    sum=0;
    now=r[0];
    int cnt=0;
    while(1){
        sum+=b[now];
        a[now]-=sum;
        if(a[now]>0 || sum==0 || now>n)ans.push_back(re[now]),cnt++;;
        now=r[now];
        if(now==-1)break;
    }
    printf("%d\n",cnt);
    for(auto x: ans){
        printf("%d ",x);
    }
    printf("\n");
    return 0;
}