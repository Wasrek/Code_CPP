/*
    TASK:One Turn Table
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    int i,j;
};
queue< A > q;
stack< A >st;
char a[55][55];
int dis[55][55],di[]= {0,0,-1,1},dj[]= {1,-1,0,0};
int main()
{
    int n,m,i,j,ii,jj,k,ch,cou,cb=0,si,sj;
    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='B')
                cb++,st.push({i,j});
        }
    }
    while(!st.empty())
    {
        si=st.top().i,sj=st.top().j;
        st.pop();
        memset(dis,-1,sizeof dis);
        q.push({si,sj}),dis[si][sj]=0;
        cou=0;
        while(!q.empty())
        {
            i=q.front().i;
            j=q.front().j;
            q.pop();
            cou++;
            for(k=0; k<4; k++)
            {
                ii=i;
                jj=j;
                while(1)
                {
                    ii+=di[k];
                    jj+=dj[k];
                    if(ii<1 || ii>n || jj<1 || jj>m)
                        break;
                    if(dis[ii][jj]!=-1)
                        continue;
                    if(a[ii][jj]=='W')
                        break;
                    dis[ii][jj]=dis[i][j]+1;
                    if(dis[ii][jj]>2)
                    {
                        printf("NO");
                        return 0;
                    }
                    q.push({ii,jj});
                }
            }
        }
        if(cou<cb)
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}
/*
3 4
WWBW
BWWW
WWWB

4 4
WWBW
WBBB
BBBB
WBBW

4 4
WBBW
WBBW
WBWW
WBBW
*/
