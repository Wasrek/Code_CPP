/*
    TASK:Spaceship
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y,z,a,b,c;
};
A s[15];
int mark[15];
int want,sn,mi=2e9,aa,bb,cc,nd;
void play(int x,int y,int z,int a,int b,int c,int dis){
    if(a>=want && b>=want && c>=want){
        mi=min(dis,mi);
        return ;
    }
    for(int i=1;i<=sn;i++){
        if(mark[i])continue;
        mark[i]=1;
        aa=a+s[i].a;
        bb=b+s[i].b;
        cc=c+s[i].c;
        nd=dis+(s[i].x-x)*(s[i].x-x)+(s[i].y-y)*(s[i].y-y)+(s[i].z-z)*(s[i].z-z);
        if(a>=want && b>=want && c>=want){
            mi=min(nd,mi);
            continue;
        }
        play(s[i].x,s[i].y,s[i].z,aa,bb,cc,nd);
        mark[i]=0;
    }
    return ;
}
int main()
{
    int x,y,z;
    scanf("%d",&want);
    scanf("%d %d %d",&x,&y,&z);
    scanf("%d",&sn);
    for(int i=1;i<=sn;i++){
        scanf("%d %d %d %d %d %d",&s[i].x,&s[i].y,&s[i].z,&s[i].a,&s[i].b,&s[i].c);
    }
    play(x,y,z,0,0,0,0);
    printf("%d\n",mi);
    return 0;
}