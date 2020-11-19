/*
    TASK:RT_Group Manage
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[3100];
int main(){
    int n,i,j,maxx,minn,cou=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++){
        maxx=minn=a[i];
        for(j=i;j<=n;j++){
            maxx=max(maxx,a[j]);
            minn=min(minn,a[j]);
            if(j-i+1==maxx-minn+1)
                cou++;
        }
    }
    printf("%d\n",cou);
    return 0;
}
