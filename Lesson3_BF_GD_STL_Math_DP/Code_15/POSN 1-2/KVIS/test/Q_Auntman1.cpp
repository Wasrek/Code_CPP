/*
    TASK:Q_Auntman
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
struct A
{
    int i,j,t;
};
queue< A > q;
char a[1010][1010];
int di[4]= {1,-1,0,0},dj[4]= {0,0,1,-1},ci[8]= {-1,-1,-2,-2,1,1,2,2,},cj[8]= {-1,1,-2,2,-1,1,-2,2};//pi[2]= {0,-1},pj[2]= {-1,0},chi[4]= {-1,-1,-2,-2},chj[4]= {-1,1,-2,2};
int main()
{
    int n,m,i,j,cou=0,k,nexti,nextj,t,v;
    scanf("%d %d",&n,&m);
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='+')
            {
                q.push({i,j,1});
            }
            if(a[i][j]=='x')
            {
                q.push({i,j,2});
            }
            if(a[i][j]=='A')
            {
                cou++;
            }
        }
    }
    while(!q.empty())
    {
        i=q.front().i,j=q.front().j,t=q.front().t;
        q.pop();
        if(t==1)
        {
            for(v=0; v<4; v++)
            {
                nexti=i+di[v],nextj=j+dj[v];
                if(nexti<0 || nextj<0 || nexti>=n || nextj>=m)
                    continue;
                if(a[nexti][nextj]=='A')
                    cou--,a[nexti][nextj]='.';
            }
        }
        if(t==2)
        {
            for(v=0; v<8; v++)
            {
                nexti=i+ci[v],nextj=j+cj[v];
                if(nexti<0 || nextj<0 || nexti>=n || nextj>=m)
                    continue;
                if(a[nexti][nextj]=='A')
                    cou--,a[nexti][nextj]='.';
            }
        }
    }
    printf("%d\n",cou);
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(a[i][j]=='x' || a[i][j]=='+')
                printf(".");
            else
                printf("%c",a[i][j]);
        }
        printf("\n");
    }
}
/*
5 7
A..A...
.A..A..
.Ax.+..
...A...
......A
*/
