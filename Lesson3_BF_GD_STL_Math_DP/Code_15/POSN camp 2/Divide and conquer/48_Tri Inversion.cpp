/*
    TASK:48_Tri Inversion
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
pair<int,int> ri[100100],le[100100],temp[100100];
long long cour[100100],coul[100100];
int b[100100];
long long ans;
void merger(int st,int en){
    if(st==en)return ;
    int mid=(st+en)/2;
    merger(st,mid);
    merger(mid+1,en);
    int i=st,j=mid+1,k=st;
    while(i<=mid && j<=en){
        if(ri[i].first <= ri[j].first){
            temp[k++]=ri[i++];
        }else{
        cour[ri[j].second]+=mid-i+1;
        temp[k++]=ri[j++];
        }
    }
    while(i<=mid)temp[k++]=ri[i++];
    while(j<=en)temp[k++]=ri[j++];
    for(i=st;i<=en;i++)ri[i]=temp[i];
}
void mergel(int st,int en){
    if(st==en)return ;
    int mid=(st+en)/2;
    mergel(st,mid);
    mergel(mid+1,en);
    int i=st,j=mid+1,k=st;
    while(i<=mid && j<=en){
        if(le[i].first <= le[j].first){
            temp[k++]=le[i++];
        }else{
        coul[le[j].second]+=mid-i+1;
        temp[k++]=le[j++];
        }
    }
    while(i<=mid)temp[k++]=le[i++];
    while(j<=en)temp[k++]=le[j++];
    for(i=st;i<=en;i++)le[i]=temp[i];
}
int main(){
    int q,n,now,i;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=n-1;i>=0;i--){
            scanf("%d",&b[i]);
            ri[i]={b[i]*-1,n-i-1};
            le[n-i-1]={b[i],n-i-1};
        }
        memset(cour,0,sizeof cour);
        memset(coul,0,sizeof coul);
        merger(0,n-1);
        mergel(0,n-1);
        ans=0;
        for(i=0;i<n;i++){
            ans+=cour[i]*coul[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
