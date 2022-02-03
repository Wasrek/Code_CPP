#include<bits/stdc++.h>
using namespace std;
char tree[300];
int l[300],r[300];
char str[300];
stack< int > st;
void pre(int i){
   if(tree[i]==NULL) return ;
   printf("%c",tree[i]);
   pre(l[i]);
   pre(r[i]);
}
int main(){
    gets(str);
    int len;
    len=strlen(str);
    int i,j,x,y,t;
    for(i=0;i<len;i++){
        if(str[i]==' ')continue;
        if(isalpha(str[i])){
            st.push(i);
            tree[i]=str[i];
        }
        if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
            x=st.top();st.pop();
            y=st.top();st.pop();
            tree[i]=str[i];
            r[i]=x;
            l[i]=y;
            st.push(i);
        }
    }
    t=st.top();st.pop();
    for(i=0;i<=len;i++)printf("%c ",tree[i]);
    printf("\n");
    for(i=0;i<=len;i++)printf("%d ",r[i]);
    printf("\n");
    for(i=0;i<=len;i++)printf("%d ",l[i]);
    printf("\n");
    pre(t);
}
