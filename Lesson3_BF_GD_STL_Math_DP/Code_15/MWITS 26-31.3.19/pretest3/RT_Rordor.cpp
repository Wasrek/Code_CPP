/*
    TASK:RT_Rordor
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[10100];
int main(){
    int cou=0,len,i;
    scanf(" %s",a);
    len=strlen(a);
    for(i=0;i<len;i++){
        if(a[i]=='L'){
            cou+=3;
            cou%=4;
        }else
        if(a[i]=='R'){
            cou++;
            cou%=4;
        }else
        if(a[i]=='B'){
            cou+=2;
            cou%=4;
        }
    }
    if(cou==0)printf("N");
    else if(cou==1)printf("E");
    else if(cou==2)printf("S");
    else if(cou==3)printf("W");
    return 0;
}
