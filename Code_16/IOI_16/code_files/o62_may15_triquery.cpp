/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dia[2010][2010],sq[2010][2010],trap[2010][2010],ori[2010][2010];
void diag(int r,int c,int v){
    for(int j=c,i=r;j<2005 && i<2005;j+=(j&-j), i+=(i&-i)){
        dia[i][j]+=v;
    }
}
void trape(){

}
void sqar(){

}
void que(int r,int c,int l){

}
int main()
{
    int n,m,q,r,c,l,v,ch=1;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&q,&r,&c);
        if(q==1){
            scanf("%d",&v);
            ori[r][c]=v;
            diag(r,c,v);
        }
        if(ch){
            trape();
            sqar();
            ch=0;
        }
        scanf("%d",&l);
        que(r,c,l);
    }
    return 0;
}