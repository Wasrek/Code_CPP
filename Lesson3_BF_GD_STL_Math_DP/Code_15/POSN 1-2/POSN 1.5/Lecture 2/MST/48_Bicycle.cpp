/*
    TASK:48_Bicycle
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
unordered_map <int,int> mapp;
struct A{
    int u,v,w;
    bool operator < (const A&o) const{
        return w<o.w;
    }
};
priority_queue< A > h;
int p[50100];
int fin(int i){
   if(p[i]==i) return i;
   return p[i]=fin(p[i]);
}
int main()
{
    int n,x,r,c,i,j,w,a,b,ra,rb;
    scanf("%d",&n);
    while(n--){
        int ans=0;
        scanf("%d %d",&x,&r);

        for(i=1;i<=x;i++){
            scanf("%d",&c);
            mapp[c]=i;//
            p[i] = i;//
        }
        while(r--){
            scanf("%d %d %d",&i,&j,&w);
            h.push({mapp[i],mapp[j],w});//
        }
        while(!h.empty()){
            a=h.top().u;b=h.top().v;c=h.top().w;
            h.pop();
            ra=fin(a);rb=fin(b);
            if(ra!=rb){
                p[rb]=ra;
            }else{ans+=c;}
        }
        printf("%d\n",ans);
        mapp.clear();
    }

    return 0;
}
/*
2
8 10
1 2 3 4 5 6 7 8
1 2 3
1 5 5
2 3 4
2 6 3
3 4 2
3 7 5
4 8 5
5 6 2
6 7 7
7 8 3
14 18
5 11 13 0 3 8 6 2 12 14 1 9 10 4
5 0 2
5 6 7
5 10 7
11 6 5
11 10 9
11 12 4
13 14 3
13 8 5
13 12 6
0 1 7
3 2 7
3 8 1
3 4 1
8 9 1
6 1 7
2 1 9
14 9 1
9 4 3
*/
