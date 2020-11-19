/*
    TASK:Expogo
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
vector< char > ans;
int main()
{
    int q,Q,x,y,a,b,ch,la,ma,m;
    char now;
    scanf("%d",&Q);
    for(int q=1;q<=Q;q++){
        scanf("%d %d",&x,&y);
        ans.clear();
        a=abs(x);
        b=abs(y);
        if((a%2)==(b%2)){
            printf("Case #%d: IMPOSSIBLE\n",q);
            continue;
        }
        ch=1;
        for(int i=0;i<=30;i++){
            if(((1<<i) & a) || (((1<<i) & b))){
                ma=i;
                if((1<<i) & a){
                    m=1;
                }else{
                    m=2;
                }
            }
            if(((1<<i) & a) && (((1<<i) & b))){
                ch=0;
                m=3;
            }
            if((i==0) && !((1<<i) & a) && !(((1<<i) & b))){
                ch=0;
            }
        }
        printf("Case #%d: ",q);
        // printf("%d\n",m);
        if(ch){
            // printf("%d no\n",ma);
            for(int i=0;i<=ma;i++){
                if((1<<i) &a ){
                    if(ch==-1){
                        ans.push_back(now);
                        ch=0;
                    }
                    la=1;
                    if(x>=0){
                        ans.push_back('E');
                    }else{
                        ans.push_back('W');
                    }
                }else
                if((1<<i)&b){
                    if(ch==-1){
                        ans.push_back(now);
                        ch=0;
                    }
                    la=2;
                    if(y>=0){
                        ans.push_back('N');
                    }else{
                        ans.push_back('S');
                    }
                }else{
                    if(ch!=-1){
                    ans.pop_back();
                    ch=-1;
                    }
                    if(la==1){
                        if(x>=0){
                            ans.push_back('W');
                            now='E';
                        }else{
                            ans.push_back('E');
                            now='W';
                        }
                    }else{
                        if(y>=0){
                        ans.push_back('S');
                        now='N';
                        }else{
                        ans.push_back('N');
                        now='S';
                        }
                    }
                }
            }
            for(auto x: ans){
                printf("%c",x);
            }
            printf("\n");
            ans.clear();
            continue;
        }else{
            if(m==1){
                now=(1<<(ma+1))-b;
                b=now;
                ch=1;
                for(int i=0;i<=ma;i++){
                    if(((1<<i)&now) && ((1<<i)&a)){
                        ch=0;
                        break;
                    }
                }
                if(!ch){
                    printf("IMPOSSIBLE\n");
                }
                else{
            // printf("%d\n",ma);
                    for(int i=0;i<=ma;i++){
                        if((1<<i) &a ){
                            if(ch==-1){
                                ans.push_back(now);
                                ch=0;
                            }
                            la=1;
                            if(x>=0){
                                ans.push_back('E');
                            }else{
                                ans.push_back('W');
                            }
                        }else
                        if((1<<i)&b){
                            if(ch==-1){
                                ans.push_back(now);
                                ch=0;
                            }
                            la=2;
                            if(y>=0){
                                ans.push_back('S');
                            }else{
                                ans.push_back('N');
                            }
                        }else{
                            if(ch!=-1){
                            ans.pop_back();
                            ch=-1;
                            }
                            if(la==1){
                                if(x>=0){
                                    ans.push_back('W');
                                    now='E';
                                }else{
                                    ans.push_back('E');
                                    now='W';
                                }
                            }else{
                                if(y>=0){
                                ans.push_back('N');
                                now='S';
                                }else{
                                ans.push_back('S');
                                now='N';
                                }
                            }
                        }
                    }
                    if(y>=0){
                        ans.push_back('N');
                    }else{
                        ans.push_back('S');
                    }
                    for(auto h: ans){
                        printf("%c",h);
                    }
                    printf("\n");
                    ans.clear();
                }
            }else if(m==2){
                now=(1<<(ma+1))-a;
                a=now;
                ch=1;
                for(int i=0;i<=ma;i++){
                    if(((1<<i)&now) && ((1<<i)&b)){
                        ch=0;
                        break;
                    }
                }
                if(!ch){
                    printf("IMPOSSIBLE\n");
                }
                else{
            // printf("%d\n",ma);
                    for(int i=0;i<=ma;i++){
                        if((1<<i) &a ){
                            if(ch==-1){
                                ans.push_back(now);
                                ch=0;
                            }
                            la=1;
                            if(x>=0){
                                ans.push_back('W');
                            }else{
                                ans.push_back('E');
                            }
                        }else
                        if((1<<i)&b){
                            if(ch==-1){
                                ans.push_back(now);
                                ch=0;
                            }
                            la=2;
                            if(y>=0){
                                ans.push_back('N');
                            }else{
                                ans.push_back('S');
                            }
                        }else{
                            if(ch!=-1){
                            ans.pop_back();
                            ch=-1;
                            }
                            if(la==1){
                                if(x>=0){
                                    ans.push_back('E');
                                    now='W';
                                }else{
                                    ans.push_back('W');
                                    now='E';
                                }
                            }else{
                                if(y>=0){
                                ans.push_back('S');
                                now='N';
                                }else{
                                ans.push_back('N');
                                now='S';
                                }
                            }
                        }
                    }
                    if(x>=0){
                        ans.push_back('E');
                    }else{
                        ans.push_back('W');
                    }
                    for(auto h: ans){
                        printf("%c",h);
                    }
                    printf("\n");
                    ans.clear();
                }
            }else{
                now=(1<<(ma+1))-b;
                b=now;
                ch=1;
                // printf("here %d %d \n",b,a);
                for(int i=0;i<=ma;i++){
                    if(((1<<i)&now) && ((1<<i)&a)){
                        ch=0;
                        break;
                    }
                }
                if(!ch){
                ch=1;
                now=(1<<(ma+1))-a;
                a=now;
                for(int i=0;i<=ma;i++){
                    if(((1<<i)&now) && ((1<<i)&b)){
                        ch=0;
                        break;
                    }
                }
                if(!ch){
                    printf("IMPOSSIBLE\n");
                }
                else{
            // printf("%d\n",ma);
                    for(int i=0;i<=ma;i++){
                        if((1<<i) &a ){
                            if(ch==-1){
                                ans.push_back(now);
                                ch=0;
                            }
                            la=1;
                            if(x>=0){
                                ans.push_back('W');
                            }else{
                                ans.push_back('E');
                            }
                        }else
                        if((1<<i)&b){
                            if(ch==-1){
                                ans.push_back(now);
                                ch=0;
                            }
                            la=2;
                            if(y>=0){
                                ans.push_back('N');
                            }else{
                                ans.push_back('S');
                            }
                        }else{
                            if(ch!=-1){
                            ans.pop_back();
                            ch=-1;
                            }
                            if(la==1){
                                if(x>=0){
                                    ans.push_back('E');
                                    now='W';
                                }else{
                                    ans.push_back('W');
                                    now='E';
                                }
                            }else{
                                if(y>=0){
                                ans.push_back('S');
                                now='N';
                                }else{
                                ans.push_back('N');
                                now='S';
                                }
                            }
                        }
                    }
                    if(x>=0){
                        ans.push_back('E');
                    }else{
                        ans.push_back('W');
                    }
                    for(auto x: ans){
                        printf("%c",x);
                    }
                    printf("\n");
                    ans.clear();
                }
                }
                else{
            // printf("%d\n",ma);
                    // printf("here\n");
                    for(int i=0;i<=ma;i++){
                        if((1<<i) &a ){
                            if(ch==-1){
                                ans.push_back(now);
                                ch=0;
                            }
                            la=1;
                            if(x>=0){
                                ans.push_back('E');
                            }else{
                                ans.push_back('W');
                            }
                        }else
                        if((1<<i)&b){
                            if(ch==-1){
                                ans.push_back(now);
                                ch=0;
                            }
                            la=2;
                            if(y>=0){
                                ans.push_back('S');
                            }else{
                                ans.push_back('N');
                            }
                        }else{
                            if(ch!=-1){
                            ans.pop_back();
                            ch=-1;
                            }
                            if(la==1){
                                if(x>=0){
                                    ans.push_back('W');
                                    now='E';
                                }else{
                                    ans.push_back('E');
                                    now='W';
                                }
                            }else{
                                if(y>=0){
                                ans.push_back('N');
                                now='S';
                                }else{
                                ans.push_back('S');
                                now='N';
                                }
                            }
                        }
                    }
                    if(y>=0){
                        ans.push_back('N');
                    }else{
                        ans.push_back('S');
                    }
                    for(auto x: ans){
                        printf("%c",x);
                    }
                    printf("\n");
                    ans.clear();
                }
            }
        }
    }
    return 0;
}