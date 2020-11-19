/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[150],r[150];
int main()
{
    int t,b,now,no,fli,re,refli;
    char c;
    scanf("%d %d",&t,&b);
    if(b==10){
    while(t--){
        for(int i=1;i<=b;i++){
            printf("%d\n",i);
            fflush(stdout);
            scanf(" %c",&c);
            a[i]=c;
        }
        printf("%s\n",a+1);
        fflush(stdout);
        scanf(" %c",&c);
        if(c=='N')return 0;
    }
    return 0;
    }else {
        while(t--){
        for(int i=1;i<=5;i++){
            printf("%d\n",i);
            fflush(stdout);
            scanf(" %c",&c);
            a[i]=c;
            printf("%d\n",i+15);
            fflush(stdout);
            scanf(" %c",&c);
            a[i+15]=c;
        }
        for(int i=6;i<=10;i++){
            printf("%d\n",i);
            fflush(stdout);
            scanf(" %c",&c);
            a[i]=c;
            printf("%d\n",i+5);
            fflush(stdout);
            scanf(" %c",&c);
            a[i+5]=c;
        }
        // printf("%s\n",r+1);
        // for(int i=1;i<=20;i++)printf("%c",r[i]);
        no=1,fli=1,re=1,refli=1;
        for(int i=1;i<=5;i++){
            printf("%d\n",i);
            fflush(stdout);
            scanf(" %c",&c);
            if(a[i]!=c)no=0;
            if(a[21-i]!=c)re=0;
            if((a[i]^1)!=c)fli=0;
            if((a[21-i]^1)!=c)refli=0;
        }
        if(no){
            for(int i=1;i<=5;i++){
                r[i]=a[i];
                r[21-i]=a[21-i];
            }
        }else if(re){
            for(int i=1;i<=5;i++){
                r[i]=a[21-i];
                r[21-i]=a[i];
            }
        }else if(fli){
            for(int i=1;i<=5;i++){
                r[i]=a[i]^1;
                r[21-i]=a[21-i]^1;
            }
        }else{
            for(int i=1;i<=5;i++){
                r[i]=a[21-i]^1;
                r[21-i]=a[i]^1;
            }
        }
        no=1,fli=1,re=1,refli=1;
        for(int i=6;i<=10;i++){
            printf("%d\n",i);
            fflush(stdout);
            scanf(" %c",&c);
            if(a[i]!=c)no=0;
            if(a[21-i]!=c)re=0;
            if((a[i]^1)!=c)fli=0;
            if((a[21-i]^1)!=c)refli=0;
        }
        if(no){
            for(int i=6;i<=10;i++){
                r[i]=a[i];
                r[21-i]=a[21-i];
            }
        }else if(re){
            for(int i=6;i<=10;i++){
                r[i]=a[21-i];
                r[21-i]=a[i];
            }
        }else if(fli){
            for(int i=6;i<=10;i++){
                r[i]=a[i]^1;
                r[21-i]=a[21-i]^1;
            }
        }else{
            for(int i=6;i<=10;i++){
                r[i]=a[21-i]^1;
                r[21-i]=a[i]^1;
            }
        }
        printf("%s\n",r+1);
        fflush(stdout);
        scanf(" %c",&c);
        if(c=='N')return 0;
        }
    }
    return 0;
}