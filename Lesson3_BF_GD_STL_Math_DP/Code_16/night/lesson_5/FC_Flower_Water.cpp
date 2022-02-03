/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,v;
    bool operator <(const A & o) const{
        return v<o.v;
    }
};
A x[100010],y[100010];
int p[100010];
unordered_map< int,int > mp;
int fin(int i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
int main()
{
    int q,n,px1,px2,py1,py2,now,fr;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&x[i].v,&y[i].v);
            x[i].i=y[i].i=p[i]=i;
        }
        sort(x+1,x+1+n);
        sort(y+1,y+1+n);
        for(int i=1;i<=n;i++){
            if(x[i-1].v==x[i].v){
                px1=fin(p[x[i-1].i]);
                px2=fin(p[x[i].i]);
                p[px1]=px2;
            }
            if(y[i-1].v==y[i].v){
                py1=fin(p[y[i-1].i]);
                py2=fin(p[y[i].i]);
                p[py1]=py2;
            }
        }
        now=0;
        for(int i=1;i<=n;i++){
            fr=fin(p[i]);
            // printf("p %d\n",fr);
            if(!mp[fr]){
                mp[fr]=1;
                now++;
            }
        }
        // printf("%d\n",now);
        if(now%2) now=now/2+1;
        else now/=2;
        printf("%d\n",now);
        mp.clear();
    }
    return 0;
}
/*
2
4
1 2
2 1
2 3
3 2
9
2 1
1 2
2 3
2 5
1 6
2 7
4 3
5 4
4 5
*/