/*
    TASK:Necklace2
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int fr[200100],fb[200100],br[200100],bb[200100];
char a[200100],b[200100];
int main()
{
    int n;
    scanf("%d",&n);
    scanf(" %s",a+1);
    strcpy(b,a+1);
    strcat(&a[1],b);
    // printf("here\n");
    int len=strlen(a+1);
    // printf("%d\n",len);
    for(int i=1;i<=len;i++){
        if(a[i]=='w'){
            fr[i]=fr[i-1]+1;
            fb[i]=fb[i-1]+1;
        }else
        if(a[i]=='r'){
            fr[i]=fr[i-1]+1;
            fb[i]=0;
        }else
        {
            fr[i]=0;
            fb[i]=fb[i-1]+1;
        }
        
    }
    for(int i=len;i>=1;i--){
        if(a[i]=='w'){
            br[i]=br[i+1]+1;
            bb[i]=bb[i+1]+1;
        }else
        if(a[i]=='r'){
            br[i]=br[i+1]+1;
            bb[i]=0;
        }else
        {
            br[i]=0;
            bb[i]=bb[i+1]+1;
        }
    }
    int ma=0;
    for(int i=1;i<=len;i++){
        ma=max(ma,max(fr[i],fb[i])+max(br[i+1],bb[i+1]));
    }
    ma=min(n,ma);
    printf("%d\n",ma);
    return 0;
}