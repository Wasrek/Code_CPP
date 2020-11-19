/*
    TASK:Pillar TCP
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int u[100100],ub[100100],d[100100],db[100100],f[100100];
int main()
{
    int q;
    scanf("%d",&q);
    while(q--){
        int n,i,x;
        scanf("%d",&n);
        f[n+1]=u[n+1]=ub[n+1]=d[n+1]=db[n+1]=0;
        for(i=1;i<=n;i++){
            scanf("%d",&f[i]);
            if((f[i]-f[i-1])==1 || (f[i]-f[i-1])==2){u[i]=u[i-1]+1;}else{u[i]=1;}
            if((f[i-1]-f[i])==1 || (f[i-1]-f[i])==2){d[i]=d[i-1]+1;}else{d[i]=1;}
        }
        ub[n]=1,db[n]=1;
        for(i=n-1;i>=1;i--){
            if((f[i]-f[i+1])==1 || (f[i]-f[i+1])==2){db[i]=db[i+1]+1;}else{db[i]=1;}
            if((f[i+1]-f[i])==1 || (f[i+1]-f[i])==2){ub[i]=ub[i+1]+1;}else{ub[i]=1;}
        }
        /*for(i=1;i<=n;i++){
            printf("%d ",u[i]);
        }printf("\n");
        for(i=1;i<=n;i++){
            printf("%d ",ub[i]);
        }printf("\n");
        for(i=1;i<=n;i++){
            printf("%d ",d[i]);
        }printf("\n");
        for(i=1;i<=n;i++){
            printf("%d ",db[i]);
        }printf("\n");*/
        int nowu,nowd,ai=1,Max=0,b;
        for(i=1;i<=n;i++){
            b=max(u[i-1],max(d[i-1],max(ub[i+1],db[i+1])))+1;
            if(Max<b)Max=b,ai=i;
            if(f[i+1]-f[i-1]<=4 && f[i+1]-f[i-1]>=2){
                nowu=u[i-1]+ub[i+1]+1;
                if(Max<nowu)Max=nowu,ai=i;
            }
            if(f[i-1]-f[i+1]<=4 && f[i-1]-f[i+1]>=2){
                nowd=d[i-1]+db[i+1]+1;
                if(Max<nowd)Max=nowd,ai=i;
            }
        }
        //if(Max!=0){
        printf("%d %d\n",Max,ai-1);
        //}else{printf("2 0\n");}
    }
    return 0;
}
/*
2
12
20 10 11 11 15 10 17 16 10 12 20 20

2
7
4 8 5 4 3 3 3
*/
