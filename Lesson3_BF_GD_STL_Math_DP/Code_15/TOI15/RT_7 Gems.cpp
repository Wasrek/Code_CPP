/*
    TASK:RT_7 Gems
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[210][210];
int mark[8][128][205][205],di[]= {0,0,1,-1,0},dj[]= {1,-1,0,0,0},gg[210][210];
struct A
{
    int c,i,j,bm,w;
};
struct B
{
    int i,j;
};
queue<A> h;
int main()
{
    int i,j,n,m,si,sj,c,bm,w,k,cou=0,gem,cc;
    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='S')
                si=i,sj=j;
            if(a[i][j]=='G')
            {
                gg[i][j]=(1<<cou);
                cou++;
            }
        }
    }
    memset(mark,127,sizeof mark);
    int ii,jj;
    mark[1][0][si][sj]=1;
    h.push({1,si,sj,0,0});
    while(!h.empty())
    {
        c=h.front().c;
        i=h.front().i;
        j=h.front().j;
        bm=h.front().bm;
        w=h.front().w;
        h.pop();
        cc=(c+1)%6;
        if(cc==0)
            cc=6;
        if(bm==(1<<7)-1)
        {
            printf("%d\n",w);
            return 0;
        }
        for(k=0; k<5; k++)
        {
            ii=i+di[k];
            jj=j+dj[k];
            if(ii<1 || jj<1 || ii>n || jj>m)
                continue;
            if(a[ii][jj]=='.' || a[ii][jj]=='S')
            {
                if(mark[cc][bm][ii][jj]<=w+1)
                    continue;
                mark[cc][bm][ii][jj]=w+1;
                h.push({cc,ii,jj,bm,w+1});
                continue;
            }
            if(a[ii][jj]=='#')
                continue;
            if(a[ii][jj]=='G')
            {
                gem=bm|gg[ii][jj];
                if(mark[cc][gem][ii][jj]<=w+1)
                    continue;
                mark[cc][gem][ii][jj]=w+1;
                h.push({cc,ii,jj,gem,w+1});
            }
            if(isdigit(a[ii][jj]))
            {
                if(__builtin_popcount(bm)>=a[ii][jj]-'0' || cc==a[ii][jj]-'0')
                {
                    if(mark[cc][bm][ii][jj]<=w+1)
                        continue;
                    mark[cc][bm][ii][jj]=w+1;
                    h.push({cc,ii,jj,bm,w+1});
                    continue;
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}
