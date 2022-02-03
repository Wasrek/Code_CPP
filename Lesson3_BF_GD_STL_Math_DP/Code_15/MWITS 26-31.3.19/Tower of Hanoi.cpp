/*
    TASK:Tower of Hanoi
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int n,p,i,ch;
deque<int> dq[100];
void play(int st,char x,char y,char z)
{
    if(p==0)
    {
        return;
    }
    if(st==1)
    {
        dq[z].push_back(dq[x].back());
        dq[x].pop_back();
        p--;
        return ;
    }
    play(st-1,x,z,y);
    if(p)
    {
        dq[z].push_back(dq[x].back());
        dq[x].pop_back();
        p--;
        if(p)
            play(st-1,y,x,z);
    }
}
int main()
{
    int q,j;
    scanf("%d",&q);
    for(i=1; i<=q; i++)
    {
        scanf("%d %d",&n,&p);
        ch=0;
        for(j=n; j>=1; j--)
            dq['A'].push_back(j);
        play(n,'A','B','C');
        printf("Case %d:\n",i);
        printf("A: ");
        if(dq['A'].empty())
            printf("X");
        else
        {
            while(!dq['A'].empty())
            {
                printf("%d ",dq['A'].front());
                dq['A'].pop_front();
            }
        }
        printf("\n");
        printf("B: ");
        if(dq['B'].empty())
            printf("X");
        else
        {
            while(!dq['B'].empty())
            {
                printf("%d ",dq['B'].front());
                dq['B'].pop_front();
            }
        }
        printf("\n");
        printf("C: ");
        if(dq['C'].empty())
            printf("X");
        else
        {
            while(!dq['C'].empty())
            {
                printf("%d ",dq['C'].front());
                dq['C'].pop_front();
            }
        }
        printf("\n");
        while(!dq['A'].empty())
            dq['A'].pop_back();
        while(!dq['B'].empty())
            dq['B'].pop_back();
        while(!dq['C'].empty())
            dq['C'].pop_back();
    }
}
