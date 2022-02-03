/*
    TASK:Carousel
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int t[400010],c[400010],g[400010],h[400010];
int main()
{
    int Q,n,now,cnt,ch,cou;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d",&n);
        now=0;
        ch=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&t[i]);
            if(t[i]!=t[i-1]){
                h[++now]=t[i];
            }else{
                ch=1;
            }
            g[i]=now;
        }
        if(now==1){
            printf("1\n");
            for(int i=1;i<=n;i++){
                printf("1 ");
            }
            printf("\n");
            continue;
        }
        if((now%2)==0 || ((now%2) && h[1]==h[now]) ||((now%2) && ch)){
            printf("2\n");
            cou=0;
            if((now%2) && ch){
                for(int i=1;i<=n;i++){
                if(g[i+1]!=g[i] && g[i]==g[i-1] && ch){
                    cou++;
                    printf("%d ",2-(cou%2));
                    ch=0;
                    continue;
                }else
                if(g[i]!=g[i-1]){
                    cou++;
                }
                printf("%d ",2-(cou%2));
            }
            printf("\n");
            continue;
            }
            for(int i=1;i<=n;i++){
                if(g[i]%2){
                    printf("1 ");
                }else{
                    printf("2 ");
                }
            }
            printf("\n");
        }else{
            printf("3\n");
            for(int i=1;i<=n;i++){
                if(g[i]==now){
                    printf("3 ");
                    continue;
                }
                if(g[i]%2){
                    printf("1 ");
                }else{
                    printf("2 ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}