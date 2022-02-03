/*
    TASK:CAT Codes
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
#define hashsize 1000003
int hashh[hashsize],mark[hashsize],num[hashsize];
char d[1000100];
int main(){
    int k,m,h,now,i,sum,q,j,ch=0,l,kk;
    scanf("%d %d",&k,&m);
    for(i=1;i<=k;i++){
        sum=0;
    scanf(" %s",d);
    for(l=0;l<m;l++){
        sum<<=1;
        sum+=d[l];
    }
    h=sum;
    h %= hashsize;
    now = 1;
    while(hashh[h]!=0){
        h+=now;
        now<<=1;
        h%=hashsize;
    }
    hashh[h]=i;
    num[i]=sum;
    }
    scanf("%d",&q);
    while(q--){
     ch=0;
    scanf("%d",&kk);
    scanf(" %s",d);
    if(kk<m){printf("OK");continue;}
    sum=0,j=0;
    for(i=0;i<m;i++){
        sum<<=1;
        sum+=d[i];
    }
    while(j+m<=kk){
    h=sum;
    h %= hashsize;
    now=1;
    while(hashh[h]!=0){
        if(num[hashh[h]]==sum){
            mark[hashh[h]]=1;
            ch=1;
            break;
        }
        h+=now;
        now<<=1;
        h%=hashsize;
    }
    //printf("%d\n",sum);
    sum-=(d[j]<<(m-1));
    sum<<=1;
    sum+=d[j+m];
    //printf("%d\n",sum);
    j++;
    }
    if(ch==0){
        printf("OK");
    }else{
        for(l=1;l<=k;l++){
            if(mark[l])printf("%d ",l);
        }
    }
    printf("\n");
    memset(mark,0,sizeof mark);
    }
    return 0;
}
