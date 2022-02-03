/*
    TASK:Milk
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int p[100100];
int findroot(int i){
   if(p[i]==i) return i;
   return p[i]=findroot(p[i]);
}
int main()
{
    int n,q,i,x,y;
    char a;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++) p[i]=i;
    while(q--){
        scanf(" %c %d %d",&a,&x,&y);
        if(a=='q'){
            if(findroot(x)==findroot(y))
                printf("yes\n");
            else
                printf("no\n");
        }
        else
            p[findroot(x)]=findroot(y);//x is under y
    }

    return 0;
}
