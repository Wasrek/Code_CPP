/*
    TASK:BTS Travel2
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
   int num;
   struct node *l, *r;
};
node *root=NULL,*run=NULL;
node* createnode(int num){
   node *temp;
   temp = (node*)malloc(sizeof(node));
   temp -> num = num;
   temp->l = temp->r = NULL;
   return temp;
}
void pre(node* run){
   if(run==NULL) return ;
   printf("%d ",run->num);
   pre(run->l);
   pre(run->r);
}
void pos(node* run){
   if(run==NULL) return ;
   pos(run->l);
   pos(run->r);
   printf("%d ",run->num);
}
void in(node* run){
   if(run==NULL) return ;
   in(run->l);
   printf("%d ",run->num);
   in(run->r);
}
int main()
{
    int n,num,i;
    node *t;
    scanf("%d %d",&n,&num);
    root = createnode(num);
    run = createnode(num);
    for(i=0;i<n-1;i++){
        scanf("%d",&num);
        t = createnode(num);
        run = root;
        while(1){
            if(num < run->num && run->l==NULL){
                run->l=t; break;
            }
            if(num > run->num && run->r==NULL){
                run->r=t; break;
            }
            else if(num < run->num)
                run = run->l;
            else
                run = run->r;
        }
    }
    pre(root); printf("\n");
    pos(root); printf("\n");
    in(root); printf("\n");
    return 0;
}
