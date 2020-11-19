/*
    TASK:Parenthesis
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
stack<char> st;
char a[1000];
int main()
{
    int q,len,ch,i;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",a);
        len = strlen(a);
        ch=1;
        for(i=0;i<len;i++){
            if(a[i]=='(' || a[i]=='[')
                st.push(a[i]);
            else{
                if(a[i]==')' && (st.empty()||st.top()!='(')){
                    ch=0;break;//we have to break immediately cause if their no any thing to pop then you pop it it will be bug
                }
                if(a[i]==']' && (st.empty()||st.top()!='[')){
                    ch=0;break;
                }
                st.pop();

            }
        }
        if(st.empty()&&ch)
        printf("Yes");
    else
        printf("No");
    while(!st.empty())
        st.pop();
    }
    return 0;
}
