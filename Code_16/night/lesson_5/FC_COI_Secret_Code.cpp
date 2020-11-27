/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char c[1000100],a[1000100],ans[1000100];
int p[1000100],ma[1000100];
int main()
{
    int q,now,lenc,lena;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",a+1);
        scanf(" %s",c+1);
        lenc=strlen(c+1);
        lena=strlen(a+1);
        memset(p,0,sizeof p);
        for(int i=2,j=0;i<=lenc;i++){
            while(j>0 && c[j+1]!=c[i]) j=p[j];
            if(c[j+1]==c[i]) j++;
            p[i]=j;
        }
        now=0;
        for(int i=1,j=0;i<=lena;i++){
            while(j>0 && c[j+1]!=a[i]) j=p[j];
            if(c[j+1]==a[i]) j++;
            if(j==lenc){
                now-=(lenc-1);
                j=ma[now];
            }else{
                ma[++now]=j;
                ans[now]=a[i];
            }
        }
        if(!now){
            printf("No COI Secret Code\n");
        }else{
            ans[now+1]='\0';
            printf("%s\n",ans+1);
        }
    }
    return 0;
}