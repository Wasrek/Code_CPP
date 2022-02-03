/*
    TASK:RT_WhileQueued
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j;
};
A a[100100],b[100100];
long long cnt,c[100100];
int ch;
void ms(int l,int r){
    if(l==r)return ;
    int mid=(l+r)/2,ll;
    ms(l,mid);
    ms(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid && j<=r){
        if(a[i].i <= a[j].i){
            b[k++]=a[i++];
        }else{
        cnt+=mid-i+1;
        for(ll=i;ll<=mid;ll++){
        c[a[ll].j]++;if(c[a[ll].j]>2)ch=1;
        }
        //printf("%d %d",a[i].j,mid-i+1);
        //printf("\n");
        b[k++]=a[j++];
        }
    }
    while(i<=mid)b[k++]=a[i++];
    while(j<=r)b[k++]=a[j++];
    for(i=l;i<=r;i++)a[i]=b[i];
    return ;
}
int main(){
    int t,n,i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i],i);
            a[i].j=i;
        }
        ch=0;
        cnt=0;
        memset(c,0,sizeof c);
        ms(1,n);
        if(ch){printf("CHEAT\n");}
        else
        printf("%lld\n",cnt);
        //for(i=1;i<=n;i++)printf("%d ",c[i]);
        //printf("\n");
    }
}
/*
2
5
2 1 5 3 4
5
2 5 1 3 4
*/
