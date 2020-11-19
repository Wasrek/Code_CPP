/*
    TASK:FC_Dominoes
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[100100];
int g[100100];
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&a[i].first,&a[i].second);
    }
    sort(a+1,a+n+1);
    int Max=0,ans=1,now=1,ru=a[1].first+a[1].second;
    char c;
    g[now]++;
    for(i=2;i<=n;i++){
        if(ru>a[i].first){
            g[now]++;
            ru=max(ru,a[i].first+a[i].second);
        }else{
            if(g[now]>Max){
                Max=g[now];
                ans=now;
                c='R';
            }
            now=i;
            ru=a[i].first+a[i].second;
            g[now]++;
        }
    }
    if(g[now]>Max){
        Max=g[now];
        ans=now;
        c='R';
    }
    memset(g,0,sizeof g);
    now=n,ru=a[n].first-a[n].second;
    g[now]++;
    for(i=n-1;i>=1;i--){
        if(ru<a[i].first){
            g[now]++;
            ru=min(ru,a[i].first-a[i].second);
        }else{
            if(g[now]>=Max){
                if(g[now]==Max && ans>now || g[now]>Max ){
                ans=now;
                c='L';
                }
                Max=g[now];
            }
            now=i;
            ru=a[i].first-a[i].second;
            g[now]++;
        }
    }
    if(g[now]>=Max){
            if(g[now]==Max && ans>now || g[now]>Max){
            ans=now;
            c='L';
        }
            Max=g[now];
    }
    printf("%d %c\n",ans,c);
}
/*
5
1 1
3 3
5 4
7 15
10 3
*/
