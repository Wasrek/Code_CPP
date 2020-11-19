/*
    TASK:Gim jeong Wen
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100],b[1000100];
int main(){
    int n;
    scanf("%d",&n);
    int m,i;
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%d %d",&a[i],&b[i]);
    }
    a[m+1]=b[m+1]=n;
    sort(a+1,a+m+2);
    sort(b+1,b+m+2);
    //for(i=1;i<=m;i++)printf("%d ",a[i]);
    int Maxx=0,Maxy=0,Max=0;
    for(i=1;i<=m;i++){
        //printf("%d %d\n",a[i],b[i]);
        Maxx=max(a[i]-a[i-1],Maxx);
        Maxy=max(b[i]-b[i-1],Maxy);
    }
    Max=min(Maxx,Maxy);
   // printf("%d %d\n",Maxx,Maxy);
    printf("%.3lf\n",(double)Max/2);
}
/*
10
5
9 5
7 5
5 5
3 5
1 5
*/
