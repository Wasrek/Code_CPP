#include<bits/stdc++.h>
using namespace std;
char a[100010][35];
vector<int> g[100100];
int visited[100100],lowlink[100100],id[100100],mark[100100],cnt=1,in[100100],cp[35];
stack<int> st;
void dfs(int i){
    id[i]=cnt++;
    lowlink[i]=id[i];
    visited[i]=1;
    mark[i]=1;
    st.push(i);
    for(auto x : g[i]){
        if(!visited[x]){
            mark[x]=1;
            dfs(x);
        }
        if(mark[x]){
            lowlink[i]=min(lowlink[i],lowlink[x]);
        }
    }
    if(id[i]==lowlink[i]){
        while(!st.empty()&&st.top()!=i){
            mark[st.top()]=0;
            lowlink[st.top()]=id[i];
            st.pop();
        }
        st.pop();
        mark[i]=0;
    }
    //printf("%d %d\n",i,lowlink[i]);
}
int main(){
    int i,j,n,k;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf(" %s",a[i]);
        for(j=0;j<k;j++){
            if(a[i][j]=='1') g[i].push_back(n+j),cp[j]=1;
            else g[n+j].push_back(i);
        }
    }
    for(i=0;i<n;i++){
        if(!visited[i]){
            //printf("main push %d\n",i);
            dfs(i);
        }
    }
    for(i=0;i<n+k;i++){
        if(i>=n&&cp[i-n]==0) continue;
        for(auto x : g[i]){
            if(lowlink[x]==lowlink[i]) continue;
            in[lowlink[x]]++;
        }
    }
    int ch=-1;
    for(i=0;i<n;i++){
        if(in[lowlink[i]]!=0) continue;
        if(ch==-1){
            ch=lowlink[i];
            continue;
        }
        if(lowlink[i]!=ch){
            printf("-1\n");
            return 0;
        }
    }
    if(ch==-1) printf("-1");
    for(i=0;i<n;i++){
        if(lowlink[i]==ch) printf("%d ",i+1);
    }
return 0;
}
