/*
    TASK:NC_Cheese Sausage
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}
int main(){
    int a,b,w;
    scanf("%d %d",&a,&b);
    w=b-gcd(b,a);
    printf("%d\n",w);
}
