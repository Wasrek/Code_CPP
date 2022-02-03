/*
    TASK:FC_Power
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000];
int gcd(int i,int j){
   if(i%j==0) return j;
   return gcd(j,i%j);
}
int main()
{
    int n,q,i,j,k,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=2,k=0;i<=10000;i++){
            if(n%i==0){
                for(j=0;n%i==0;n/=i,j++);
                a[k++]=j;
            }
        }
            ans=a[0];
            for(i=1;i<k;i++)
                ans=gcd(ans,a[i]);
            if(ans==1 || n!=1) printf("NO\n");
            else printf("%d\n",ans);

    }
    return 0;
}
