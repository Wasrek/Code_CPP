/*
    TASK:Combination
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
#include<stdlib.h>
int a[15],b[15],n,r,k,cou=0;
void comb(int state,int last){
   int i;
   if(state==r){
    cou++;
    if(cou==k){
        for(i=0;i<r;i++)
        {
            printf("%d ",b[i]);
        }exit(0);
    }
   }
   for(i=last+1;i<=n;i++){
       if(a[i]!=1){
        a[i]=1;
        b[state]=i;
        printf(" -%d %d- ",state,b[state]);
        comb(state+1,i);
        a[i]=0;
       }
   }
}
int main(){
   scanf("%d %d %d",&n,&r,&k);
   comb(0,0);
   return 0;
}
