/*
    TASK:
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[1000100],b[1000100];
int p[1000100];
int main(){
    gets(a+1),gets(b+1);
    int lena,lenb,i,j=0;
    lena=strlen(a+1),lenb=strlen(b+1);
    for(i=2;i<=lenb;i++){
        while(j>0 && b[j+1]!=b[i])j=p[j];
        if(b[j+1]==b[i])j++;
        p[i]=j;
    }
    for(i=1,j=0;i<=lena;i++){
        while(j>0 && b[j+1]!=a[i])j=p[j];
        if(b[j+1]==a[i])j++;
        if(j==lenb)printf("Lucky");
    }
}
