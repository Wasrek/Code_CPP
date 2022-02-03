/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int b[100100],l;
long long fw[100100];
bool ch[100100];
void upd(int u,int v){
    for(int i=u;i<=100000;i+=(i&-i)) fw[i]+=v;
}
int qy(int u){
    int ans=0;
    for(int i=u;i>0;i-=(i&-i)){
        ans+=fw[i];
    } 
    return ans;
}
void md(int la,int now,bool inc){
    if(la==now) return ;
    int k;
    if(inc){
        int cha=abs(now-la);
        printf("%d %d\n",la,now);
        if(la==0) la=l;
        if(now==0) now=l;
        if(la<now || now==0){
            upd(1,-1*cha);
            k=now+1;
            upd(k,l);upd(k+1,-l);
        }else{
            k=la+1;
            printf("-- %d %d %d %d\n",la,now,k,cha);
            upd(k,-l);upd(k+1,l);
            upd(1,cha);
        }
    }else{
        int cha=abs(now-la);
        if(la<now){
            k=la+1;
            upd(k,-l);upd(k+1,l);
            upd(1,cha);
        }else {
            k=now+1;
            upd(k,l);upd(k+1,-l);
            upd(-1,cha);
        }
    }
    return ;
}
void flp(int now){
    if(ch[now]){

    }else{

    }
}
int main()
{
    int n,q,x,y;
    long long diff;
    char t;
    scanf("%d %d %d",&n,&l,&q);
    for(int i=1;i<=n;i++){
        ch[i]=1;//base=0
    }
    while(q--){
        scanf(" %c",&t);
        if(t=='s'){
            scanf("%d %d",&x,&y);
            md(b[x],(b[x]+y)%l,ch[x]);
            b[x]=(b[x]+y)%l;
        }else if(t=='f'){
            scanf("%d",&x);
            ch[x]^=1;
            flp(x);
        }else {//q
            scanf("%d",&x);
            x++;
            diff=qy(x);
            // printf("%d %d\n",diff,x);
            printf("%lld\n",diff+(x-1)*n);
        }
        for(int i=1;i<=l+1;i++){
            printf("%d ",qy(i));
        }
        printf("\n");
    }
    return 0;
}