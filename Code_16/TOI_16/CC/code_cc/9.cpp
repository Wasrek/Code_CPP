/*
    TASK:Z-encryption
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010],ans[1010];
int main()
{
    int n,set,c,r,l1,l2,mi,ta,len;
    scanf("%d",&n);
    set=(n*2)+(2*(n-2));
    scanf(" %s",a+1);
    if(n==1){
        printf("%s",a+1);
        return 0;
    }
    len=strlen(a+1); 
    int now=n-1,pt=0,nnow;
    while(1){
        nnow=now;
        if(now>len) break;
        for(int i=1;i<=n;i++){
            nnow++;
            if(nnow<=len){
                ans[nnow]=a[++pt];
            }
        }
        if(now>len) break;
        now+=set;
        if(now>len) break;
    }
    int up,dw,st;
    for(int i=1;i<=n-2;i++){
        up=n+(i*2)-1;
        dw=n+((n-i-1)*2)-1;
        st=n-i;
        while(1){
            if(st<=len) ans[st]=a[++pt];
            st+=up;
            if(st<=len) ans[st]=a[++pt];
            st+=dw;
            if(st>len) break;
        }
    }
    if(1<=len) ans[1]=a[++pt];
    now=(2*n)+(n-2)-1;
     while(1){
        if(now>len) break;
        nnow=now;
        for(int i=1;i<=n;i++){
            nnow++;
            if(nnow<=len){
                ans[nnow]=a[++pt];
            }
        }
        if(now>len) break;
        now+=set;
        if(now>len) break;
    }
    for(int i=1;i<=len;i++){
        printf("%c",ans[i]);
    }
    printf("\n");
    return 0;
}