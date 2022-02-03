#include<bits/stdc++.h>
char str[5];
int tree[1<<23];
void pre(int i){
   if(tree[i]==0)return;
   printf("%d\n",tree[i]);
   pre(i*2);
   pre(i*2+1);
}
void pos(int i){
   if(tree[i]==0)return;
   pos(i*2);
   pos(i*2+1);
   printf("%d\n",tree[i]);
}
void in(int i){
   if(tree[i]==0)return;
   in(i*2);
   printf("%d\n",tree[i]);
   in(i*2+1);
}
void bfs(int i){
   for(i=0;i<1<<23;i++)
   {
       if(tree[i]==0)break;
       printf("%d\n",tree[i]);
   }
   return;
}
int main(){
   int i,j,n,r;
   scanf("%s %d",str,&j);
   for(i=0;i<j;i++){
    scanf("%d",&n);
    r=1;
    while(1){
        if(tree[r]==0)break;
        if(tree[r]>n){
            r=r*2;
        }else r=r*2+1;
    }
    tree[r]=n;
   }
   if(!strcmp(str,"PRE"))pre(1);
   if(!strcmp(str,"POS"))pos(1);
   if(!strcmp(str,"INF"))in(1);
   if(!strcmp(str,"BFS"))bfs(1);
}
