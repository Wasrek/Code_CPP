/*
    TASK:Expression Tree
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
//Array Expression Tree
char node[300],str[300];
int l[300],r[300];
stack<int> st;
void in(int i){
   if(l[i]){
    printf("(");
   in(l[i]);
   }
   printf("%c",node[i]);
   if(r[i]){
    in(r[i]);
    printf(")");
   }
}
void pre(int i){
   if(node[i]==NULL) return ;
   printf("%c",node[i]);
   pre(l[i]);
   pre(r[i]);
}
int main()
{
    int len,i,cou=0;
    gets(str);
    len=strlen(str);
    for(i=0;i<len;i++){
        if(str[i]==' ')continue;
        if(isalpha(str[i])){
            node[++cou]=str[i];
            st.push(cou);
        }
        if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/'){
            node[++cou]=str[i];
            r[cou]=st.top();st.pop();
            l[cou]=st.top();st.pop();
            st.push(cou);
        }
    }
    in(st.top());printf("\n");
    pre(st.top());printf("\n");
    return 0;

}
/*
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
char a[300];
stack< A* > st;
int main()
{
    int len,i;
    A *y,*b,*c;
    gets(a);
    len=strlen(a);
    for(i=0;i<len;i++){
        if(a[i]==' ')continue;
        if(isalpha(a[i]))st.push( cnode(a[i]) );
        if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/'){
            y=st.top(),st.pop();
            b=st.top(),st.pop();
            c = cnode(a[i]);
            c->r=y;
            c->l=b;
            st.push(c);
        }
    }
    c=st.top();
    in(c);printf("\n");
    pre(c);

    return 0;
}
*/
