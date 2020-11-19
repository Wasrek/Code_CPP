/*
    TASK:48_Code Hunter
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100],b[1000100],m[1000100],ib[1000100],cou[1000100];
int main(){
    int q,n,i,j,ma,mi;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(i=1;i<=n;i++){
            scanf("%d",&b[i]);
            ib[b[i]]=i;
        }
        ma=0;
        for(i=1;i<=n;i++){
            if(ib[a[i]]<i){
                m[i]=ib[a[i]]+n-i;
            }else{
            m[i]=ib[a[i]]-i;
            }
            cou[m[i]]++;
        }
        //for(i=1;i<=n;i++)printf("%d ",m[i]);
        //printf("\n");
        ma=0;
        for(i=0;i<n;i++){
            if(cou[i]>ma){
                ma=cou[i];
                mi=i;
            }
        }
        printf("%d %d\n",ma,mi);
        memset(cou,0,sizeof cou);
    }
}
/*
2
4
1 3 4 2
3 4 1 2
10
9 10 6 4 3 2 7 1 5 8
4 3 9 1 5 10 6 7 8 2
*/
