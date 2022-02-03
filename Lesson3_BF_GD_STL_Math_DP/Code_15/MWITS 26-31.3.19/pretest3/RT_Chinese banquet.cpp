/*
    TASK:RT_Chinese banquet
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int mark[1010];
char a[1010][20];
int main(){
    int n,m,i,last=0,now,k,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf(" %s",a[i]);
    }
    for(i=1;i<=m;i++){
        scanf("%d",&k);
        now=last+1;
        now%=n;
        if(now==0)now=n;
        while(k--){
        //printf("%-d ",now);
        while(mark[now]){
            now++;
            now%=n;
            if(now==0)now=n;
            //printf("%--d ",now);
        }
        //printf("%---d ",now);
        now++;
        now%=n;
        if(now==0)now=n;
        }
        while(mark[now]){
            now++;
            now%=n;
            if(now==0)now=n;
            //printf("%--d ",now);
        }
        last=now;
        printf("%s\n",a[now]);
        mark[now]=1;
        //for(j=1;j<=n;j++)printf("%d ",mark[j]);
    }
}
/*
5 3
PIZZA
HAMBURGER
PEDPUCKKING
BBQ
BINGSU
3
2
3
*/
