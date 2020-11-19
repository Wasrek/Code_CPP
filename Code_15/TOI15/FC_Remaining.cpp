/*
    TASK:FC_Remaining
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,ma,mi;
    scanf("%d %d",&n,&a);
    ma=a+(a/(n-1));
    if(a%(n-1)==0){
        mi=ma-1;
    }else mi=ma;
    printf("%d %d",mi,ma);
}
