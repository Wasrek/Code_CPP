#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> mp;
struct A{
    int i,j;
    A operator - (const A&o) const{
        return {i-o.i,j-o.j};
    }
};
int cross(A a,A b){
    return a.i*b.j-a.j*b.i;
}
int isleft(A center,A a,A b){
    A pa=a-center;
    A pb=b-center;
    if(cross(pa,pb)>=0) return 1;
    return 0;
}
int isright(A center,A a,A b){
    A pa=a-center;
    A pb=b-center;
    if(cross(pa,pb)<=0) return 1;
    return 0;
}
bool anglesort(A a,A b){
    return ((a.i<b.i)||(a.i==b.i&&a.j<b.j));
}
vector<A> point,up,down;
void convexhull(vector<A> g){
    sort(g.begin(),g.end(),anglesort);
    up.clear();
    down.clear();
    up.push_back(g[0]);
    down.push_back(g[0]);
    int n=g.size(),cu=1,cd=1,i;
    for(i=1;i<n;i++){
        if(g[i].i==g[i-1].i&&g[i].j==g[i-1].j) continue;
        if(i==n-1){
            while(cu>=2&&isleft(up[cu-2],up[cu-1],g[i])) up.pop_back(),cu--;
            up.push_back(g[i]),cu++;
            while(cd>=2&&isright(down[cd-2],down[cd-1],g[i])) down.pop_back(),cd--;
            down.push_back(g[i]),cd++;
            continue;
        }
        if(isright(g[0],g[i],g[n-1])){
            while(cu>=2&&isleft(up[cu-2],up[cu-1],g[i])) up.pop_back(),cu--;
            up.push_back(g[i]),cu++;
        }
        if(isleft(g[0],g[i],g[n-1])){
            while(cd>=2&&isright(down[cd-2],down[cd-1],g[i])) down.pop_back(),cd--;
            down.push_back(g[i]),cd++;
        }
    }
    if(down.size()==1) printf("1\n");
    else printf("%d\n",down.size()+up.size()-2);
    for(i=0;i<down.size();i++){
        printf("%d %d\n",down[i].i,down[i].j);
    }
    for(i=up.size()-2;i>=1;i--){
        printf("%d %d\n",up[i].i,up[i].j);
    }
}
int main(){
    int n,i,a,b;
    while(1){
        scanf("%d",&n);
        if(n==0) return 0;
        point.clear();
        for(i=0;i<n;i++){
            scanf("%d %d",&a,&b);
            point.push_back({a,b});
        }
        convexhull(point);
    }
return 0;
}
/*
3
0 0
10 0
0 10
5
41 -6
-24 -74
-51 -6
73 17
-30 -34
2
50 50
50 50
0
*/
