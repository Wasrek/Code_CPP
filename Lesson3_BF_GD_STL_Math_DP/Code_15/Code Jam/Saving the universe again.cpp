/*
    TASK:Saving the universe again
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[35];
int main(){
    int q,d,len,i,now,da,need;
    scanf("%d",&q);
    while(q--){
        scanf("%d %s",&d,a);
        len=strlen(a);
        now=1;da=0;
        for(i=0;i<len;i++){
            if(a[i]=='C')now*=2;
            else
            if(a[i]=='S')da+=now;
        }
        if(da<=d)printf("0\n");continue;
        need=da-d;
    }
}
