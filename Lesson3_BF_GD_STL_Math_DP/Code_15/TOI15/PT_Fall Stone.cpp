/*
    TASK:PT_Fall Stone
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j;
};
A qu[160100];
stack<int> st;
int r,c,cou=0;
int mark[410][410],sto[410][410],di[]={-1,1,0,0},dj[]={0,0,-1,1};
void dfs(int i,int j){
    mark[i][j]=1;
    cou++;
    //printf("%d %d\n",i,j);
    int ni,nj,k;
    for(k=0;k<4;k++){
        ni=i+di[k];
        nj=j+dj[k];
        if(ni<1 || ni>r || nj<1 || nj>c)continue;
        if(mark[ni][nj])continue;
        if(sto[ni][nj])continue;
        dfs(ni,nj);
    }
}
int main(){
    int q,i,j;
    scanf("%d %d %d",&r,&c,&q);
    for(i=1;i<=q;i++){
        scanf("%d %d",&qu[i].i,&qu[i].j);
        qu[i].i+=1;
        qu[i].j+=1;
        sto[qu[i].i][qu[i].j]=1;
    }
    cou=0;
    for(j=1;j<=c;j++){
            if(!mark[1][j] && !sto[1][j])
            dfs(1,j);
            if(!mark[r][j] && !sto[r][j])
            dfs(r,j);
    }
    for(i=1;i<=r;i++){
            if(!mark[i][1] && !sto[i][1])
            dfs(i,1);
            if(!mark[i][c] && !sto[i][c])
            dfs(i,c);
    }
    //printf("%d\n",cou);
    //return 0;
    st.push(cou);
    int ch=0;
    for(i=q;i>=1;i--){
        sto[qu[i].i][qu[i].j]=0;
        for(j=0;j<4;j++){
            if(mark[qu[i].i+di[j]][qu[i].j+dj[j]])ch=1;
        }
        if(qu[i].i==1 || qu[i].i==r || qu[i].j==1 || qu[i].j==c)ch=1;
        if(ch){
        dfs(qu[i].i,qu[i].j);
        }
        st.push(cou);
        ch=0;
    }
    st.pop();
    while(!st.empty())printf("%d\n",st.top()),st.pop();
    return 0;
}
