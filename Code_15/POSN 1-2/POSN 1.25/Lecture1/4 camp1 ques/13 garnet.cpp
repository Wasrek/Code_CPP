/*
    TASK: garnet
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
map<int,int> a[100100];
char b[100050];
int main()
{
    int n,m,fx,fy,h,cx,cy,i,t,chi,chj,cou=0;
    char tid;
    scanf("%d %d",&m,&n);
    scanf("%d %d %c",&fy,&fx,&tid);
    if(tid=='W')
        t=4;
    else if(tid=='E')
        t=2;
    else if(tid=='S')
        t=3;
    else if(tid=='N')
        t=1;
    scanf("%d",&h);
    while(h--)
    {
        scanf("%d %d",&cy,&cx);
        a[cx][cy]=1;
    }
    scanf("%d",&h);
    for(i=0; i<h; i++)
    {
        chi=fx,chj=fy;
        scanf(" %c",&b[i]);
        if(b[i]=='L'){
            if(t==1)t=4;else
            t--;
        }
        else if(b[i]=='R'){
            if(t==4)t=1;else
            t++;
        }
        else if(b[i]=='F'){
            if(t==1)fx--;
            else if(t==2)fy++;
            else if(t==3)fx++;
            else if(t==4)fy--;
        }
        else if(b[i]=='B'){
            if(t==1)fx++;
            else if(t==2)fy--;
            else if(t==3)fx--;
            else if(t==4)fy++;
        }
        if(fx>n || fy>m || fx<1 || fy<1){
            fx=chi,fy=chj;
        }else {
            if(a[fx][fy]==1){cou++;a[fx][fy]=0;}
        //printf("%d %d",fx,fy);
        }
    }
    printf("%d",cou);
}
/*
8 10
5 1
W
2
2 3
6 9
10
F
F
L
B
F
F
R
F
L
F
*/
