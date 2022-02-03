/*
    TASK:easy
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[100100],b[100100],c[100100];
int main()
{
    int lena,lenb;
    scanf(" %s",a+1);
    lena=strlen(a+1);
    scanf(" %s",b+1);
    lenb=strlen(b+1);
    for(int i=1;i<=lena/2;i++){
        swap(a[i],a[lena-i+1]);
    }
    for(int i=1;i<=lenb/2;i++){
        swap(b[i],b[lenb-i+1]);
    }
    // printf("%s\n",a+1);
    // printf("%s\n",b+1);
    for(int i=1;i<=max(lena,lenb);i++){
        a[i]-='0';
        b[i]-='0';
        if(i>lena)a[i]=0;
        if(i>lenb)b[i]=0;
        c[i]+=a[i]+b[i];
        // printf("%d %d %d\n",a[i],b[i],c[i]);
        if(c[i]>9){
            c[i+1]=c[i]/10;
            c[i]%=10;
        }
    }
    if(c[max(lena,lenb)+1]!=0) printf("%d",c[max(lena,lenb)+1]);
    for(int i=max(lena,lenb);i>=1;i--){
        printf("%d",c[i]);
    }
    return 0;
}