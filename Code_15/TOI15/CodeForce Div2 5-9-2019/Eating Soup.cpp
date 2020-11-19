/*
    TASK:Eating Soup
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,t,mo;
    scanf("%d %d",&n,&m);
    if(m==0){
        printf("1\n");
        return 0;
    }
    if(n==m){
        printf("0\n");
        return 0;
    }
    t=n/2;
    if(m>t){
        if(n%2)t++;
        if(m-t>0){
            printf("%d\n",n/2-(m-t));
        }else{
            printf("%d\n",n/2);
        }
    }else{
        printf("%d\n",m);
        return 0;
    }
}
