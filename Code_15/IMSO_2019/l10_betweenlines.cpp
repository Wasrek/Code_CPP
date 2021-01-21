/*
    TASK:betweenlines
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[10100];
int main(){
    int n,i,w=0,u=0,m=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==13)m++;
        if(a[i]==10){
            u++;
            if(a[i-1]==13)w++;
        }
    }
    printf("%d\n",w+1);
    printf("%d\n",u+1);
    printf("%d\n",m+1);
}