/*
    TASK:RT_God TOI1
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100],fw[100100];
void update(int n){
    for(int i=n;i<=100000;i+=(i&-i)){
        fw[i]++;
    }
}
int query(int n){
    int sum=0;
    for(int i=n;i>0;i-=(i&-i)){
        sum+=fw[i];
    }
    return sum;
}
unordered_map<int,int> mp,re;
int main(){
    int n,m,i,l,r;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    int cou=0;
    for(i=1;i<=n;i++){
        if(b[i]==b[i+1]) continue;
        mp[b[i]]=++cou;
        re[cou]=b[i];
    }
//    for(i=1;i<=n;i++){
//        printf("%d ",mp[a[i]]);
//    }
    l=0,r=1000000000;
    int mid,now;
    while(l<r){
        mid=(l+r)/2;
        memset(fw,0,sizeof fw);
        cou=0;
        for(i=1;i<=n;i++){
            if(a[i]<=mid)b[++cou]=mp[a[i]];
        }
//        for(i=1;i<=cou;i++){
//            update(b[i]+1);
//        }
        now=0;
        for(i=1;i<=cou;i++){
            now+=(i-1-query(b[i]));
            update(b[i]+1);
            //printf("%d %d\n",mid,query(b[i]));
        }
        if(now>=m) r=mid;
        else l=mid+1;
    }
    printf("%d\n",l);
}
/*
5 1
4
6
11
15
10
*/
