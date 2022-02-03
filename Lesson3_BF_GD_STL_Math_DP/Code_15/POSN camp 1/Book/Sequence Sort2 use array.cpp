/*
    TASK:Sequence Sort
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int m;
struct A{
   int a[15];
   bool operator< (const A& o) const{
      int i;
      for(i=0;i<m;i++){
        if(a[i]<o.a[i]) return true;
        else if(a[i]>o.a[i]) return false;
        else continue;
      }
   }
};
A ar[11000];
int main()
{

    int n,i,j,num;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&ar[i].a[j]);
        }
    }
    sort(ar,ar+n);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
        printf("%d ",ar[i].a[j]);
    printf("\n");
    }
    return 0;
}
