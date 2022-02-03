/*
    TASK:RT_Pick Book
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[5100],b[5100],mark[1010][1010];
int main(){
    int n,m,i,j,cou=0,ans1=0,ans2=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d",&a[i],&b[i]);
        mark[a[i]][b[i]]=1;
        mark[b[i]][a[i]]=1;
    }
    for(i=1;i<=m;i++){
        for(j=i+1;j<=m;j++){
            if(a[i]==a[j] || a[i]==b[j] || b[i]==a[j] || b[i]==b[j])continue;
            cou=2;
            if(mark[a[i]][b[j]])cou++;
            if(mark[a[j]][b[i]])cou++;
            if(mark[a[i]][a[j]])cou++;
            if(mark[b[i]][b[j]])cou++;
            if(cou==5)ans1++;
            else if(cou==6){
                ans2++;
            }
        }
    }
    ans1/=2;
    ans2/=3;
    printf("%d\n",ans1+ans2);
    return 0;
}
