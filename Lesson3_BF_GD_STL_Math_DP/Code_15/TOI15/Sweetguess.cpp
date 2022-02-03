/*
    TASK:Sweetguess
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int c[15],mark[100100];
int main(){
    int q,i,t,n,m,ch,cou=0,sq,j,ch2;
    mark[2]=1;
    sq=sqrt(101000);
    for(i=3;i<=100000;i+=2)mark[i]=1;
    for(i=3;i<=sq;i+=2){
        if(mark[i]){
        for(j=i*i;j<=100000;j+=i)mark[j]=0;
        }
    }
    scanf("%d",&q);
    for(t=1;t<=q;t++){
        scanf("%d %d",&n,&m);
        ch=0,ch2=1;
        for(i=1;i<=m;i++){
            scanf("%d",&c[i]);
            if(mark[c[i]] && c[i]<n){ch=1;}
            if(c[i]==1)ch2=0;
        }
        printf("Case %d: ",t);
        if(n==2){printf("0\n");continue;}
        if(ch2){printf("1\n");continue;}
        cou=0;
        if(!ch){
            for(i=2;i<n;i++){
            if(mark[i])
            ++cou;
            }
            printf("%d\n",cou);
        }else{
        printf("can't guess\n");
        }
    }
}
