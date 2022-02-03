/*
    TASK:Pillar TCP
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],u[100010],d[100010],db[100010],ub[100010];
int main()
{
    int q,n;
    int ma,st;
    scanf("%d",&q);
    while(q--){
        ma=0;
        scanf("%d",&n);
        u[n+1]=d[n+1]=ub[n+1],db[n+1]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if((a[i]-a[i-1])==1 || (a[i]-a[i-1])==2){u[i]=u[i-1]+1;}else{u[i]=1;}
            if((a[i-1]-a[i])==1 || (a[i-1]-a[i])==2){d[i]=d[i-1]+1;}else{d[i]=1;}
        }
        db[n]=ub[n]=1;
        for(int i=n-1;i>=1;i--){
            if((a[i]-a[i+1])==1 || (a[i]-a[i+1])==2){db[i]=db[i+1]+1;}else{db[i]=1;}
            if((a[i+1]-a[i])==1 || (a[i+1]-a[i])==2){ub[i]=ub[i+1]+1;}else{ub[i]=1;}
        }
        // for(int i=1;i<=n;i++){
        //     printf("%d ",u[i]);
        // }
        // printf("\n");
        // for(int i=1;i<=n;i++){
        //     printf("%d ",d[i]);
        // }
        // printf("\n");
        // for(int i=1;i<=n;i++){
        //     printf("%d ",db[i]);
        // }
        // printf("\n");
        // for(int i=1;i<=n;i++){
        //     printf("%d ",ub[i]);
        // }
        // printf("\n");
        int now=ma;
        for(int i=1;i<=n;i++){
            now=ma;
            ma=max(max(d[i],max(u[i],max(ub[i],db[i])))+1,ma);
            if(a[i+1]-a[i-1]<=4 && a[i+1]-a[i-1]>=2){
                ma=max(ma,u[i-1]+ub[i+1]+1);
            }
            if(a[i-1]-a[i+1]<=4 && a[i-1]-a[i+1]>=2){
                ma=max(ma,d[i-1]+db[i+1]+1);
            }
            if(ma!=now)st=i;
        }
        printf("%d %d\n",ma,st-1);
    }
    return 0;
}