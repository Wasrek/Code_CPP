/*
    TASK:RC_Word Peatt
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char s[5010];
int main(){
    int n,cnt=0,p=0,len,i,ch;
    scanf("%d\n",&n);
    gets(s+1);
    len=strlen(s+1);
    //printf("%d\n",len);
    for(i=1;i<=len;i++){
        //printf("%d",i);
        p++;
        if(s[i]==' '){p=0;continue;}
        if(s[i]=='.' || s[i]=='?' || s[i]=='!'){
            printf("%d\n",cnt);
            cnt=0;
            continue;
        }
        ch=0;
        if(p==1 && s[i]>='A' && s[i]<='Z'){
            while(i+1<=len){
                if(s[i]>='0' && s[i]<='9'){ch=1;break;}
                if(s[i+1]==' ' || s[i+1]=='.' || s[i+1]=='?' || s[i+1]=='!')break;
                i++;
            }
            if(!ch)cnt++;
        }
    }
}
/*
2
An3 ant Peatty. Pen apple Pie pen!
*/
