/*
    TASK:NC_Aquarium
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator<(const A& o) const{
        if(w!=o.w)
            return w>o.w;
    }
};
int n,m;
int l(int i,int j)
{
    int node=m*(i-1)+j;
    return node*2-1;
}
int r(int i,int j)
{
    int node=m*(i-1)+j;
    return node*2;
}
int p[10100*2];
char a[110][110];
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
priority_queue< A > h;
int main(){
    int i,j,w,tu,tv,tw,ans;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf(" %c",&a[i][j]);
            p[l(i,j)]=l(i,j);
            p[r(i,j)]=r(i,j);
            if(i>1){
                if(a[i][j]=='/'){
                    if(a[i-1][j]=='/'){
                        p[l(i,j)]=fin(p[r(i-1,j)]);
                    }else{
                        p[l(i,j)]=fin(p[l(i-1,j)]);
                    }
                }else{
                    if(a[i-1][j]=='/'){
                        p[r(i,j)]=fin(p[r(i-1,j)]);
                    }else{
                        p[r(i,j)]=fin(p[l(i-1,j)]);
                    }
                }
            }
            if(j>1)
            p[fin(p[l(i,j)])]=fin(p[r(i,j-1)]);
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&w);
            h.push({l(i,j),r(i,j),w});
            //printf("- %d %d - ",fin(l(i,j)),fin(r(i,j)));
        }
        //printf("\n");
    }
    ans=0;
    while(!h.empty()){
        tu=h.top().u;
        tv=h.top().v;
        tw=h.top().w;
        tu=fin(tu);
        tv=fin(tv);
        //printf("%d\n",tw);
        h.pop();
        //printf("%d %d %d\n",tu,tv,tw);
        if(tu!=tv){
            ans+=tw;
            //printf("%d\n",tw);
            p[tu]=tv;
        }
    }
    printf("%d\n",ans);
}
/*
2 2
\/
\\
7 10
12 9
*/
