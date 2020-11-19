/*
    TASK:RT_Key chain
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100010],qs[100010];
int main(){
    long long n,k,i,idx,p,cou,j,ans;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    idx=1;
    i=1;
    for(j=1;j<=n;j++){
        cou=0;
        while(1){
        if(a[i]==j){
            break;
        }
        cou++;
        i++;
        if(i>n)i=1;
        }
        b[j]=cou;
        qs[j]=qs[j-1]+b[j];
    }
    int di,mo;
    di=k/n;
    mo=k%n;
    ans=qs[n]*di;
    ans+=qs[mo];
    printf("%lld\n",ans);
    return 0;
}
/*
4 6
4
2
1
3
*/
