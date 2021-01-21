/*
    TASK:delivery
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
map<int,int> mp,re;
int dis[20][20],k;
int dif(int a,int b){
    if(a>=(1<<k)+1 && b>=(1<<k)+1){
        a-=(1<<k);
        b-=(1<<k);
    }
    int dis=0;
    while(a!=b){
        if(a<b){
            b/=2;
        }else{
            a/=2;
        }
        dis++;
    }
    return dis;
}
int sam(int a,int b){
    if((a<(1<<k) && b<(1<<k)) || (a>(1<<k) && b>(1<<k)))return 1;
    return 0;
}
int chl(int a,int b){
    if(dis[mp[a]][mp[b]]!=1 && sam(a,b)==0)return dis[mp[a]][mp[b]];
    else if(dis[mp[a]][mp[b]]==1 && sam(a,b)==0){
        return 1;
    }else {
        return dif(a,b);
    }
}
int main()
{
    int l,q,a,b,cnt=0;
    scanf("%d %d %d",&k,&l,&q);
    for(int i=1;i<=l*2;i++){
        for(int j=1;j<=l*2;j++){
            if(i!=j)
            dis[i][j]=1e9;
        }
    }
    for(int i=1;i<=l;i++){
        scanf("%d %d",&a,&b);
        if(!mp[a])mp[a]=++cnt,re[cnt]=a;
        if(!mp[b])mp[b]=++cnt,re[cnt]=b;
        //printf("%d\n",cnt);
        dis[mp[a]][mp[b]]=dis[mp[b]][mp[a]]=1;
    }
    int nowji,nowki;
    for(int i=1;i<=cnt;i++){
        for(int j=1;j<=cnt;j++){
            for(int k=1;k<=cnt;k++){
                nowji=chl(re[i],re[j]);
                nowki=chl(re[k],re[i]);
                dis[j][k]=min(dis[j][k],nowji+nowki);
            }
        }
    }
    // for(int i=1;i<=cnt;i++){
    //     for(int j=1;j<=cnt;j++){
    //         printf("%d %d %d\n",re[i],re[j],dis[i][j]);
    //     }
    // }
    // printf("%d %d %d\n",re[1],re[3],dis[1][3]);
   int now,c;
   while(q--){
       scanf("%d %d",&a,&b);
       if(sam(a,b)){
           now=dif(a,b);
       }else now=2e9;
       //printf("%d\n",now);
       for(int i=1;i<=cnt;i++){
           for(int j=1;j<=cnt;j++){
               if(sam(a,re[i]) && sam(b,re[j])){
                   c=dif(a,re[i])+dif(b,re[j])+dis[i][j];
                   now=min(now,c);
               }
           }
       }
       printf("%d\n",now);
   }
    return 0;
}