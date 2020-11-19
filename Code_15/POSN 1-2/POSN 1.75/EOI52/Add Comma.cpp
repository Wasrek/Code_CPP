/*
    TASK:Add Comma
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[110];
int main()
{
    int n,len;
    scanf("%d",&n);
    while(n--){
        long long cou=0;
        scanf(" %s",a+1);
        len=strlen(a+1);
        int b,c=1,i;
        b=len%3;
        if(b!=0){
        c=b+1;
        for(i=1;i<=b;i++){
            printf("%c",a[i]);
        }
        if(len>3)
        printf(",");
        }
        for(i=c;i<=len;i++){
            printf("%c",a[i]);
            cou++;
            if(cou%3==0 && i!=len)printf(",");
        }
        printf("\n");
    }

    return 0;
}
