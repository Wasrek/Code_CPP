/*
    TASK:Cat Code
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define hhash 500009
char cc[40],ask[1000100];
int harr[hhash],val[100010],mar[100010];
int main()
{
    int n,m,su,now,q,f,k,ma=0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf(" %s",cc);
        su=cc[0]-'0';
        for(int j=1;j<m;j++){
            su*=2;
            su+=cc[j]-'0';
        }
        now=su;
        now%=hhash;
        f=1;
        while(harr[now]!=0){
            now+=f;
            f*=3;
            now%=hhash;
        }
        harr[now]=i;
        val[i]=su;
    }
    scanf("%d",&q);
    while(q){
        scanf("%d",&k);
        scanf(" %s",ask);
        if(k<m){
            printf("OK\n");
            q--;
            continue;
        }
        ma=0;
        su=ask[0]-'0';
        for(int i=1;i<m-1;i++){
            su*=2;
            su+=ask[i]-'0';
        }
        for(int i=m-1;i<k;i++){
            su&=((1<<(m-1))-1);// last m-1
            su*=2;
            su+=ask[i]-'0';
            now=su;
            now%=hhash;
            f=1;
            while(harr[now]!=0){
                if(val[harr[now]]==su){
                    ma=1;
                    mar[harr[now]]=q;
                    break;
                }else{
                    now+=f;
                    f*=3;
                    now%=hhash;
                }
            } 
        }
        if(!ma){
            printf("OK\n");
            q--;
            continue;
        }else{
            for(int i=1;i<=n;i++){
                if(mar[i]==q)printf("%d ",i);
            }
            printf("\n");
        }
        q--;
    }
    return 0;
}