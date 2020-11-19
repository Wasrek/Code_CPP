/*
    TASK:Intend find
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100];
int main()
{
   int i,n,q;
   scanf("%d %d",&n,&q);
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);
      sort(a,a+n);
   while(q--){
   scanf("%d",&i);
   printf("%d\n",upper_bound(a,a+n,i)-a);
   }
   return 0;
}
