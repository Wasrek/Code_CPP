/*
    TASK: FC_Stock
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000050],s[1000050];
int main()
{
   int n,q,i,f,l;
   scanf("%d %d",&n,&a[1]);
   s[1]=a[1];
   for(i=2;i<=n;i++){
    scanf("%d",&a[i]);
    if(a[i]>a[i-1]){
    s[i]=s[i-1]+(a[i]-a[i-1]);
    }else
    s[i]=s[i-1];
   }
   scanf("%d",&q);
   while(q--){
        scanf("%d %d",&f,&l);
        printf("%d\n",s[l]-s[f]);
   }
}
