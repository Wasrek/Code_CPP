#include<bits/stdc++.h>
using namespace std;
char a[600][600];
int mic[10][600][600];
int qs[600][600];
int play(int siz,int si,int sj)
{
    if(mic[siz][si][sj]!=-1)
        return mic[siz][si][sj];
    if(siz==0)
        return mic[siz][si][sj]=0;
    int ma=1e9,midi=si+(1<<(siz-1)),midj=sj+(1<<(siz-1)),endi=si+(1<<siz),endj=sj+(1<<siz);
    ma=min(ma,play(siz-1,si,sj)+play(siz-1,si,midj)+abs(qs[endi-1][midj-1]-qs[endi-1][sj-1]-qs[midi-1][midj-1]+qs[midi-1][sj-1]-((1<<siz)*(1<<siz)/4))+qs[endi-1][endj-1]-qs[endi-1][midj-1]-qs[midi-1][endj-1]+qs[midi-1][midj-1]);
    ma=min(ma,play(siz-1,si,sj)+play(siz-1,si,midj)+abs(qs[endi-1][endj-1]-qs[endi-1][midj-1]-qs[midi-1][endj-1]+qs[midi-1][midj-1]-((1<<siz)*(1<<siz)/4))+qs[endi-1][midj-1]-qs[endi-1][sj-1]-qs[midi-1][midj-1]+qs[midi-1][sj-1]);
    ma=min(ma,play(siz-1,si,sj)+play(siz-1,midi,sj)+abs(qs[midi-1][endj-1]-qs[midi-1][midj-1]-qs[si-1][endj-1]+qs[si-1][midj-1]-((1<<siz)*(1<<siz)/4))+qs[endi-1][endj-1]-qs[endi-1][midj-1]-qs[midi-1][endj-1]+qs[midi-1][midj-1]);
    ma=min(ma,play(siz-1,si,sj)+play(siz-1,midi,sj)+abs(qs[endi-1][endj-1]-qs[endi-1][midj-1]-qs[midi-1][endj-1]+qs[midi-1][midj-1]-((1<<siz)*(1<<siz)/4))+qs[midi-1][endj-1]-qs[midi-1][midj-1]-qs[si-1][endj-1]+qs[si-1][midj-1]);
    ma=min(ma,play(siz-1,si,sj)+play(siz-1,midi,midj)+abs(qs[endi-1][midj-1]-qs[endi-1][sj-1]-qs[midi-1][midj-1]+qs[midi-1][sj-1]-((1<<siz)*(1<<siz)/4))+qs[midi-1][endj-1]-qs[midi-1][midj-1]-qs[si-1][endj-1]+qs[si-1][midj-1]);
    ma=min(ma,play(siz-1,si,sj)+play(siz-1,midi,midj)+abs(qs[midi-1][endj-1]-qs[midi-1][midj-1]-qs[si-1][endj-1]+qs[si-1][midj-1]-((1<<siz)*(1<<siz)/4))+qs[endi-1][midj-1]-qs[endi-1][sj-1]-qs[midi-1][midj-1]+qs[midi-1][sj-1]);
    ma=min(ma,play(siz-1,midi,sj)+play(siz-1,si,midj)+abs(qs[midi-1][midj-1]-qs[midi-1][sj-1]-qs[si-1][midj-1]+qs[si-1][sj-1]-((1<<siz)*(1<<siz)/4))+qs[endi-1][endj-1]-qs[endi-1][midj-1]-qs[midi-1][endj-1]+qs[midi-1][midj-1]);
    ma=min(ma,play(siz-1,midi,sj)+play(siz-1,si,midj)+abs(qs[endi-1][endj-1]-qs[endi-1][midj-1]-qs[midi-1][endj-1]+qs[midi-1][midj-1]-((1<<siz)*(1<<siz)/4))+qs[midi-1][midj-1]-qs[midi-1][sj-1]-qs[si-1][midj-1]+qs[si-1][sj-1]);
    ma=min(ma,play(siz-1,midi,midj)+play(siz-1,si,midj)+abs(qs[endi-1][midj-1]-qs[endi-1][sj-1]-qs[midi-1][midj-1]+qs[midi-1][sj-1]-((1<<siz)*(1<<siz)/4))+qs[midi-1][midj-1]-qs[midi-1][sj-1]-qs[si-1][midj-1]+qs[si-1][sj-1]);
    ma=min(ma,play(siz-1,midi,midj)+play(siz-1,si,midj)+abs(qs[midi-1][midj-1]-qs[midi-1][sj-1]-qs[si-1][midj-1]+qs[si-1][sj-1]-((1<<siz)*(1<<siz)/4))+qs[endi-1][midj-1]-qs[endi-1][sj-1]-qs[midi-1][midj-1]+qs[midi-1][sj-1]);
    ma=min(ma,play(siz-1,midi,midj)+play(siz-1,midi,sj)+abs(qs[midi-1][endj-1]-qs[midi-1][midj-1]-qs[si-1][endj-1]+qs[si-1][midj-1]-((1<<siz)*(1<<siz)/4))+qs[midi-1][midj-1]-qs[midi-1][sj-1]-qs[si-1][midj-1]+qs[si-1][sj-1]);
    ma=min(ma,play(siz-1,midi,midj)+play(siz-1,midi,sj)+abs(qs[midi-1][midj-1]-qs[midi-1][sj-1]-qs[si-1][midj-1]+qs[si-1][sj-1]-((1<<siz)*(1<<siz)/4))+qs[midi-1][endj-1]-qs[midi-1][midj-1]-qs[si-1][endj-1]+qs[si-1][midj-1]);
    //printf("%d %d %d %d\n",siz,si,sj,ma);
    return mic[siz][si][sj]=ma;
}
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf(" %s",&a[i][1]);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+a[i][j]-'0';
    memset(mic,-1,sizeof(mic));
    printf("%d\n",play(log2(n),1,1));
    return 0;
}
