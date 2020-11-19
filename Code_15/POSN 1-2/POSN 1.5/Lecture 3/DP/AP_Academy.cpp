/*
    TASK:AP_Academy
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int i[1000100],o[1000100];
int main()
{
    int n,Max=0,a,b,j,q,t;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&a,&b);
        i[a]++;
        o[b]++;
        if(b>Max)Max=b;
    }
    for(j=1;j<=1000000;j++){
        i[j]+=i[j-1];
        o[j]+=o[j-1];
        //printf("%d ",i[j]);
    }
   // printf("\n");
    //for(j=1;j<=Max;j++){
      //  printf("%d ",o[j]);
    //}
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&a,&b);
        t=i[b]-o[a-1];
        printf("%d\n",t);
    }

    return 0;
}
/*
4
1 4
3 5
4 8
7 10
4
4 4
*/
