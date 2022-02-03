/*
    TASK:army
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[800][800];
int di[8]={0,0,1,1,1,-1,-1,-1},dj[8]={1,-1,1,-1,0,0,1,-1};
typedef pair<int,int> PII;
queue< PII > q;
int main()
{
    int r,c,i,j,cou,k,ans=0,ii,jj,nexti,nextj;
    scanf("%d %d",&c,&r);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        scanf(" %c",&a[i][j]);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(a[i][j]=='.'){
                q.push({i,j});
                a[i][j]='*',cou=1;
                while(!q.empty()){
                    ii=q.front().first,jj=q.front().second;
                    q.pop();
                    for(k=0;k<8;k++){
                        nexti=ii+di[k],nextj=jj+dj[k];
                        if(nexti<0||nextj<0||nexti>=r||nextj>=c) continue;
                        if(a[nexti][nextj]=='*')continue;
                        a[nexti][nextj]='*',cou++;
                        q.push({nexti,nextj});

                    }
                }
                if(cou>ans)
                    ans=cou;
            }        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
10 8
...*....**
..**....**
...*....**
...**.*.**
***.**.***
...**.*.**
...*.*****
...***..**
*/
