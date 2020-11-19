/*
    TASK:RT_iZone
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int r[1000100],g[1000100],b[1000100],mark[1000100];
int main(){
    int n,m,w,i,j,cnt=0,a,x,y,ansr,ansb,ansg;
    char c;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n+3;i++)
    {
        if(cnt==0){
            mark[i]='R';
            for(j=i;j<=n+3;j+=(j&-j)){
                r[j]+=1;
            }
        }else
        if(cnt==1){
        mark[i]='G';
        for(j=i;j<=n+3;j+=(j&-j)){
                g[j]+=1;
            }
        }else{
        mark[i]='B';
        for(j=i;j<=n+3;j+=(j&-j)){
                b[j]+=1;
            }
        }
        cnt++;
        cnt%=3;
    }
    while(m--){
        scanf("%d",&w);
        if(w==1){
            scanf("%d %c",&i,&c);
            if(mark[i]==c)continue;
            if(c=='R'){
                for(j=i;j<=n+3;j+=(j&-j)){
                r[j]+=1;
                if(mark[i]=='B')b[j]-=1;
                else g[j]-=1;
                }
                mark[i]='R';
            }else
            if(c=='B'){
                for(j=i;j<=n+3;j+=(j&-j)){
                b[j]+=1;
                if(mark[i]=='R')r[j]-=1;
                else g[j]-=1;
                }
                mark[i]='B';
            }else
            if(c=='G'){
                for(j=i;j<=n+3;j+=(j&-j)){
                g[j]+=1;
                if(mark[i]=='B')b[j]-=1;
                else r[j]-=1;
                }
                mark[i]='G';
            }
        }else{
            scanf("%d %d",&x,&y);
            ansr=ansb=ansg=0;
            for(i=y;i>=1;i-=(i&-i)){
                ansr+=r[i];
                ansg+=g[i];
                ansb+=b[i];
            }
            for(i=x-1;i>=1;i-=(i&-i)){
                ansr-=r[i];
                ansg-=g[i];
                ansb-=b[i];
            }
            if(ansr>ansg && ansr>ansb){
                printf("R\n");
            }else
            if(ansb>ansg && ansb>ansr){
                printf("B\n");
            }else
            if(ansg>ansb && ansg>ansr){
                printf("G\n");
            }else
            printf("None\n");
        }
    }
    return 0;
}
/*
10 7
1 2 R
2 1 5
1 5 B
1 3 G
2 4 8
2 1 8
2 5 6
*/
