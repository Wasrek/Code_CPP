/*
    TASK:Molar Mass
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
stack<int> st;
char a[150];
int main()
{
   int q,len,ch,i,coun,now,num,counb=0,sum;
    scanf("%d",&q);
    while(q--){
       scanf(" %s",a);
       len = strlen(a);
       for(i=0;i<len;i++)
       {
           if(a[i]=='('){st.push(-1);}
           else if(a[i]=='C'){st.push(12);}
           else if(a[i]=='H'){st.push(1);}
           else if(a[i]=='O'){st.push(16);}
           else if(a[i]==')')
           {
               counb=0;
               while(1){
               if(st.top()==-1){
                st.pop();
                  break;
               }else{
               counb+=st.top();
               st.pop();
               }
           }
           st.push(counb);
           }
           else if(!isalpha(a[i])){
            num=a[i]-'0';
            st.top()*=num;
           }
       }
       sum=0;
           while(!st.empty())
           {
               sum+=st.top();
               st.pop();
           }
        printf("%d\n",sum);
    }
}
