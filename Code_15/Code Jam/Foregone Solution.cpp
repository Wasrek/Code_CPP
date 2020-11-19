/*
    TASK:Foregone Solution
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[110],b[110],c[110];
int main(){
    int q,len,i,chb,chc,t;
    scanf("%d",&t);
    for(q=1;q<=t;q++){
        scanf(" %s",a+1);
        len=strlen(a+1);
        if(a[len]=='5')b[len]='3',c[len]='2';
        else
        if(a[len]=='0'){
            b[len]='0';
            c[len]='0';
        }else
        {
        b[len]=a[len]-1;
        c[len]='1';
        }
        for(i=1;i<len;i++){
            if(a[i]=='4'){
                b[i]='3';
                c[i]='1';
            }else {
            b[i]=a[i];
            c[i]='0';
            }
        }
        printf("Case #%d: ",q);
        chb=0;
        for(i=1;i<=len;i++){
            if(b[i]!='0')chb=1;
            if(chb)printf("%c",b[i]);
        }
        printf(" ");
        chc=0;
        for(i=1;i<=len;i++){
            if(c[i]!='0')chc=1;
            if(chc)printf("%c",c[i]);
        }
        printf("\n");
    }
    return 0;
}
