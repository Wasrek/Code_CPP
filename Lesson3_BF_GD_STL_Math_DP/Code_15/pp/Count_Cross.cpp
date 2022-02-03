/*
    TASK:Count_Cross
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100],ans=0,cou[100100];
void merges(int l,int r){
    if(l==r) return ;
    int mid=(l+r)/2;
    merges(l,mid);
    merges(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid && j<=r){
        if(a[i]<=a[j]){
            b[k++]=a[i++];
        }else {
        //cou[j]+=mid-i+1;
        ans+=mid-i+1;
        b[k++]=a[j++];
        }
    }
    while(i<=mid)b[k++]=a[i++];
    while(j<=r) b[k++]=a[j++];
    for(i=l;i<=r;i++){
        a[i]=b[i];
    }
}
int main(){
    int q,n,i;
    scanf("%d",&q);
    while(q--){
        ans=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        merges(0,n-1);
        //for(i=0;i<n;i++){
        //    printf("%d ",cou[i]);
        //}
        printf("%d\n",ans);
    }
    return 0;
}
