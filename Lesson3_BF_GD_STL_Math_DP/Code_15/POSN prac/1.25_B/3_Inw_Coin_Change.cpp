/*
    Prac
    TASK:Inw Coin Change
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int b[25],n,k,cou=0,m=1;
void play(int s,int state)
{
    int i,j;
    if(s>n) return;
    if(s==n)
    {
        cou++;
        if(cou==k)
        {
            for(i=0; i<state; i++)
            {
                printf("%d",b[i]);
            }
            exit(0);
        }
        return ;
    }
    for(i=1; i<=9; i++){
            b[state]=i;
            s+=i;
            play(s,state+1);
            s-=i;
        }
    }

int main()
{
    scanf("%d %d",&n,&k);//money order
    play(0,0);

    return 0;
}
