/*
    TASK:Lawnmower
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[110][110],mi[110],mj[110];
int main()
{
    int q,i,j,ch,t,r,c;
    scanf("%d",&q);
    for(t=1; t<=q; t++)
    {
        printf("Case #%d: ",t);
        scanf("%d %d",&r,&c);
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                scanf("%d",&a[i][j]);
                mi[i]=max(mi[i],a[i][j]);
                mj[j]=max(mj[j],a[i][j]);
            }
        }
        for(i=0,ch=1; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if(a[i][j]<mi[i] && a[i][j]<mj[j])
                {
                    ch=0;
                }
            }
        }
        printf((ch)?"YES\n":"NO\n");
        memset(a,0,sizeof a);
        memset(mi,0,sizeof mi);
        memset(mj,0,sizeof mj);
    }
    return 0;
}
/*
3
Case #1:
3 3
2 1 2
1 1 1
2 1 2
YES
Case #2:
5 5
2 2 2 2 2
2 1 1 1 2
2 1 2 1 2
2 1 1 1 2
2 2 2 2 2
NO
Case #3:
1 3
1 2 1
YES
*/
