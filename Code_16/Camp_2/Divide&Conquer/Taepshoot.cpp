/*
    TASK:Taepshoot
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[4000000];
int b[4000000],n,coun;
void play1(int lev,int v,int ti){
    if(lev==n){
        b[coun++]=ti;
        return ;
    }
    int l=0,r=0;
    if(a[v]=='L'){
        r+=(1<<lev);
    }else{
        l+=(1<<lev);
    }
    play1(lev+1,v*2+1,ti+l);
    play1(lev+1,v*2+2,ti+r);
    return ;
}
int play2(int lev,int v){
    if(lev==n){
        return b[coun++];
    }
    int l=play2(lev+1,v*2+1);
    int r=play2(lev+1,v*2+2);
    if(l<r){
        a[v]='L';
    }
    else a[v]='R';
    return min(l,r);
}
int main()
{
    int opr;
    scanf("%d",&opr);
    scanf("%d",&n);
    if(opr==1){
        scanf(" %s",a);
        play1(0,0,1);
        // printf("%d\n",coun);
        for(int i=0;i<min(coun,555555);i++){
            printf("%d ",b[i]);
        }
        return 0;
    }else{
        for(int i=0;i<(1<<n);i++){
            scanf(" %d",&b[i]);
        }
        play2(0,0);
        printf("%s",a);
    }
    return 0;
}