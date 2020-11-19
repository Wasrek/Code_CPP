/*
    TASK:RT_Card Deck
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char s[1050];
int mark[5][15];
int main(){
    int i,len,now,p,k,t,h;
    p=k=h=t=13;
    scanf(" %s",s+1);
    len=strlen(s+1);
    for(i=1;i<=len;i+=3){
        now=(s[i+1]-'0')*10+(s[i+2]-'0');
        if(s[i]=='P'){
            p--;
            if(mark[1][now]){
                printf("Wrong");
                return 0;
            }
            mark[1][now]=1;
        }else
        if(s[i]=='K'){
            k--;
            if(mark[2][now]){
                printf("Wrong");
                return 0;
            }
            mark[2][now]=1;
        }else
        if(s[i]=='H'){
            h--;
            if(mark[3][now]){
                printf("Wrong");
                return 0;
            }
            mark[3][now]=1;
        }else
        if(s[i]=='T'){
            t--;
            if(mark[4][now]){
                printf("Wrong");
                return 0;
            }
            mark[4][now]=1;
        }
    }
    printf("%d %d %d %d\n",p,k,h,t);
}
