/*
    TASK:Expression Tree
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
   char b;
   A *l,*r;
};
A* cnode(char c){
   A* temp;
   temp = (A*)malloc(sizeof(A));
   temp->b = c;
   temp->l = temp->r = NULL;
   return temp;
}
void in(A* run){
   if(run==NULL) return ;
   if(run->l!=NULL) printf("(");
   in(run->l);
   printf("%c",run->b);
   in(run->r);
   if(run->r!=NULL) printf(")");
}
void pre(A* run){
   if(run==NULL) return ;
   printf("%c",run->b);
   pre(run->l);
   pre(run->r);
}
char str[400];
stack< A* > st;
int main()
{
    int len,i;
    A *t1,*t2,*t3;
    gets(str);
    len = strlen(str);
    for(i=0;i<len;i++){
        if(str[i]==' ')continue;
        if(isalpha(str[i]))
            st.push( cnode(str[i]) );
        if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
            t1 = st.top(); st.pop();
            t2 = st.top(); st.pop();
            t3 = cnode(str[i]);
            t3->l =t2,t3->r = t1;
            st.push(t3);
        }
    }
    t3 = st.top();
    in(t3);printf("\n");
    pre(t3);printf("\n");
    return 0;
}
