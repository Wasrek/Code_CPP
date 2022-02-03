/*
    TASK:RC_Animal Farm
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j;
    char c;
    int k;
    bool operator<(const A&o)const{
    if(k!=o.k)return k>o.k;
    return c>o.c;
    }
};
int di[]={0,1},dj[]={1,0};
char mark[4500];
char a[2010][2010];
priority_queue< A> h;
int main(){
    int r,c,i,cost,k,ii,jj,mi,j,l,iii,jjj,cou=0;
    char t;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++){
        scanf(" %s",&a[i][1]);
    }
    h.push({1,1,a[1][1],1});
    memset(mark,127,sizeof mark);
    mark[1]=a[1][1];
    l=r+c-1;
    int kk;
//    printf("%c\n",a[1][1]);
    for(jjj=1;jjj<=l;jjj++){
//    printf("letter: --  %c %d\n",a[h.top().i][h.top().j],jjj);
    printf("%c",a[h.top().i][h.top().j]);
    cou++;
    if(cou==l)return 0;
    while(!h.empty()){
        t=h.top().c;
        i=h.top().i;
        j=h.top().j;
        kk=h.top().k;
        h.pop();
//        printf("%c %d %d %d\n",t,i,j,kk);
//        if(kk!=j)continue;
//        printf("%c %d %d %d\n",t,i,j,kk);
        for(iii=0;iii<2;iii++){
        ii=i+di[iii];
        jj=j+dj[iii];
        if(ii>r || jj>c)continue;
        if(a[ii][jj]>mark[kk+1])continue;
        h.push({ii,jj,a[ii][jj],kk+1});
        mark[kk+1]=a[ii][jj];
//        printf("push: %c %d %d %d\n",a[ii][jj],ii,jj,kk+1);
        }
//        printf("---\n");
        if(!h.empty() && (h.top().c!=t || h.top().k>jjj))break;
//        printf("---\n");
    }
//    printf("out\n");
    while(!h.empty() && h.top().k<=jjj)h.pop();
    }
}
