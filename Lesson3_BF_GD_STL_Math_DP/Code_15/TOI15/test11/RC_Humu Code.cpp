/*
    TASK:RC_Humu Code
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char s[1000100],p[1000100],mark[1000100],fw[1000100],ch[1000100];
vector<char> ans[1000100];
int main(){
    gets(s+1);
    int i,len=strlen(s+1),m=0,now,mm,q,qm;
    for(i=1;i<=len;i++){
//        printf("%c",s[i]);
        if(s[i]=='.')m++;
        if(s[i]==' ')s[i]='_';
    }
    mm=m;
    int j=0;
    //printf("%d\n",len);
    for(i=1;i<=len;i++){
        j++;
        if(j>m)j%=m;
        while(mark[j]){j++;if(j>m)j%=m;}
        ans[j].push_back(s[i]);
        if(s[i]=='.')mark[j]=1;
    }
    for(i=1;i<=mm;i++){
        for(auto x:ans[i]){
            printf("%c",x);
        }
        printf("\n");
    }
//    for(auto x:ans[1]){
//        printf("%c",x);
//    }
//    printf("\n");
}
