#include<bits/stdc++.h>
using namespace std;
stack < int > st,st1;
int k[250000],g[250000];
int ks,gs,i,j,cou;
int main()
{
    scanf("%d %d",&ks,&gs);
    for(i=0;i<ks;i++)
    {
        scanf("%d",&k[i]);
        st.push(k[i]);
    }
     for(i=0;i<gs;i++)
    {
        scanf("%d",&g[i]);
        while(1){
        if(g[i]>st.top())
        {
        st.push(g[i]);
        break;
        }else
        if(g[i]<st.top())
        {
        st1.push(st.top());
        st.pop();
        }
        }
        while(!st1.empty())
        {
            st.push(st1.top());
            st1.pop();
        }
        cou=0;
    while(!st.empty())
        {
            cou++;
            if(g[i]==st.top())
            {
            printf("%d\n",cou);st.pop();break;
            }
        st1.push(st.top());
        st.pop();
        }
        while(!st1.empty())
        {
            st.push(st1.top());
            st1.pop();
        }
    }
}


/*
5 4
75
84
90
94
99
100
77
85
95*/
