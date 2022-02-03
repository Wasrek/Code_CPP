/*
    TASK:treeinc
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int ma[300100];
vector< int > w[300100];
int main()
{
    int n,i,j,k,Max;
    scanf("%d",&n);
    int m=n-1;
    while(m--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
            w[a].push_back(b);
            w[b].push_back(a);
    }
    for(i=1; i<=n; i++)
    {
        for(k=0; k<w[i].size(); k++)
        {
            j=w[i][k];
            if(j>i)
            {
                if(ma[j]!=0)
                {
                    ma[j]=max(ma[j],ma[i]+1);
                    if(ma[j]>Max)
                        Max=ma[j];
                }
                else
                {
                    ma[j]=ma[i]+1;
                    if(ma[j]>Max)
                        Max=ma[j];
                }
            }
        }
    }
    printf("%d\n",Max+1);

    return 0;
}
/*
9
1 2
2 9
1 7
6 8
2 6
3 9
4 9
5 4
*/
