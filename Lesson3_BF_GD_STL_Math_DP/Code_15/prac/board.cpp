#include<bits/stdc++.h>
using namespace std;
int ma[25];
int main()
{
    int s,n,m,a,all;
    scanf("%d %d %d",&n,&m,&s);
    all=n*m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a);
            a+=(s*i);
            if(ma[j]>=a)all--;
            if(ma[j]<a)ma[j]=a;
        }
    }
    printf("%d\n",all);
    return 0;
}