/*
    TASK:Palindromic Matrix
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int coun[1005],ans[30][30];
int main()
{
    int n,i,j,k,a;-
    scanf("%d",&n);
    for(i=0;i<n*n;i++)
    {
        scanf("%d",&a);
        coun[a]++;
    }
    int coun1=0,coun2=0,coun3=0,coun4=0;
    for(i=1;i<=1000;i++)
    {
        if(coun[i]%4==0);
        else if(coun[i]%4==1)
            coun2++;
        else if(coun[i]%4==2)
            coun4++;
        else
            coun2++,coun4++;
    }
    if(coun2>n%2||(n%2==0&&coun4)||(n%2==1&&coun4>n-1))
    {
        printf("NO");
        return 0;
    }
    for(i=0;i<n/2;i++)
    {
        for(j=0;j<n/2;j++)
        {
            for(k=1;k<=1000;k++)
            {
                if(coun[k]>=4)
                {
                    ans[i][j]=k;
                    ans[n-i-1][j]=k;
                    ans[i][n-j-1]=k;
                    ans[n-i-1][n-j-1]=k;
                    coun[k]-=4;
                    break;
                }
            }
        }
    }
    if(n%2)
    {
        for(i=0;i<n/2;i++)
        {
            for(k=1;k<=1000;k++)
            {
                if(coun[k]>=2)
                {
                    ans[i][n/2]=k;
                    ans[n-i-1][n/2]=k;
                    coun[k]-=2;
                    break;
                }
            }
        }
        for(i=0;i<n/2;i++)
        {
            for(k=1;k<=1000;k++)
            {
                if(coun[k]>=2)
                {
                    ans[n/2][i]=k;
                    ans[n/2][n-i-1]=k;
                    coun[k]-=2;
                    break;
                }
            }
        }
        for(k=1;k<=1000;k++)
            if(coun[k])
                ans[n/2][n/2]=k,coun[k]--;
    }
    printf("YES\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",ans[i][j]);
        printf("\n");
    }
    return 0;
}
