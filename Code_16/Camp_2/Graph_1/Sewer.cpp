/*
    TASK:Sewer
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,li,lj,t;
};
char a[110][110];
int ma[110][110];
queue< A > q;
int main()
{
    int n,m,ti,tj,li,lj,t;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf(" %c",&a[i][j]);
        }
    }
    q.push({1,1,-1,-1,1});
    while(!q.empty()){
        ti=q.front().i;
        tj=q.front().j;
        li=q.front().li;
        lj=q.front().lj;
        t=q.front().t;
        q.pop();
        // printf("\n%d %d %d %d %d\n",ti,tj,t,li,lj);
        if(ma[ti][tj]==t){
            printf("%d\n%d %d",t,ti,tj);
            return 0;
        }else{
            ma[ti][tj]=t;
        }
        if(a[ti][tj]=='N'){
            if(a[ti-1][tj]=='B' || a[ti-1][tj]=='D'){
                if(ti-1>=1 && (ti-1!=li || tj!=lj))
                q.push({ti-1,tj,ti,tj,t+1});
            }
            if(a[ti][tj-1]=='B' || a[ti][tj-1]=='R'){
                if(tj-1>=1 && (ti!=li || tj-1!=lj))
                q.push({ti,tj-1,ti,tj,t+1});
            }
        }else
        if(a[ti][tj]=='R'){
            // printf("Hi1\n");
            // printf("here\n");
            if((ti!=li || tj+1!=lj) && tj+1<=m){
                q.push({ti,tj+1,ti,tj,t+1});
            }
            if(a[ti-1][tj]=='B' || a[ti-1][tj]=='D'){
                if(ti-1>=1 && (ti-1!=li || tj!=lj))
                q.push({ti-1,tj,ti,tj,t+1});
            }
            if(a[ti][tj-1]=='B' || a[ti][tj-1]=='R'){
                if(tj-1>=1 && (ti!=li || tj-1!=lj))
                q.push({ti,tj-1,ti,tj,t+1});
            }
        }else
        if(a[ti][tj]=='D'){
            // printf("Hi2\n");
            if((ti+1!=li || tj!=lj) && ti+1<=n){
                // printf("here\n");
                q.push({ti+1,tj,ti,tj,t+1});
            }
            if(a[ti-1][tj]=='B' || a[ti-1][tj]=='D'){
                if(ti-1>=1 && (ti-1!=li || tj!=lj))
                q.push({ti-1,tj,ti,tj,t+1});
            }
            if(a[ti][tj-1]=='B' || a[ti][tj-1]=='R'){
                if(tj-1>=1 && (ti!=li || tj-1!=lj))
                q.push({ti,tj-1,ti,tj,t+1});
            }
        }else
        if(a[ti][tj]=='B'){
            // printf("Hi3\n");
            if((ti+1!=li || tj!=lj) && ti+1<=n){
                // printf("Hi31");
                q.push({ti+1,tj,ti,tj,t+1});
            }
            if((ti!=li || tj+1!=lj) && tj+1<=m){
                // printf("Hi32");
                q.push({ti,tj+1,ti,tj,t+1});
            }
            if(a[ti-1][tj]=='B' || a[ti-1][tj]=='D'){
                if(ti-1>=1 && (ti-1!=li || tj!=lj))
                q.push({ti-1,tj,ti,tj,t+1});
            }
            if(a[ti][tj-1]=='B' || a[ti][tj-1]=='R'){
                if(tj-1>=1 && (ti!=li || tj-1!=lj))
                q.push({ti,tj-1,ti,tj,t+1});
            }
        }
    }
    return 0;
}