/*
    TASK: X-game
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[10][10],ans=17;
void play(int i,int j,int state)
{
    int t=a[1][1],k,l,ch=1;
    for(k=1; k<=4; k++)
        for(l=1; l<=4; l++)
            if(a[k][l]!=t)
                ch=0;
    if(ch)
    {
        if(state<ans)
            ans=state;
        return ;
    }
    if(i>4||j>4)
        return ;
    if(j==4)
        play(i+1,1,state);
    else
        play(i,j+1,state);
    a[i][j]^=1;//1 xor 1 equal to 0 0 xor 1 equal to 1
    a[i+1][j]^=1;
    a[i-1][j]^=1;
    a[i][j+1]^=1;
    a[i][j-1]^=1;
    if(j==4)
        play(i+1,1,state+1);
    else
        play(i,j+1,state+1);
    a[i][j]^=1;
    a[i+1][j]^=1;
    a[i-1][j]^=1;
    a[i][j+1]^=1;
    a[i][j-1]^=1;
}
int main()
{
    int i,j;
    char b;
    for(i=1; i<=4; i++)
    {
        for(j=1; j<=4; j++)
        {
            scanf(" %c",&b);
            a[i][j]=(b=='b');
        }
    }
    play(1,1,0);
    printf((ans==17)?"Impossible\n":"%d\n",ans);
    return 0;
}
