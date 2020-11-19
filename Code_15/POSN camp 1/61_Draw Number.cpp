/*
    TASK:61_Draw Number
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[7][7],mark[10000005],ans[7];
int dir[4]={-1,1,0,0},dic[4]={0,0,1,-1},cnt=0;
void draw(int i,int j,int state){
    ans[state] = a[i][j];
    if(state==6){
        int sum=0;
        for(int k=1;k<=6;k++){
            sum*=10;
            sum+=ans[k];
        }
        if(!mark[sum]){
            mark[sum]=1;
            cnt++;
        }
        return ;
    }
    for(int k=0;k<4;k++){
        int ii=i+dir[k],jj=j+dic[k];
        if(ii==0 || jj==0 || ii>5 || jj>5)continue;
        draw(ii,jj,state+1);
    }
}
int main()
{
    int q,i,j;
    scanf("%d",&q);
    while(q--){
        cnt=0;
        for(i=1;i<=5;i++){
            for(j=1;j<=5;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(i=1;i<=5;i++){
            for(j=1;j<=5;j++){
                draw(i,j,1);
            }
        }
        printf("%d\n",cnt);
        memset(mark,0,sizeof mark);
    }
    return 0;
}
/*
1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 2 1
1 1 1 1 1
*/
