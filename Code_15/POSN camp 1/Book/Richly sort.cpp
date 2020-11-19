/*
    TASK:Richly sort
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
   int x,y;
   bool operator < (const A& o)const{
      if(x!=o.x) return x<o.x;//x<o.x true
      return y>o.y;
   }
};
A arr[100100];
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d",&arr[i].x,&arr[i].y);
    sort(arr,arr+n);
    for(i=0;i<n;i++)
    {
        printf("%d %d\n",arr[i].x,arr[i].y);
    }
    return 0;
}
