/*
    TASK:Cromartie School
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j;
};
char a[80][80];
int qs[80][80],pp[80][80],mark[80*80],di[4]={0,0,-1,1},dj[4]={-1,1,0,0};
stack< A > st;
queue< A > q;
int main(){
    int w,l,i,j,Ma=0,ni,nj,qi,qj,cou=0,ii,jj,k,iii,jjj,ans=1e9;
    scanf("%d %d",&w,&l);
    for(i=1;i<=l;i++){
        for(j=1;j<=w;j++){
            scanf(" %c",&a[i][j]);
        }
    }
    for(i=1;i<=l;i++){
        for(j=1;j<=w;j++){
            if(a[i][j]!='T'){
                qs[i][j]=min(min(qs[i-1][j],qs[i][j-1]),qs[i-1][j-1])+1;
                Ma=max(Ma,qs[i][j]);
            }
        }
    }
    for(i=1;i<=l;i++){
        for(j=1;j<=w;j++){
            if(qs[i][j]==Ma){
                st.push({i,j});
            }
            if(a[i][j]=='P' && !pp[i][j]){
                cou++;
                pp[i][j]=cou;
                q.push({i,j});
                while(!q.empty()){
                    ii=q.front().i;
                    jj=q.front().j;
                    q.pop();
                    for(k=0;k<4;k++){
                        iii=ii+di[k];
                        jjj=jj+dj[k];
                        if(iii<1 || iii>l || jjj<1 || jjj>w)    continue;
                        if(pp[iii][jjj])                        continue;
                        if(a[iii][jjj]=='P'){
                            pp[iii][jjj]=cou;
                            q.push({iii,jjj});
                        }
                    }
                    //printf("%d %d %d\n",cou,ii,jj);
                }
            }
        }
    }
//    for(i=1;i<=l;i++){
//        for(j=1;j<=w;j++){
//            printf("%d ",pp[i][j]);
//        }
//        printf("\n");
//    }
    while(!st.empty()){
        ni=st.top().i;
        nj=st.top().j;
        cou=0;
        for(i=ni-Ma+1;i<=ni;i++){
            for(j=nj-Ma+1;j<=nj;j++){
                if(a[i][j]=='P' && !mark[pp[i][j]]){
                    cou++;
                    mark[pp[i][j]]=1;
                }
            }
        }
        ans=min(ans,cou);
        memset(mark,0,sizeof mark);
        st.pop();
    }
    printf("%d %d\n",Ma*Ma,ans);
//    for(i=1;i<=l;i++){
//        for(j=1;j<=w;j++){
//            printf("%d ",qs[i][j]);
//        }
//        printf("\n");
//    }
}
/*
8 6
SSSSSSSS
SSSSSSSS
SPPSSSSS
SSSPSSSS
SSSSSTTS
PSSSSTSS

6 5
TSSSSS
TTSSSS
SSSPSS
SSPPPS
TSSPST
*/
