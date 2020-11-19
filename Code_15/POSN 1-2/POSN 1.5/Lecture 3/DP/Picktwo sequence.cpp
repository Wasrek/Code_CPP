/*
    TASK:Picktwo sequence
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],kr[100100],kl[100100],mr[100100],ml[100100];
int main()
{
    int q,i;
    scanf("%d",&q);
    while(q--)
    {
        int n,c,b,Max=-1e9;
        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            kr[i]=kr[i-1]+a[i];
            if(kr[i]<0)
            {
                kr[i]=0;
            }
            if(kr[i]>Max)Max=kr[i];
            mr[i]=Max;
        }
        Max=-1e9;
        for(i=n;i>=1;i--){
            kl[i]=kl[i+1]+a[i];
            if(kl[i]<0){
                kl[i]=0;
            }
            if(kl[i]>Max)Max=kl[i];
            ml[i]=Max;
        }
        /*for(i=1;i<=n;i++)printf("%d ",kr[i]);
        printf("\n");
        for(i=1;i<=n;i++)printf("%d ",mr[i]);
        printf("\n");
        for(i=1;i<=n;i++)printf("%d ",kl[i]);
        printf("\n");
        for(i=1;i<=n;i++)printf("%d ",ml[i]);*/
        Max=0;
        int h;
        for(i=1;i<=n;i++){
            if(mr[i]<0 && ml[i+1]>Max)Max=ml[i+1];
            if(ml[i+1]<0 && mr[i]>Max)Max=mr[i];
            h=ml[i+1]+mr[i];
            if(mr[i]>0 && ml[i+1]>=0 && h>Max)Max=h;
        }
        printf("%d\n",Max);
    }
}
