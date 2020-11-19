/*
    TASK:48_Tri Inversion
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
pair<int,int> le[100005],temp[100005],ri[100005];
long long counr[100005],counl[100005];
int b[100005];
long long ans;
void mergel(int st,int en){
    if(st==en)return ;
    int mid=(st+en)/2;
    mergel(st,mid);
    mergel(mid+1,en);
    int i=st,j=mid+1,k=st;
    while(i<=mid && j<=en){
        if(le[i].first<=le[j].first)
            temp[k++]=le[i++];
        else{
             counl[le[j].second]+=mid-i+1;
             temp[k++]=le[j++];
        }
    }
    while(i<=mid)temp[k++]=le[i++];
    while(j<=en)temp[k++]=le[j++];
    for(i=st;i<=en;i++)
        le[i]=temp[i];
}
void merger(int st,int en){
    if(st==en)return ;
    int mid=(st+en)/2;
    merger(st,mid);
    merger(mid+1,en);
    int i=st,j=mid+1,k=st;
    while(i<=mid && j<=en){
        if(ri[i].first<=ri[j].first)
            temp[k++]=ri[i++];
        else{
             counr[ri[j].second]+=mid-i+1;
             temp[k++]=ri[j++];
        }
    }
    while(i<=mid)temp[k++]=ri[i++];
    while(j<=en)temp[k++]=ri[j++];
    for(i=st;i<=en;i++)
        ri[i]=temp[i];
}
int main(){
    int q,n,o,i;
    scanf("%d",&q);
    while(q--){
        ans=0;
        scanf("%d",&n);
        for(i=n-1;i>=0;i--){
            scanf("%d",&b[i]);
            ri[i]={b[i]*-1,n-i-1};
            le[n-i-1]={b[i],n-i-1};
        }
        memset(counr,0,sizeof counr);
        memset(counl,0,sizeof counl);
        merger(0,n-1);
        mergel(0,n-1);
        for(i=0;i<n;i++){
            ans+=(counr[i]*counl[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
3
4
9 7 5 3
4
1 4 3 2
3
2 3 1
*/
