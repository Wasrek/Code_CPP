/*
    TASK:counting sort
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100];
int main(){
    int n,b,j;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&b);
        a[b]++;
    }
    for(int i=1;i<=1000000;i++){
        j=a[i];
        while(j--){
            printf("%d ",i);
        }
    }
}
