/*
    TASK:Swift Substring
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
#define md 1000010
char a[md],b[md];
int pi[md];
int main(){
    int lena,lenb,i,j,cou,q,ch,k;
    scanf("%d",&q);
    while(q--){
    j=0,cou=0;
    scanf(" %s %s",a+1,b+1);
    lena=strlen(a+1),lenb=strlen(b+1);
    i=1,ch=0;
    for(j=1;j<=lenb;j++){
    if(a[i]==b[j]){
        if(i==lena){ch=1;break;}
        i++;//printf("%d ",j);
    }
    }
    if(ch)printf("Yes\n");
    else printf("No\n");
    }
    return 0;
}
