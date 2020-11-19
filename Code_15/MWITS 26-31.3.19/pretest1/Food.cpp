/*
    TASK:Food
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[10],b[10],c[10],n;
void permu(int now,int state){
    int i;
    //printf("-%d- %d ",state,n);
    if(state==n-1){
        //printf("-%d-",state);
        printf("%d ",now);
        for(i=0;i<n-1;i++){
            printf("%d ",b[i]);
        }
        printf("\n");
        return ;
    }
    for(i=1;i<=n;i++){
        if(a[i]!=1 && i!=now){
            a[i]=1;
            b[state]=i;
            permu(now,state+1);
            a[i]=0;
        }
    }
}
int main(){
    int m,j,i;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d",&j);
        c[j]=1;
    }
    for(i=1;i<=n;i++){
        if(!c[i])
        permu(i,0);
        memset(a,0,sizeof a);
    }
    return 0;
}
