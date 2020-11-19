/*
    TASK:Segment Tree
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],b[400];
int main(){
    int n,q,k,x,y,i,ans;
    char opr;
    scanf("%d %d",&n,&q);
    k = (int)sqrt(n);
    while(q--){
        scanf(" %c %d %d",&opr,&x,&y);
        x--;
        if(opr=='U'){
            a[x]=y;
            b[x/k]=-1e9;
            for(i=x/k*k;i<min(n,x/k*k+k);i++)
                b[x/k]=max(b[x/k],a[i]);
        }
        else{
            y--;
            for(i=x,ans=a[i];i<=y;){
                if(i%k==0 && i+k-1<=y){
                    ans=max(ans,b[i/k]);
                    i+=k;
                }
                else{
                    ans=max(ans,a[i]);
                    i++;
                }
            }
            printf("%d\n",ans);
        }
    }
}
