/*
    TASK:word
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    int i,j,st;
};
char a[30][30],s[20];
int di= {0,0,-1,-1,-1,1,1,1},dj= {-1,1,-1,0,1,-1,0,1},mark[30][30];
queue< q >;
int main()
{
    int n,r,c,i,j,q,v,t,len,k,o,ch=0;
    scanf("%d %d",&r,&c);
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            scanf(" %c",&a[i][j]);
            a[i][j]=tolower(a[i][j]);
        }
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf(" %s",s);
        len=strlen(s);
        for(k=0; k<r; k++)
        {
            for(o=0; o<c; o++)
            {
                if(a[k][o]==s[0])
                {
                    q.push({k,o,0});
                    while(!q.empty())
                    {
                        i=q.front().i,j=q.front().j,t=q.front().st;
                        q.pop();
                        if(t==len) {printf("%d %d",k,o);ch=1;break;}
                        for(v=0; v<8; v++)
                        {
                            nexti=i+di[v],nextj=j+dj[v];
                            if(nexti<0 || nextj<0 || nexti>=r || nextj>=c)
                                continue;
                            if(a[nexti][nextj]==1)
                                continue;
                            if(a[nexti][nextj]!=s[t+1])
                                continue;
                            q.push({nexti,nextj,t+1});
                        }
                    }
                }
            }
        }
        while(!q.empty())
            q.pop();
    }
    return 0;
}
