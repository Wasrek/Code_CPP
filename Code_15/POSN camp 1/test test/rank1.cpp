#include<bits/stdc++.h>
using namespace std;
int ks,gs,k[250001],n[250001],i,j,cou,g;
int main()
{
   scanf("%d %d",&ks,&gs);
    for(i=0;i<ks;i++)
    {
        scanf("%d",&k[i]);
        k[i]=k[i]*(-1);
        n[i]=k[i];
    }
    for(i=0;i<gs;i++)
    {
        scanf("%d",&k[ks]);
        g=k[ks];
        k[ks]=k[ks]*(-1);
        sort(k,(k+ks+1));
        cou=0;
        for(j=0;j<=ks;j++)
           // printf("%d",k[j]);
        {
            if(k[j]==(g*(-1)))
            {
                printf("%d\n",cou+1);break;
            }
           cou++;
        }
        for(j=0;j<=ks;j++)
        {
            k[j]=n[j];
        }
    }

}
