/*
    TASK:Fenwick
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
int fen[2005][2005];
void update(int ii,int jj,int val)
{
    for(int i=ii;i<=2000;i+=i&-i)
        for(int j=jj;j<=2000;j+=j&-j)
            fen[i][j]+=val;
}
int query(int ii,int jj)
{
    int sum=0;
    for(int i=ii;i>0;i-=i&-i)
        for(int j=jj;j>0;j-=j&-j)
            sum+=fen[i][j];
    return sum;
}
int main()
{
    int n,m,k,kk,i,j,l,a,v;
    scanf("%d %d %d",&n,&m,&kk);
    while(kk--)
    {
        scanf("%d",&a);
        if(a==1)
        {
            scanf("%d %d %d %d %d",&i,&j,&k,&l,&v);
            update(i,j,v);
            update(i,l+1,-v);
            update(k+1,j,-v);
            update(k+1,l+1,v);
        }
        if(a==2)
        {
            scanf("%d %d",&i,&j);
            printf("%d\n",query(i,j));
        }
    }
    return 0;
}
