/*
    TASK:55_Cards
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char s[20];
int main()
{
    int q,len,i,ans;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",s);
        len=strlen(s);
        ans=0;
        for(i=0;i<len;i++){
            if(s[i]=='J')ans++;
            else if(s[i]=='Q')ans+=2;
            else if(s[i]=='K')ans+=3;
            else if(s[i]=='A')ans+=4;
        }
        printf("%d\n",ans);
    }
    return 0;
}
