/*
    TASK:48_Table
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,t;
};
A arr[350][5100],rr[350];
struct B{
    int type,v,a,b,t;
    bool operator<(const B & o) const{
        return v>o.v;
    }
};
priority_queue< B > h;
int main()
{
    int r,c,q,opr,a,b,v,ans,ch;
    scanf("%d %d %d",&r,&c,&q);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            h.push({1,0,i,j,0});
        }
    }
    for(int i=1;i<=q;i++){
        scanf("%d",&opr);
        if(opr==1){
            scanf("%d %d %d",&a,&b,&v);
            arr[a][b].v=v;
            arr[a][b].t=i;
            h.push({1,v,a,b,i});
        }
        if(opr==2){
            scanf("%d %d",&a,&v);
            rr[a].v=v;
            rr[a].t=i;
            h.push({2,v,a,0,i});
        }
        if(opr==3){
            scanf("%d %d",&a,&b);
            if(rr[a].t>arr[a][b].t) printf("%d\n",rr[a].v);
            else printf("%d\n",arr[a][b].v);
        }
        if(opr==4){
            while(!h.empty()){
                if(h.top().type==1){
                    if(h.top().t<rr[h.top().a].t || h.top().t < arr[h.top().a][h.top().b].t){ h.pop(); continue;}
                    printf("%d\n",h.top().v);
                    break;
                }else{
                    ch=0;
                    if(h.top().t<rr[h.top().a].t){ h.pop();continue;}
                    for(int j=1;j<=c;j++){
                        if(arr[h.top().a][j].t<h.top().t){
                            ch=1;break;
                        }
                    }
                    if(ch){
                        printf("%d\n",h.top().v);
                        break;
                    }else{
                        h.pop();
                        continue;
                    }
                }
                break;
            }
        }
    } 
    return 0;
}