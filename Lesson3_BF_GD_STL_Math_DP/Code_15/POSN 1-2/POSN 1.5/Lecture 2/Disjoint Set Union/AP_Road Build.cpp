/*
    TASK:AP_Road Build
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int p[300100];
int fin(int i)
{
    if(p[i]==i)
        return i;
    return p[i]=fin(p[i]);
}
int ha[300100][3],wa[300100][3];
int main()
{
    int q,c,w,r,a,b,i,mid,l,h,j,ch,ans;
    scanf("%d",&q);
    for(j=1; j<=q; j++)
    {
        ans=0;
        scanf("%d %d %d",&c,&h,&w);
        for(i=1; i<=w; i++)
        {
            scanf("%d %d",&a,&b);
            wa[i][1]=a;
            wa[i][2]=b;
        }
        for(i=1; i<=h; i++)
        {
            scanf("%d %d",&a,&b);
            ha[i][1]=a;
            ha[i][2]=b;
        }
        l=1,r=h+1;
        while(l<r)
        {
            mid=(l+r)/2;
            for(i=1; i<=c; i++)
                p[i]=i;
            for(i=1; i<=mid; i++)
            {
                p[fin(ha[i][2])]=fin(ha[i][1]);
            }
            ch=0;
            for(i=1; i<=w; i++)
            {
                if(fin(wa[i][1])!=fin(wa[i][2]))
                {
                    ch=1;//printf("-%d-",i);
                }
                // printf("m:%d %d\n",mid,ch);
            }
            if(ch==0)
                r=mid;
            else if(ch)
                l=mid+1;
        }
        if(r > h)
            printf("C#%d: -1\n",j);
        else
            printf("C#%d: %d\n",j,r);

    }
}
/*
2
5 5 5
1 2
1 3
3 2
4 5
2 5
1 5
2 3
1 4
1 3
2 5
5 5 5
1 5
1 4
2 3
4 5
3 4
1 2
1 3
1 4
2 3
1 5
*/
