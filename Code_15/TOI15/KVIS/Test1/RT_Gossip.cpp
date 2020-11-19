/*
    TASK:RT_Gossip
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[110],p[110];
int main(){
    int q,i,j,len,ch,l,pp;
    scanf("%d",&q);
    scanf(" %s",p+1);
    l=strlen(p+1);
    while(q--){
        ch=1;
        scanf(" %s",a+1);
        len=strlen(a+1);
        for(i=1;i<=len;i++){
            if(p[i]=='*'){
                break;
            }
            if(a[i]!=p[i]){
                ch=0;
                break;
            }
            a[i]='0';
        }
        if(!ch){printf("No\n");continue;}
        for(i=len,j=l;i>=1,j>=1;i--,j--){
            if(p[j]=='*')break;
            if(a[i]!=p[j]){ch=0;break;}
        }
        if(!ch){printf("No\n");continue;}
        printf("Yes\n");
    }
    return 0;
}
