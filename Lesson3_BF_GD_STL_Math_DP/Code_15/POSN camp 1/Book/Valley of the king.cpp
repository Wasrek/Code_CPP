/*
    TASK:Valley of the king
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010],b[1010];
int main()
{
    int q,i,n,ans,j;
    scanf("%d",&q);
    while(q--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for(i=0,j=0,ans=0;i<n; ){
        if(a[i]==a[i+1])//same
            ans++,i+=2;
        else
            b[j++] = a[i],i++;
    }

    printf("%d\n",ans);
    if(j==0)
    {
        printf("Empty\n");
    }
    else{
    for(i=0;i<j;i++)
    {
        printf("%d ",b[i]);
    }
    }
    }
    return 0;
}
/* 2
15
3 5 3 2 3 6 3 4 7 2 4 3 5 3 4*/
