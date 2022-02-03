/*
    TASK:In Storm
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100],b[1000100],c[1000100];
int main()
{
    int n,i,now,ch=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    now=a[n];
    for(i=n-1;i>=1;i--){
        b[i]=now;
        if(a[i]>now)now=a[i];
        //printf("%d ",b[i]);
    }
    now=a[1];
    for(i=1;i<n;i++){
        if(a[i]>now)now=a[i];
        c[i]=now;
       // printf("%d ",c[i]);
    }
    /*printf("\n");
    for(i=1;i<=n-1;i++)printf("%d ",b[i]);
    printf("\n");*/

    for(i=1;i<n;i++){
            if(b[i]<=c[i]){printf("%d ",b[i]);continue;}
            if(b[i]>c[i]){printf("%d ",c[i]);continue;}
    }


    return 0;
}
/*
9
1 2 5 2 3 2 4 3 2
9
1 5 2 3 6 3 4 3 2
*/
