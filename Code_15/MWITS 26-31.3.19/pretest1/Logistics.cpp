/*
    TASK:Logistics
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int f,n;
    float w;
};
vector<int> g[70][70],ar[70];
int mark[70];
float dis[70][70];
queue<A> q;
int main(){
    int n,w,i,j,ss,ff,nn,ch=1;
    float ww,ans;
    scanf("%d",&n);
    char a,b;
    while(n--){
        scanf(" %c %c %d",&a,&b,&w);
        if(a!='Y' && b!='Y')ar[a-'X'].push_back(b-'X'),ar[b-'X'].push_back(a-'X');
        else if(a=='Y')ar[35].push_back(b-'X'),ar[b-'X'].push_back(35);
        else if(b=='Y')ar[35].push_back(a-'X'),ar[a-'X'].push_back(35);
        if(a=='Y'){
            g[b-'X'][35].push_back(w);continue;
        }
        if(b=='Y'){
            g[a-'X'][35].push_back(w);continue;
        }
        if(a>b)swap(a,b);
        g[a-'X'][b-'X'].push_back(w);
    }
    for(i=0;i<=35;i++){
        for(j=i+1;j<=35;j++){
            sort(g[i][j].begin(),g[i][j].end());
            ss=g[i][j].size();
            if(ss==0)continue;
//            for(auto x:g[i][j])printf("%d",x);
//            printf("\n");
            if(ss%2){
                dis[i][j]=(float)g[i][j][ss/2];
                dis[j][i]=dis[i][j];
//                printf("%.1f\n",i+'X',(double)g[i][j][ss/2]);
            }else{
                dis[i][j]=(float)(g[i][j][ss/2-1]+g[i][j][ss/2])/2;
                dis[j][i]=dis[i][j];
            }
//            if(j==35){printf("%c Y %.1lf\n",i+'X',dis[i][j]);}
//            else
//            printf("%c %c %.1lf\n",i+'X',j+'X',dis[i][j]);
        }
    }
    q.push({0,0,0});
    mark[0]=1;
    while(!q.empty()){
        ff=q.front().f;
        nn=q.front().n;
        ww=q.front().w;
        q.pop();
        if(nn==35){ch=0;break;}
        for(auto y : ar[nn]){
            if(!mark[y])
            mark[y]=1,q.push({nn,y,ww+dis[nn][y]});
        }
    }
    if(ch){printf("broken\n");return 0;}
    memset(mark,0,sizeof mark);
    ans=0;
    while(!q.empty())q.pop();
    q.push({0,0,0});
    q.push({0,0,0});
    mark[0]=1;
    while(!q.empty()){
        ff=q.front().f;
        nn=q.front().n;
        ww=q.front().w;
        if(nn!=ff){
        //if(dis[ff][nn]==0)dis[ff][nn]=dis[nn][ff];
        if(nn==35){printf("%c Y %.1f\n",ff+'X',dis[ff][nn]);}
            else
            printf("%c %c %.1f\n",ff+'X',nn+'X',dis[ff][nn]);

        }
        q.pop();
        if(nn==35){ch=0;ans=ww;break;}
        for(auto y : ar[nn]){
            if(!mark[y])
            mark[y]=1,q.push({nn,y,ww+dis[nn][y]});
        }
    }
    printf("%.1f\n",ans);
    return 0;

}
/*
6
X a 1
a b 4
b a 1
b Y 3
b Y 2
Y b 6
5
a b 2
q Y 3
t b 4
q t 5
X a 1
*/
