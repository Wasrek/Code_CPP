/*
    TASK:Drone_Survey
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,peat=1,a;
    char opr,tid;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf(" %c %c %d",&opr,&tid,&a);
        if(opr=='M'){
            if(tid=='A') peat+=a,peat%=n;
            if(tid=='B') peat=((peat-a)%n+n)%n;
        }
        if(opr=='Q'){
            if(tid=='A'){
                if((peat+a)%n==0) printf("%d\n",n);
                else printf("%d\n",(peat+a)%n);
            }
            if(tid=='B'){
                if(((peat-a)%n+n)%n==0) printf("%d\n",n);
                else printf("%d\n",((peat-a)%n+n)%n);
            }
        }
    }
}
