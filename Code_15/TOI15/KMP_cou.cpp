/*
    TASK:Oh my god
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
    int lena,lenb,i,j=0,cou=0;
    scanf(" %s %s",a+1,b+1);
    lena=strlen(a+1),lenb=strlen(b+1);
    for(i=2;i<=lenb;i++){
        while(j>0 && b[j+1]!=b[i])j=pi[j];
        if(b[j+1]==b[i])j++;
        pi[i]=j;
    }
    for(i=1,j=0;i<=lena;i++){
        while(j>0 && b[j+1]!=a[i])j=pi[j];
        if(b[j+1]==a[i])j++;
        if(j==lenb){
            cou++;
        }
    }
    printf("%d\n",cou);
    return 0;
}
