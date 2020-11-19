/*
    TASK: Q_Jelly Bean
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main()
{
    int q,r,c,i,j,n;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&j,&n);
        for(i=0;i<n;i++){
            scanf("%d %d",&r,&c);
            a[i]=r*c;
        }
        sort(a,a+n,greater<int>());
        for(i=0;i<n;i++){
            j-=a[i];
            if(j<=0){
                printf("%d\n",i+1);break;
            }
        }
    }
}
