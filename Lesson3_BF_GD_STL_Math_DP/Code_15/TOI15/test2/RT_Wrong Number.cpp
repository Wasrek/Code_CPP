/*
    TASK:RT_Wrong Number
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,sum=0,num,mod,nn;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&num);
        mod=num%10;
        num/=10;
        nn=1;
        while(mod--){
            nn*=num;
        }
        sum+=nn;
    }
    printf("%d\n",sum);
}
