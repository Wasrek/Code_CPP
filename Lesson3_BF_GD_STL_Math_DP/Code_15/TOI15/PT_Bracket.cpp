/*
    TASK:PT_Bracket
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue< long long > h;
char s[50100];
int main(){
    long long q,len,cou,a,b,ans,i,ch=0;
    scanf("%lld",&q);
    while(q--){
        scanf(" %s",s);
        cou=0;
        ch=0;
        ans=0;
        len=strlen(s);
        for(i=0;i<len;i++){
            if(s[i]=='(')cou++;
            else
            if(s[i]=='?'){
                scanf("%lld %lld",&a,&b);
                cou--;
                h.push(b-a);
                ans+=b;
            }else
            if(s[i]==')')cou--;
            if(cou==-1){
                if(!h.empty()){
                ans-=h.top();
                h.pop();
                cou+=2;
                }else{
                printf("-1\n");
                while(!h.empty())h.pop();ch=1;
                break;
                }
            }
            //printf("%d\n",cou);
        }
        //printf("%d %d\n",ans,cou);
        if(ch)continue;
        if(cou==0)
        printf("%lld\n",ans);
        else printf("-1\n");
        while(!h.empty())h.pop();
    }
}
