#include<bits/stdc++.h>
using namespace std;
int ks,gs,k[250001],n[250001],i,j,cou,g;
int main()
{
   scanf("%d %d",&ks,&gs);
    for(i=0;i<ks;i++)
    {
        scanf("%d",&k[i]);
    }
    for(i=0;i<gs;i++)
    {
        scanf("%d",&g);
        j=upper_bound(k,(k+ks),g)-(k);
        printf("%d\n",ks+1-j);
    }
}
