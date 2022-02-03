/*
    TASK:FC_Pay Male
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int mark[4][110][110][110];
int play(int a,int b,int c,int last){
    if(a==1 && b==0 && c==0 && last!=0)return 1;
    if(a==0 && b==1 && c==0 && last!=1)return 1;
    if(a==0 && b==0 && c==1 && last!=2)return 1;
    if(mark[last][a][b][c]!=-1)return mark[last][a][b][c];
    int ans=0;
    if(last==0){
        if(b>0)
            ans+=play(a,b-1,c,1);
        if(c>0)
            ans+=play(a,b,c-1,2);
    }
    else if(last==1){
        if(a>0)
            ans+=play(a-1,b,c,0);
        if(c>0)
            ans+=play(a,b,c-1,2);
    }
    else{
        if(a>0)
            ans+=play(a-1,b,c,0);
        if(b>0)
            ans+=play(a,b-1,c,1);
    }
    return mark[last][a][b][c]=ans%100003;
}
int main(){
    int q,a,b,c,aa,bb,cc;
    memset(mark,-1,sizeof mark);
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&a,&b,&c);
        aa=bb=cc=0;
        if(a+b+c==1){printf("1\n");continue;}
        if(a!=0)aa=play(a-1,b,c,0);
        if(b!=0)bb=play(a,b-1,c,1);
        if(c!=0)cc=play(a,b,c-1,2);
        printf("%d\n",(aa+bb+cc)%100003);
    };
}
