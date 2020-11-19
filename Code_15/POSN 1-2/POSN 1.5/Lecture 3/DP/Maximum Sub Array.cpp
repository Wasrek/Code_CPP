/*
    TASK:Maximum Sub Array
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[550][550],qs[550][550],dp[550];
int main()
{
    int n,i,j,s,sum=0,Max=-1e9;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            qs[i][j]=a[i][j]+qs[i][j-1];
        }
    }
    for(s=1;s<=n;s++){//size (height)
        for(j=1;j<=n-s+1;j++){//starting point
            for(i=1;i<=n;i++){//width
                sum+=(qs[i][j+s-1]-qs[i][j-1]);
                if(sum>Max)Max=sum;
                if(sum<0)sum=0;

            }
            sum=0;
        }
    }
    printf("%d\n",Max);

    return 0;
}
/*
4
0 -2 7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2
3
3 -1 -2
5 -5 9
-1 2 -4
*/
