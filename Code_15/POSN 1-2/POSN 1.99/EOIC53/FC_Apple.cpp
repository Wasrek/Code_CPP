/*
    TASK:FC_Apple
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a%b==0)return b;
    else return gcd(b,a%b);
}
int main(){
    int r,g;
    scanf("%d %d",&r,&g);
    int Min=gcd(r,g);
    for(int i=1;i<=Min;i++){
        if(Min%i==0){
            printf("%d %d %d\n",i,r/i,g/i);
        }
    }
    return 0;
}
