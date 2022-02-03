/*
    TASK:Number
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[500010],start=0,kwa=1,n,m;
int fin(int l){
   if(kwa) return (start+l-1)%n;
   else return (start-l+1+n)%n;
}
int main()
{
    int i,x,y,j,k;
    char opr;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<m;i++){
        scanf(" %c",&opr);
        if(opr=='a'){
            scanf("%d %d",&x,&y);
            j=fin(x),k=fin(y);
            swap(a[j],a[k]);
        }
        else if(opr=='b'){
            scanf("%d %d",&x,&y);
            a[fin(x)]=y;
        }
        else if(opr=='c'){
            scanf("%d",&x);
            start=fin(x);
            kwa^=1;
        }
        else if(opr=='q'){
            scanf("%d",&x);
            printf("%d\n",a[fin(x)]);
        }
    }
    return 0;
}
