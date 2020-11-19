/*
    TASK:RT_Pizza
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[20];
int main(){
    int i,ma=0;
    for(i=1;i<=8;i++){
        scanf("%d",&a[i]);
        a[8+i]=a[i];
    }
    for(i=1;i<=16;i++){
        a[i]+=a[i-1];
        if(i-4>=0){
            ma=max(ma,a[i]-a[i-4]);
        }
    }
    printf("%d\n",ma);
}
