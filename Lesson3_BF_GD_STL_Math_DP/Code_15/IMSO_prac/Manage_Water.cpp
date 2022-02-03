/*
    TASK:Manage_Water
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int n;
int fw[2010][2010];
void update(int x,int y,int c){
    for(int i=x;i<=n;i+=(i&-i)){
        for(int j=y;j<=n;j+=(j&-j)){
            fw[i][j]+=c;
        }
    }
}
int query(int x,int y){
    int sum=0;
    for(int i=x;i>0;i-=(i&-i)){
        for(int j=y;j>0;j-=(j&-j)){
            sum+=fw[i][j];
        }
    }
    return sum;
}
int main()
{
    int w,x,y,c,x1,x2,y1,y2,ans,ch=0;
    while(1){
        scanf("%d",&w);
        if(w==0){
            scanf("%d",&n);
            ch=1;
        }
        if(w==3)return 0;
        if(!ch)continue;
        if(w==1){
            scanf("%d %d %d",&x,&y,&c);
            update(x+1,y+1,c);
        }
        if(w==2){
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            ans=query(x2+1,y2+1)-query(x2+1,y1)-query(x1,y2+1)+query(x1,y1);
            printf("%d\n",ans);
        }
    }
}
/*
0 4
1 1 2 3
2 0 0 2 2
1 1 1 2
1 1 2 -1
2 1 1 2 3
3
*/
