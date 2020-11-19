/*
    TASK:Peattsort
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],fw[100010],n;
void update(int ii,int v){
    for(int i=ii;i<=n;i+=(i&-i)){
        fw[i]+=v;
    }
}
int query(int ii){
    int ans=0,i;
    for(i=ii;i>0;i-=(i&-i)){
        ans+=fw[i];
    }
    return ans;
}
pair<int,int> p[100010];
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=2;i<=n;i++){
        update(i,1);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&p[i].first);
        p[i].second=i;
    }
    sort(p+1,p+1+n);
    j=n;
    for(i=1;i<=n;i++){
        if(i%2){
            printf("%d\n",query(p[i/2+1].second));
            update(p[i/2+1].second+1,-1);
        }else{
            printf("%d\n",n-i-query(p[n-i/2+1].second));
            update(p[n-i/2+1].second+1,-1);
        }
    }
}
