/*
    TASK:Notty Land
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
vector<int,int> pa[100005],re[100005];
int mark1[100005],mark2[100005];
stack<int> st;
int coun=0,p[100005];
void play1(int k){
    if(mark1[k])return ;
    mark1[k]=1;
    for(i=0;i<pa[k].size();i++){
        play1(pa[k][i])
    }
    st.push(k);
}
void play2(int k){
    if(mark2[k])return ;
    mark2[k]=1;
    p[k]=coun;
    for(i=0;i<re[k].size();i++){
        play2(re[k][i])
    }

}
int main(){
    int n,m,q,i,j,d,b,k,g,h;
    scanf("%d %d %d",&n,&m,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&d);
        while(d--){
            scanf("%d",&b);
            pa[i].push_back(b);
            re[b].push_back(i);
        }
    }
    for(i=1;i<=n;i++){
        if(mark1[i])continue;
        play1(i);
    }
    while(!st.empty()){
        k=st.top();
        st.pop();
        if(!mark2[k]){
            play2(k);
        }
        coun++;
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&g,&h);
        if(p[h]==p[g])printf("yes");
        else printf("no");
    }
}
