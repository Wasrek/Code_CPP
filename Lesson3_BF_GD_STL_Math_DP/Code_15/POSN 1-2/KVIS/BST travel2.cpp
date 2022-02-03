/*
    TASK:BST travel2
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int tree[350],l[350],r[350];
void pre(int i){
   if(tree[i]==0) return ;
   printf("%d ",tree[i]);
   pre(l[i]);
   pre(r[i]);
}
void pos(int i){
   if(tree[i]==0) return ;
   pos(l[i]);
   pos(r[i]);
   printf("%d ",tree[i]);
}
void in(int i){
   if(tree[i]==0) return ;
   in(l[i]);
   printf("%d ",tree[i]);
   in(r[i]);
}
int main()
{
   int n,run,i,num;//run find blank
   scanf("%d %d",&n,&tree[1]);
   for(i=2;i<=n;i++){
    scanf("%d",&tree[i]);
    run=1;
    while(1){
        if(tree[i]< tree[run])//left
        {
        if(l[run]==0){
            l[run]=i;break;
            }
        run=l[run];
        }
        else{
            if(r[run]==0){
                    r[run]=i;break;
            }
        run=r[run];
        }
    }
   }
   pre(1);printf("\n");
   pos(1);printf("\n");
   in(1);printf("\n");
}
