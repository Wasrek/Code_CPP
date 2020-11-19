#include<bits/stdc++.h>
using namespace std;
map<int,int> mp[100001];
int main()
{
    int a,b,c,d,i;
    scanf("%d %d",&a,&b);
    while(b--){
        scanf("%d %d",&c,&d);
        mp[c][d] = 1;
    }
    for(i=1;i<=a;i++)
        printf("%d %d\n",i,mp[i].size());
    return 0;
}
