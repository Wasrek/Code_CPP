#include<bits/stdc++.h>
using namespace std;
int n[500050];
int main()
{
    int w,h,f,l,i,Min=1e9,ans;
    scanf("%d %d",&w,&h);
    w=(w/2);
    while(w--){
        scanf("%d %d",&f,&l);
        n[1]++;n[f+1]--;
        n[h-l+1]++;n[h+1]--;
    }
    for(i=1;i<=h;i++)
    {
        n[i]+=n[i-1];
        if(n[i]<Min){
            Min=n[i];
            ans=1;
        }else if(Min == n[i])
            ans++;
    }
    printf("%d %d",Min,ans);

}
/*
14 5
1
3
4
2
2
4
3
4
3
3
3
2
3
3
*/
