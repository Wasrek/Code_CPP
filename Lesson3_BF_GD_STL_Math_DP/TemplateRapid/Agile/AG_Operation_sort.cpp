/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int f,b;
};
char a[3010];
int r[3010];
stack < A > st;
bool isoper(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/') return true;
    return false;
} 
int main()
{
    int q,len,pt;
    A op1,op2;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",a+1);
        len=strlen(a+1);
        for(int i=len;i>=1;i--){
            if(isoper(a[i])){
                op1=st.top(); st.pop();
                op2=st.top(); st.pop();
                r[op1.b]=op2.f;
                r[op2.b]=i;
                st.push({op1.f,i});
            }else{
                st.push({i,i});
            }
        }
        pt=st.top().f;
        while(pt!=0){
            printf("%c",a[pt]);
            pt=r[pt];
        }
        printf("\n");
        while(!st.empty()) st.pop();
        memset(a,0,sizeof a);
    }
    return 0;
}