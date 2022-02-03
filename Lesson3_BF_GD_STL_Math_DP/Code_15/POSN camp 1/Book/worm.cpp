/*
    TASK:worm
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
   int d,c;
   bool operator < (const A& o) const{
      return c < o.c;
   }
};
A arr[100100];
int main()
{
    int n,i;
    double sum=0,elec=0,Max=0,ans1,ans2;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d",&arr[i].d,&arr[i].c);
    sort(arr,arr+n);
    sum = arr[0].d,elec = arr[0].c;
    Max = sum/elec,ans1=sum,ans2=elec;
    for(i=1;i<n;i++){
        sum+=arr[i].d;
        if(arr[i].c>elec)elec=arr[i].c;
        if(sum/elec>Max)
            Max = sum/elec,ans1=sum,ans2=elec;
    }
    printf("%.0lf %.0lf\n",ans1,ans2);
}
