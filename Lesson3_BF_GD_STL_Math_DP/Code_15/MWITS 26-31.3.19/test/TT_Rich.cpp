/*
    TASK:TT_Rich
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100],r[1000100],l[1000100];
int main(){
    int n,i,ui,uj,mi,ma=0,ans=0,ii,ei,ej,maa;
    scanf("%d %d",&n,&a[1]);
    mi=a[1];ii=1;
    for(i=2;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]>mi && a[i]-mi>ma){
            ma=a[i]-mi;
        }else if(a[i]<mi){
            mi=a[i];
            ii=i;
        }
        l[i]=ma;
    }
    //for(i=1;i<=n;i++)printf("%d ",l[i]);
    ma=0;
    maa=a[n];ii=n;
    for(i=n-1;i>=1;i--){
        if(a[i]<maa && maa-a[i]>ma){
            ma=maa-a[i];
        }else if(a[i]>maa){
            maa=a[i];
            ii=i;
        }
        r[i]=ma;
    }
    //for(i=1;i<=n;i++)printf("%d ",r[i]);
    for(i=1;i<n;i++){
        ans=max(ans,l[i]+r[i+1]);
    }
    printf("%d\n",ans);
}
