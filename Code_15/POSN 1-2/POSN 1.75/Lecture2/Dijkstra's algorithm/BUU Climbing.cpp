/*
    TASK:BUU Climbing
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[110][110];
int mark[110][110],di[]= {0,0,1,-1,1,-1,1,-1},dj[]= {1,-1,0,0,-1,1,1,-1};
struct A
{
    int i,j,w;
    bool operator< (const A&o) const
    {
        return w>o.w;
    }
};
priority_queue<A> hp;
int main()
{
    int i,j,q;
    scanf("%d",&q);
    while(q--)
    {
        int r,c,Max=0;
        scanf("%d %d",&r,&c);
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                scanf(" %c",&a[i][j]);
                Max=max(Max,(int)a[i][j]);
            }
        }
        int is,js,w,k,l,ni,nj,ch=1;
        scanf("%d %d",&is,&js);
        hp.push({is,js,0});
        while(!hp.empty())
        {
            i=hp.top().i;
            j=hp.top().j;
            w=hp.top().w;
            hp.pop();
            if(mark[i][j]==1)
                continue;
            if(a[i][j]==Max)
            {
                printf("%d\n",w);
                ch=0;
                break;
            }
            mark[i][j]=1;
            for(k=0; k<8; k++)
            {
                ni=i+di[k];
                nj=j+dj[k];
                if(ni<0 || ni>=r || nj<0 || nj>=c)
                    continue;
                if(a[ni][nj]=='#')
                    continue;
                hp.push({ni,nj,(w+(abs(a[ni][nj]-a[i][j])+1)*(abs(a[ni][nj]-a[i][j])+1))});
            }
        }
        if(ch)
            printf("NO\n");
        while(!hp.empty())
        {
            hp.pop();
        }
        memset(mark,0,sizeof mark);
    }
    return 0;
}
/*
2
5 5
11111
1###1
12341
12221
12221
0 0
3 3
1#3
2#3
##4
1 0
*/
