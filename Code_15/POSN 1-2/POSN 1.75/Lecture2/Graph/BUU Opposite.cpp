/*
    TASK:BUU Opposite
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dis[35][35][35][35],di[]={0,0,1,-1},dj[]={-1,1,0,0},opi[]={0,0,-1,1},opj[]={1,-1,0,0},mf[35][35][35][35],ms[35][35][35][35],td[35][35][35][35];
char a[35][35];
struct A{
    int i,j,k,l;
};
queue<A> qu;
int main(){
    int q,r,c,i,j,ai,bi,aj,bj;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                scanf(" %c",&a[i][j]);
                if(a[i][j]=='A')ai=i,aj=j;
                if(a[i][j]=='B')bi=i,bj=j;
            }
        }
        int ii,jj,k,nexti,nextj;
        memset(dis,-1,sizeof dis);
        memset(mf,0,sizeof mf);
        memset(ms,0,sizeof ms);
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(a[i][j]=='#')
                    continue ;
                dis[i][j][i][j]=0;
                mf[i][j][i][j]=1;
                qu.push({i,j,i,j});
                while(!qu.empty()){
                    ii=qu.front().k,jj=qu.front().l;
                    qu.pop();
                    for(k=0;k<4;k++){
                        nexti=ii+di[k],nextj=jj+dj[k];
                        if(nexti<0 ||nextj<0 ||nexti>=r ||nextj>=c)continue;
                        if(a[nexti][nextj]=='#')continue;
                        if(mf[i][j][nexti][nextj])continue;
                        mf[i][j][nexti][nextj]=1;
                        dis[i][j][nexti][nextj]=dis[i][j][ii][jj]+1;
                        qu.push({i,j,nexti,nextj});
                    }
                }
            }
        }
        if(dis[ai][aj][bi][bj]==-1){printf("-1 0\n");continue;}
        qu.push({ai,aj,bi,bj});
        int ia,ja,ib,jb,nia,nib,nja,njb,sh=0;
        td[ai][aj][bi][bj]=0;
        ms[ai][aj][bi][bj]=1;
        int Min=dis[ai][aj][bi][bj];
        while(!qu.empty()){
            ia=qu.front().i,ja=qu.front().j,ib=qu.front().k,jb=qu.front().l;
            qu.pop();
            for(k=0;k<4;k++){
                nia=ia+di[k],nib=ib+opi[k],nja=ja+dj[k],njb=jb+opj[k];
                if(nia<0 ||nja<0 ||nia>=r || nja>=c)nia=ia,nja=ja;
                if(nib<0 ||njb<0 ||nib>=r || njb>=c)nib=ib,njb=jb;
                if(a[nia][nja]=='#')nia=ia,nja=ja;
                if(a[nib][njb]=='#')nib=ib,njb=jb;
                if(ms[nia][nja][nib][njb])continue;
                ms[nia][nja][nib][njb]=1;
                td[nia][nja][nib][njb]=td[ia][ja][ib][jb]+1;
                if(Min>dis[nia][nja][nib][njb])Min=dis[nia][nja][nib][njb],sh=td[nia][nja][nib][njb];
                qu.push({nia,nja,nib,njb});
            }
        }
        printf("%d %d\n",Min,sh);
    }
}
/*
4
2 5
A....
....B
1 5
A.#.B
1 5
A...B
3 5
A....
###..
###.B
*/
