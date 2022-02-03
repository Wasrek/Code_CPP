/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 2005
int qs[2][N];
int sum[2][N];
int lvl[2][N];
int maxpeak[2][N];
char str[2][N];
int main()
{
    int n,m,nowlvl,nowsum,nowqs,ans1=0,ans2=0,ans3=0;
    scanf("%d %d",&m,&n);
    for(int i=1;i<=n+1;i++)
    {
        if(i<=n)    scanf(" %s",str[i%2]+1);
        else
        {
            for(int j=1;j<=m;j++)   str[i%2][j]='0';
        }
        for(int j=1;j<=m;j++)
        {
            if(str[i%2][j]=='1')    qs[i%2][j]=qs[i%2][j-1]+1;
            else                    qs[i%2][j]=0,lvl[i%2][j]=0,sum[i%2][j]=0,maxpeak[i%2][j]=0;
        }
        for(int j=m;j>=1;)
        {
            if(str[i%2][j]!='1')
            {
                j--;
                continue;
            }
            int nowmaxpeak;
            nowlvl=nowsum=0;
            nowqs=nowmaxpeak=qs[i%2][j];
            int k;
            for(k=j;k>=1&&str[i%2][k]=='1';k--) nowmaxpeak=max(nowmaxpeak,maxpeak[(i-1)%2][k]),nowlvl=max(nowlvl,lvl[(i-1)%2][k]),nowsum=max(nowsum,sum[(i-1)%2][k]);
            for(k=j;k>=1&&str[i%2][k]=='1';k--) maxpeak[i%2][k]=nowmaxpeak,lvl[i%2][k]=nowlvl+1,sum[i%2][k]=nowsum+nowqs,qs[i%2][k]=nowqs;
            j=k;
        }
        for(int j=m;j>=1;)
        {
            if(str[(i-1)%2][j]!='1')
            {
                j--;
                continue;
            }
            int k,ch=0;
            for(k=j;k>=1&&str[(i-1)%2][k]=='1';k--)
            {
                if(str[i%2][k]=='1')    ch=1;
            }
            if(!ch)
            {
                if(sum[(i-1)%2][j]==lvl[(i-1)%2][j]*lvl[(i-1)%2][j])
                {
                    if(qs[(i-1)%2][j]==lvl[(i-1)%2][j]) ++ans1;
                    else                                ++ans3;
                }
                else if(maxpeak[(i-1)%2][j]*maxpeak[(i-1)%2][j]==sum[(i-1)%2][j])   ++ans3;
                else
                {
                    ++ans2;
                }
            }
            j=k;
        }
    }
    printf("%d %d %d\n",ans1,ans2,ans3);
    return 0;
}
/*
20 12
00000000000000000000
10000000001111111110
11000100000111111100
11101110000011111000
11000000000001110000
10000000000000100000
00000000000000000000
11111000000000100000
11111000000001110000
11111000000011111000
11111000000001110000
11111000000000100000
*/
