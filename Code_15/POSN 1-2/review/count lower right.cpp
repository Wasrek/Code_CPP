/*
    TASK:count lower right
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[100005],temp[100005];
long long coun[100005];
int b[100005];
long long ans;
void merges(int st,int en){
    if(st==en)return ;
    int mid=(st+en)/2;
    merges(st,mid);
    merges(mid+1,en);
    int i=st,j=mid+1,k=st;
    while(i<=mid && j<=en){
        if(a[i].first<=a[j].first)
            temp[k++]=a[i++];
        else{
             coun[a[j].second]+=mid-i+1;
             temp[k++]=a[j++];
        }
    }
    while(i<=mid)temp[k++]=a[i++];
    while(j<=en)temp[k++]=a[j++];
    for(i=st;i<=en;i++)
        a[i]=temp[i];
}
int main(){
    int q,n,o,i;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=n-1;i>=0;i--){
            scanf("%d",&o);
            b[i]=o*-1;
            a[i]={b[i],n-i-1};
        }
        memset(coun,0,sizeof coun);
        merges(0,n-1);
        for(i=0;i<n;i++){
            printf("%d ",coun[i]);
        }
        printf("\n");
    }
    return 0;
}
