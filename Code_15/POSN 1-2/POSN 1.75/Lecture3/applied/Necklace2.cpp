/*
    TASK:Necklace2
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[200200],b[200200];
int fb[200200],fr[200200],bb[200200],br[200200];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",&a[1]);
    strcpy(b,&a[1]);
    strcat(&a[1],b);
    int x=2*n;
    int i;
    for(i=1; i<=x; i++)
    {
        if(a[i]=='w')
        {
            fb[i]=fb[i-1]+1;
            fr[i]=fr[i-1]+1;
        }
        else if(a[i]=='r')
        {
            fr[i]=fr[i-1]+1;
            fb[i]=0;
        }
        else if(a[i]=='b')
        {
            fb[i]=fb[i-1]+1;
            fr[i]=0;
        }
    }
    for(i=x; i>=1; i--)
    {
        if(a[i+1]=='w')
        {
            bb[i]=bb[i+1]+1;
            br[i]=br[i+1]+1;
        }
        else if(a[i+1]=='r')
        {
            br[i]=br[i+1]+1;
            bb[i]=0;
        }
        else if(a[i+1]=='b')
        {
            bb[i]=bb[i+1]+1;
            br[i]=0;
        }
    }
    int ans=0;
    for(i=1;i<=n;i++){
        ans=max(ans,max(fr[i],fb[i])+max(br[i],bb[i]));
    }
    ans=min(ans,n);
    printf("%d\n",ans);
}
