/*
    TASK:fighter
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000100];
int main()
{
    int n,k,i,cou=0,last=-1,even=0,odd=0;
    scanf("%d",&n);
    k=2*n;
    for(i=1; i<=k; i++)
    {
        scanf("%d",&dp[i]);
        if(dp[i]%2==0)
        {
            if(last==-1 || last==0){
                cou++,last=0;
                }
                else
                {
                    cou=1,last=0;
                }
            if(cou>=3)
                odd+=3;
                     else
                         odd++;
        }
        if(dp[i]%2==1)
        {
           if(last==-1 || last==1){
                cou++,last=1;
                }
                else
                {
                    cou=1,last=1;
                }
            if(cou>=3)
                even+=3;
            else
                even++;
        }
        //printf("\neven:%d odd:%d l:%d\n",even,odd,cou);
        if(even>=n)
        {
            printf("1\n%d",dp[i]);
            return 0;
        }
        if(odd>=n)
        {
            printf("0\n%d",dp[i]);
            return 0;
        }
    }
    return 0;
}
/*
8
1 2 3 4 5 6 7 8 9 10 2 4 6 8 10 12
6
7 5 2 4 8 1 3 9 11 12 13 14
*/
