/*
    TASK:game1
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[550][550],di[]= {0,1},dj[]= {1,0},mark[550][550],dis[550][550],cou[1010];
typedef pair<int,int> A;
queue<A>q;
int main()
{
    int w,h;
    scanf("%d %d",&h,&w);
    int i,j;
    for(i=h-1; i>=0; i--)
    {
        for(j=0; j<w; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    q.push({0,0});
    int ans=0,k,nexti,nextj,Max=0;
    while(!q.empty())
    {
        i=q.front().first,j=q.front().second;
        q.pop();
        for(k=0; k<2; k++)
        {
            nexti=i+di[k],nextj=j+dj[k];
            if(nexti<0 || nextj<0 || nexti>=h || nextj>=w)
                continue;
            if(a[nexti][nextj])
                continue;
            if(mark[nexti][nextj])
                continue;
            dis[nexti][nextj]=dis[i][j]+1;
            Max=max(Max,dis[nexti][nextj]);
            cou[dis[nexti][nextj]]++;
            mark[nexti][nextj]=1;
            q.push({nexti,nextj});
        }
       // printf("\n%d %d",i,j);
    }
    //printf("%d",Max);
    for(i=1; i<=Max; i++)
    {
        ans+=cou[i]*cou[i];
    }
    printf("%d\n",ans+1);
}
