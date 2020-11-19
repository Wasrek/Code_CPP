/*
    TASK:Nimble Timeline
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[500010],ans[500010],fw[1000020];
pair< pair< int,int > ,int > qu[500010];
void update(int i){
    if(!i)    return;
    while(i<=1000000)    ++fw[i],i+=i&-i;
}
int query(int i,int ans=0)
{
    while(i)  ans+=fw[i],i-=i&-i;
    return ans;
}
int main(){
    int n,q,i,x,y,ptr=0,l,r,mid;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=q;i++){
        scanf("%d %d",&x,&y);
        qu[i]={{x,y},i};
    }
    sort(qu+1,qu+1+q);
    for(i=1;i<=q;i++){
        while(ptr<=qu[i].first.first) update(a[ptr++]);
        l=1,r=1e6+2;
        while(l<r){
            mid=(l+r)/2;
            if(query(mid)<qu[i].first.second)   l=mid+1;
            else                                r=mid;
        }
        ans[qu[i].second]=l;
    }
    for(i=1;i<=q;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
