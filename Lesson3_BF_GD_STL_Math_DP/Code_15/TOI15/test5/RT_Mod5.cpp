/*
    TASK:RT_Mod5
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char s[100010];
int main(){
    int i,q,len;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",s+1);
        len=strlen(s+1);
        i=(s[len-1]*10)+s[len];
        if(i%4)printf("0\n");
        else printf("4\n");
    }
}
