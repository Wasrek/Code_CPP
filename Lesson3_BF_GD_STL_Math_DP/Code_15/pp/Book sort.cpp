/*
    TASK:Book sort
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
pair<string,int> a[30100],b[30100];
int cou[30100];
char c[35];
void merges(int l,int r){
    if(l==r) return ;
    int mid=(l+r)/2;
    merges(l,mid);
    merges(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid && j<=r){
        if(a[i].first<=a[j].first){
            b[k++]=a[i++];
        }else{
            cou[a[j].second]+=mid-i+1;
            b[k++]=a[j++];
        }
    }
    while(i<=mid)b[k++]=a[i++];
    while(j<=r)b[k++]=a[j++];
    for(i=l;i<=r;i++){
        a[i]=b[i];
    }
}
int main(){
    int i,n,len,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %s",c);
        len=strlen(c);
        for(j=0;j<len;j++){
            if(c[j]>'Z'){
                c[j]-=('z'-'Z');
            }
        }
        a[i].first=c;
        a[i].second=i;
    }
    merges(0,n-1);
    for(i=0;i<n;i++){
        printf("%d ",i-cou[i]+1);
    }
}
