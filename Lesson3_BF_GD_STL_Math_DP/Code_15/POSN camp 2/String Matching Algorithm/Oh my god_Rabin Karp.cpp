/*
    TASK:Oh my god
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000003
char a[mod+10],b[mod+10];
int main(){
    int lena,lenb,ha=0,hb=0,num=1,i,j;
    scanf(" %s %s",a,b);
    lena=strlen(a),lenb=strlen(b);
    for(i=0;i<lenb;i++){
        ha = (ha*29+(a[i]-'0'))%mod;
        hb = (hb*29+(b[i]-'0'))%mod;//เปลี่ยนอักษรให้เป็นเลขให้มันเป็นเลขฐาน29โดยใช้วิธีชักลบบวกๆ
    }
    for(i=0;i<lenb-1;i++)
        num = (num*29)%mod;
    for(i=0;i<lena-lenb;i++){
        if(ha==hb){
            for(j=0;j<lenb;j++){
                if(b[j]!=a[i+j])
                    break;
            }
            if(j==lenb){
                printf("Lucky\n");
                return 0;
            }
        }
        ha-=(num*(a[i]-'0'))%mod;
        if(ha<0)ha+=mod;
        ha = (ha*29)%mod;
        ha = (ha+(a[i+lenb]-'0'))%mod;
    }
    printf("Unlucky\n");
    return 0;
}
