/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
};
int n,m,sx,sy,ex,ey;
map<pair<int,int>, bool> mp,mp1; 
bool ch(int nx,int ny){
    if(nx==0 || nx== n+1 || ny==0 || ny==m+1 || mp[{nx,ny}]) return 1;
    return 0;
}
int can=0;
void play(int nx,int ny,int la,int now){
    // printf("%d %d %d\n",nx,ny,mp1[{nx,ny}]);
    if(mp1[{nx,ny}] || can) return ;
    bool c1,c2,c3,c4;
    c3=ch(nx,ny+1); c4=ch(nx+1,ny); c1=ch(nx,ny-1); c2=ch(nx-1,ny);
    if(nx!=sx || ny!=sy)mp1[{nx,ny}]=1;
    if(!c1 && !c2 && !c3 && !c4) return ;
    // printf("%d %d %d %d\n",c1,c2,c3,c4);
    int x=nx,y=ny;
    if(c1 && !c3 && la!=1){
        while(!(x==ex && y==ey) && !ch(x,y+1)){
            y++;
            if(!(x==ex && y==ey) && (ch(x-1,y) || ch(x+1,y))){
                play(x,y,3,now+1);
            }
        }
        // printf("%d %d\n",x,y);
        if(x==ex && y==ey){
            printf("%d\n",now+1);
            can=1;
            return ;
        }
        if(x!=nx || y!=ny) play(x,y,3,now+1);
    } else if(c3 && !c1 && la!=3){
        while(!(x==ex && y==ey) && !ch(x,y-1)){
            y--;
            if(!(x==ex && y==ey) && (ch(x-1,y) || ch(x+1,y))){
                play(x,y,1,now+1);
            }
        }
        if(x==ex && y==ey){
            printf("%d\n",now+1);
            can=1;
            return ;
        }
        if(x!=nx || y!=ny) play(x,y,1,now+1);
    }
    if(can) return ;
    x=nx,y=ny;
    if(c2 && !c4 && la!=2){
        while(!(x==ex && y==ey) && !ch(x+1,y)){
            x++;
            if(!(x==ex && y==ey) && (ch(x,y-1) || ch(x,y+1))){
                play(x,y,4,now+1);
            }
        }
        if(x==ex && y==ey){
            printf("%d\n",now+1);
            can=1;
            return ;
        }
        // printf("%d %d\n",x,y);
        if(x!=nx || y!=ny) play(x,y,4,now+1);
    }else if(c4 && !c2 && la!=4){
        while(!(x==ex && y==ey) && !ch(x-1,y)){
            x--;
            if(!(x==ex && y==ey) && (ch(x,y-1) || ch(x,y+1))){
                play(x,y,2,now+1);
            }
        }
        if(x==ex && y==ey){
            printf("%d\n",now+1);
            can=1;
            return ;
        }
        if(x!=nx || y!=ny) play(x,y,2,now+1);
    }
    return ;
}
int ch4(int x,int y){
    if(x==1 && y==1) return 1;
    if(x==1 && y==m) return 2;
    if(x==n && y==1) return 3;
    if(x==n && y==m) return 4;
    return 0;
}
int chs(int x,int y){
    if(x==1) return 1;
    if(y==1) return 2;
    if(x==n) return 4;
    if(y==m) return 3;
    return 0;
}
int main()
{
    int w;
    scanf("%d %d %d",&n,&m,&w);
    int x,y;
    scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
    int nx=sx,ny=sy,la=0;
    if(w==0){
        bool c3=ch(nx,ny+1), c4=ch(nx+1,ny), c1=ch(nx,ny-1), c2=ch(nx-1,ny);
        // printf("%d %d %d %d\n",c1,c2,c3,c4);
        if(ch4(sx,sy) && chs(ex,ey)){
            int now=abs(ch4(sx,sy)-chs(ex,ey));
            now=max(now,1);
            now=min(now,2);
            printf("%d\n",now);
            return 0;
        }
        if(c1 && sx==ex && sy<=ey){
            printf("1\n");
            return 0;
        }
        if(c3 && sx==ex && sy>=ey){
            printf("1\n");
            return 0;
        }
        if(c2 && sy==ey && sx<=ex){
            printf("1\n");
            return 0;
        }
        if(c4 && sy==ey && sx>=ex){
            printf("1\n");
            return 0;
        }
        printf("-1\n");
        return 0;
    }
    for(int i=1;i<=w;i++){
        scanf("%d %d",&x,&y);
        mp[{x,y}]=1;
    }
    play(nx,ny,0,0);
}