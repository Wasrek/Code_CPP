/*
    TASK:1class
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
stack<char> st;
char a[100];
int main()
{
    int len,c,d,n;
    gets(a);
    len=strlen(a);
    for(int i=0; i<len; i++)
    {
        if(isalnum(a[i]))
        {
            st.push(a[i]-'0');
        }
        else if('+' || '-' || '*' || '/')
        {
            c=st.top();
            st.pop();
            d=st.top();
            st.pop();
            if(a[i]=='-')
                st.push(c-d);
            else if(a[i]=='+')
                st.push(c+d);
            else if(a[i]=='*')
                st.push(c*d);
            else if(a[i]=='/')
                st.push(c/d);
        }
    }
    printf("%d\n",st.top());
}
