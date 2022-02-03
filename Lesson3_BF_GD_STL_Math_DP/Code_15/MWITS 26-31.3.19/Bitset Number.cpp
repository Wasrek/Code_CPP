/*
    TASK:Bitset Number
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010],b[1010];
int main(){
    int cou1,cou2,lena,lenb,i,j;
    scanf(" %s",a);
    scanf(" %s",b);
    lena=strlen(a);
    lenb=strlen(b);
    for(i=0;i<lena;i++){
        if(a[i]=='1')cou1++;
    }
    for(i=0;i<lenb;i++){
        if(b[i]=='1')cou2++;
    }
    if(cou1%2==1)cou1++;
    if(cou1>=cou2)printf("YES");
    else printf("NO");
    return 0;
}
