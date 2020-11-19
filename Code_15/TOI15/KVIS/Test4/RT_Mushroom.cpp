/*
    TASK:RT_Mushroom
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
map<int,int> mpx,mpy;
map<pair<int,int>,int> mp1,mp2;
int main()
{
    int n,k,i,j,x,y,ch=1,ans,m,c;
    pair<int,int> temp;
    scanf("%d %d",&n,&k);
    for(i=1; i<=n; i++)
    {
        scanf("%d %d",&x,&y);
        if(ch)
        {
            mpx[x]++;
            mpy[y]++;
            if(mpx[x]==k)
            {
                ch=0;
                ans=i;
            }
            if(mpy[y]==k)
            {
                ch=0;
                ans=i;
            }
            temp.first=1;
            temp.second=(y+x-1);
            mp1[temp]++;
            if(mp1[temp]==k)
            {
                ch=0;
                ans=i;
            }
            temp.first=1;
            temp.second=(y-x-1);
            mp2[temp]++;
            if(mp2[temp]==k)
            {
                ch=0;
                ans=i;
            }
        }
    }
    if(ch)
    {
        printf("%-1\n");
    }else {
        printf("%d\n",ans);
    }
    return 0;
}
