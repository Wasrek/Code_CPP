/*
    TASK: 
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
int ran(int l, int r)
{
    // return l + (rand() % (r - l + 1));
    return rnd.next(l,r);
}
char oper[6]={'+','-','*','/'};
vector<char> g;
void play(int Ma){
    if(Ma<3){
        if(Ma==1) g.push_back(ran('a','z'));
        else g.push_back(ran('A','Z'));
        return ;
    }
    if(Ma>=3){
        g.push_back(oper[ran(0,3)]);
        Ma--;
        int now=ran(1,Ma-1);
        play(now);
        play(Ma-now);
    }
    return ;
}
int main(int argc,char* argv[])
{
    int Q,Maxx,cnt=0;
    Q=atoi(argv[++cnt]);
    Maxx=atoi(argv[++cnt]);
    // scanf("%d %d",&Q,&Maxx);
    printf("%d\n",Q);
    while(Q--){
        play(Maxx);
        for(auto x: g){
            printf("%c",x);
        }
        printf("\n");
        g.clear();
    }
    return 0;
}