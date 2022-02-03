/*
    TASK:robot line up
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int a[200100],b[200100],c[400100],si[200100],m[400100];
long long cnt=0;
void ms(int l,int r){
    if(l>=r) return;
    int mid=(l+r)/2;
    ms(l,mid);
    ms(mid+1,r);
    int i=l,j=mid+1,now=l;
    while(i<=mid && j<=r){
        if(c[i]>=c[j]){
            m[now++]=c[i];
            i++;
        }else{
            m[now++]=c[j];
            j++;
            cnt+=(mid-i+1);
        }
    }
    while(i<=mid){
        m[now++]=c[i];
        i++;
    }
    while(j<=r){
        m[now++]=c[j];
        j++;
    }
    for(int i=l;i<=r;i++){
        c[i]=m[i];
    }
    return ;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        c[i]=a[i];
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
    }
    sort(b+1,b+1+m);
    sort(c+1,c+1+n);
    int now=upper_bound(b+1,b+1+m,c[(int)ceil((double)n/2)])-b;
    int idx=0;
    for(int i=1;i<now;i++){
        c[++idx]=b[i];
    }
    for(int i=1;i<=n;i++){
        c[++idx]=a[i];
    }
    for(int i=now;i<=m;i++){
        c[++idx]=b[i];
    }
    // for(int i=1;i<=idx;i++){
    //     printf("%d ",c[i]);
    // }
    ms(1,idx);
    printf("%lld\n",cnt);
    return 0;
}