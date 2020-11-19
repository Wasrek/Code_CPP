#include<bits/stdc++.h>
using namespace std;
int a[160005],b[160005],cc[160005],m1[]={1,-1,0,0},m2[]={0,0,1,-1},m[405][405];
int p[160005],p2[160005],mark[160005];
int fs(int i)
{
    if(p[i]==i)
        return i;
    return p[i]=fs(p[i]);
}
int main()
{
    int r,c,q,ans,i,j,nx,ny,k,now,nex;
    scanf("%d %d %d",&r,&c,&q);
    for(i=1;i<=q;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
        m[a[i]][b[i]]=1;
    }
    for(i=0;i<r*c;i++)
    {
        p[i]=i;
        p2[i]=1;
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(m[i][j])
                continue ;
            for(k=0;k<4;k++)
            {
                nx=i+m1[k];
                ny=j+m2[k];
                if(nx>=0 && nx<r && ny>=0 && ny<c && m[nx][ny]==0 && fs(i*c+j)!=fs(nx*c+ny))
                {
                    now=fs(i*c+j);
                    nex=fs(nx*c+ny);
                    p2[nex]+=p2[now];
                    p[now]=fs(nex);
                }
            }
        }
    }

    for(int l=q;l>=1;l--)
    {
        ans=0;
        for(i=0;i<r;i++)
        {
            now=fs(i*c);
            if(m[i][0]==0 && mark[now]!=l)
            {
                mark[now]=l;
                ans+=p2[now];
            }
            now=fs(i*c+c-1);
            if(m[i][c-1]==0 && mark[now]!=l)
            {
                mark[now]=l;
                ans+=p2[now];
            }
        }
        for(i=0;i<c;i++)
        {
            now=fs(i);
            if(m[0][i]==0 && mark[now]!=l)
            {
                mark[now]=l;
                ans+=p2[now];
            }
            now=fs((r-1)*c+i);
            if(m[r-1][i]==0 && mark[now]!=l)
            {
                mark[now]=l;
                ans+=p2[now];
            }
        }
        m[a[l]][b[l]]=0;
            for(k=0;k<4;k++)
            {
                i=a[l];
                j=b[l];
                nx=i+m1[k];
                ny=j+m2[k];
                if(nx>=0 && nx<r && ny>=0 && ny<c && m[nx][ny]==0 && fs(i*c+j)!=fs(nx*c+ny))
                {
                    now=fs(i*c+j);
                    nex=fs(nx*c+ny);
                    p2[nex]+=p2[now];
                    p[now]=fs(nex);
                }
            }

        cc[l]=ans;
    }
    for(i=1;i<=q;i++)
    {
        printf("%d\n",cc[i]);
    }
}
