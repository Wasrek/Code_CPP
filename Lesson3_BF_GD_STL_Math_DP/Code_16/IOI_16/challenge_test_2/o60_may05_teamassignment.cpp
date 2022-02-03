/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],gr[100100];
int main()
{
    int n,l,u,ll=0,rr=0,le,ch,p;
    scanf("%d %d %d",&n,&l,&u);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        rr=max(rr,a[i]);
    }
    if(ceil((double)(n%l)/(double)(n/l))>(u-l)){
       printf("-1\n");
       return 0; 
    }
    int now;
    while(ll<rr){
        int mid=(ll+rr+1)>>1;
        le=n%l;ch=1;
        if((l-u)<le){

        }
        // printf("%d %d",mid,le);
        int i=1;
        while(i<=n){
            // printf("%d\n",i);
            now=0;
            for(int j=0;j<p;j++){
                now=max(a[i+j],now);
            }
            i+=p;
            // printf("no %d\n",now);
            if(now>=mid) continue;
            for(int j=0;j<min(le,u-l);j++){
                now=max(a[i+j],now);
                if(now>=mid){
                    le-=(j+1);
                    i+=(j+1);
                    break;
                }
            }
            // printf("yes %d\n",now);
            if(now<mid){
                ch=0;
                break;
            }
        }
        if(ch){
            ll=mid;
        }else rr=mid-1;
    }
    printf("%d\n",ll);
    return 0;
}