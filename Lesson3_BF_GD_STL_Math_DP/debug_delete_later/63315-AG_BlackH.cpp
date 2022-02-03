#include<bits/stdc++.h>
using namespace std;
vector<int>node[100100],z,h;
int pa[100100],d[100100][3],b[100100];
queue<int>hh;
void fp(int x, int y){
    pa[x]=y;
    z.push_back(x);
    d[x][0]=z.size()-1;
    for(int i=0;i<node[x].size();i++){
        if(node[x][i]==y)continue;
        fp(node[x][i],x);
    }
    z.push_back(x);
    d[x][1]=z.size()-1;
}

//void f(int x,int v){
//    if(v!=-1)b[x]=v;
//    for(int i=0;i<node[x].size();i++){
//        if(node[x][i]==pa[x])continue;
//        f(node[x][i],b[x]);
//    }
//}
int ch[100100];
int main(){
    int n,q,i,u,v,t,c,x,j;
    scanf("%d%d",&n,&q);
    for(i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        node[u].push_back(v);
        node[v].push_back(u);
    }
    fp(1,0);
    memset(b,-1,sizeof b);
    t=(int)sqrt((double)q);
//    for(i=0;i<z.size();i++)printf("%d ",z[i]);
//    printf("\n");
    for(i=1;i<=q;i++){
        scanf("%d%d",&c,&x);
        if(c==0){
            if(b[x]==-1)b[x]=x;
            h.push_back(x);
        }
        else{
            for(j=0;j<h.size();j++){
                if(b[x]==-1){
                    if(d[h[j]][0]<d[x][0] && d[h[j]][1]>d[x][1])b[x]=h[j];
                }
                if(d[h[j]][0]<d[b[x]][0] && d[h[j]][1]>d[b[x]][1])b[x]=h[j];
            }
            printf("%d\n",b[x]);
        }
        if(i%t==0){
            for(j=0;j<z.size();j++){
                if(!hh.empty())b[z[j]]=hh.front();
                if(!hh.empty()&&z[j]==hh.front()){
                    hh.pop();
                }
                else if(z[j]==b[z[j]]){
                    hh.push(z[j]);
                }
            }
//            f(1,-1);
            h.clear();
        }
    }
    return 0;
}
