/*
    TASK:Parenthesis
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
stack<char> st;
char c[150];
int main()
{
    int q,i,len,ch=1;
    scanf("%d",&q);
    while(q--)
    {
        scanf(" %s",c);
        len=strlen(c);
        //printf("k");
        ch=1;
        for(i=0; i<len; i++)
        {
            if(c[i]=='(' || c[i]=='[')
                st.push(c[i]);
            else{
                if(c[i]==')' && (st.empty()||st.top()!='(')){
                    ch=0;break;
                }
                if(c[i]==']' && (st.empty()||st.top()!='[')){
                    ch=0;break;
                }
                st.pop();

            }
        }
        if(st.empty()&&ch)
        printf("Yes\n");
    else
        printf("No\n");
    while(!st.empty())
        st.pop();
    }
    return 0;
}
