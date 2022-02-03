/*
    TASK:Manage_Water
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int fw[2100][2100];
int query(int ii,int jj){
    int sum=0,i,j;
    for(i=ii;i>0;i-=(i&-i))
        for(j=jj;j>0;j-=(j&-j))
            sum+=fw[i][j];
    return sum;
}
int main(){
    int n,opr,x,y,c,x1,x2,y1,y2,i,j;
    scanf("%d %d",&i,&n);
    while(1){
        scanf("%d",&opr);
        if(opr==3) return 0;
        if(opr==1){
            scanf("%d %d %d",&x,&y,&c);
            for(i=x+1;i<=2000;i+=(i&-i))
            for(j=y+1;j<=2000;j+=(j&-j))
                fw[i][j]+=c;
        }
    else{
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        printf("%d\n",query(x2+1,y2+1)-query(x2+1,y1)-query(x1,y2+1)+query(x1,y1));
    }
    }
    return 0;
}
