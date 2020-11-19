/*
    TASK:Sport
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
int ans[150],k;
void play(int state,int w,int l){
   int i;
   if(w==k||l==k){
    for(i=0;i<state;i++){
        if(ans[i]==0) printf("W ");
        else printf("L ");
    }
    printf("\n");
    return ;
   }
   ans[state]=0;
   play(state+1,w+1,l);
   ans[state]=1;
   play(state+1,w,l+1);
}
int main()
{
    int w,l;
    scanf("%d %d %d",&k,&w,&l);
    play(0,w,l);
    return 0;
}
