/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long fw[2020][2020];
void upd(int x,int y,int v){
    for(int i=x;i<=2000;i+=(i&-i)){
        for(int j=y;j<=2000;j+=(j&-j)){
            fw[i][j]+=v;
        }
    }
}
long long que(int x,int y){
    long long now=0;
    for(int i=x;i>0;i-=(i&-i)){
        for(int j=y;j>0;j-=(j&-j)){
            now+=fw[i][j];
        }
    }
    return now;
} 
int main()
{
    int n,x1,x2,y1,y2,f,ch=0,v;
    while(1){
        scanf("%d",&f);
        if(f==0){
            ch=1;
            scanf("%d",&n);
            continue;
        }
        if(!ch) continue;
        if(f==1){
            scanf("%d %d %d",&x1,&y1,&v);
            x1++;y1++;
            upd(x1,y1,v);
        }
        if(f==2){
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            x1++;y1++;x2++;y2++;
            printf("%lld\n",que(x2,y2)-que(x1-1,y2)-que(x2,y1-1)+que(x1-1,y1-1));
        }
        if(f==3){
            return 0;
        }
    }
    return 0;
}