/*
    TASK:Candle Lighting Prayer
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
char a[2010][2010];
int ma[2010][2010],di[8]={0,0,1,1,1,-1,-1,-1},dj[8]={1,-1,-1,0,1,-1,0,1};
int main()
{
    int m,n,i,j,cou=0,ii,jj,k,iii,jjj;
    scanf("%d %d",&m,&n);
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf(" %c",&a[i][j]);
        }
    }
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(a[i][j]=='1')
            {
                cou++;
                q.push({i,j});
            while(!q.empty())
            {
                ii=q.front().i,jj=q.front().j;q.pop();
                for(k=0;k<8;k++){
                    iii=ii+di[k];
                    jjj=jj+dj[k];
                    if(a[iii][jjj]=='1'){
                        a[iii][jjj]='0';
                        q.push({iii,jjj});
                    }
                }

            }
            }
        }
    }
    printf("%d\n",cou);
}
/*
4 5
10011
00001
01100
10011
*/
