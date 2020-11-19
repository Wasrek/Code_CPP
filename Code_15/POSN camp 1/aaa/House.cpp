/*
    TASK:House
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[310][310];
int main()
{
    int r,c,k,i,j,s,t,sum,Max=-100000;
    scanf("%d %d %d",&r,&c,&k);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        scanf("%d",&a[i][j]);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            sum=a[i][j];
            for(s=i-1,t=0;s>=0 && t<k;s--,t++){
                if(t%2==0) sum-=a[s][j];
                else sum+=a[s][j];
            }//n
            for(s=i+1,t=0;s<r && t<k;s++,t++){
                if(t%2==0) sum-=a[s][j];
                else sum+=a[s][j];
            }//s
            for(s=j-1,t=0;s>=0 && t<k;s--,t++){
                if(t%2==0) sum-=a[i][s];
                else sum+=a[i][s];
            }//e
            for(s=j+1,t=0;s<c && t<k;s++,t++){
                if(t%2==0) sum-=a[i][s];
                else sum+=a[i][s];
            }
            if(sum>Max) Max=sum;
        }
    }
    printf("%d\n",Max);
    return 0;
}
