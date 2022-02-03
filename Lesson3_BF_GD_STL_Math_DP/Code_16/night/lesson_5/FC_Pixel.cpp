#include<bits/stdc++.h>
using namespace std;
char a[550][550];
int mic[10][550][550];
int qs[550][550];
int div(int siz,int si,int sj)
{
    if(mic[siz][si][sj]!=-1)
        return mic[siz][si][sj];
    if(siz==0)
        return mic[siz][si][sj]=0;
    int ma=1e9,midi=si+(1<<(siz-1)),midj=sj+(1<<(siz-1)),endi=si+(1<<siz),endj=sj+(1<<siz);
    int tlw=qs[midi-1][midj-1]-qs[midi-1][sj-1]-qs[si-1][midj-1]+qs[si-1][sj-1];
    int tlb=abs(qs[midi-1][midj-1]-qs[midi-1][sj-1]-qs[si-1][midj-1]+qs[si-1][sj-1]-((1<<siz)*(1<<siz)/4));
    int tld=div(siz-1,si,sj);
    int trw=qs[midi-1][endj-1]-qs[midi-1][midj-1]-qs[si-1][endj-1]+qs[si-1][midj-1];
    int trb=abs(qs[midi-1][endj-1]-qs[midi-1][midj-1]-qs[si-1][endj-1]+qs[si-1][midj-1]-((1<<siz)*(1<<siz)/4));
    int trd=div(siz-1,si,midj);
    int blw=qs[endi-1][midj-1]-qs[endi-1][sj-1]-qs[midi-1][midj-1]+qs[midi-1][sj-1];
    int blb=abs(qs[endi-1][midj-1]-qs[endi-1][sj-1]-qs[midi-1][midj-1]+qs[midi-1][sj-1]-((1<<siz)*(1<<siz)/4));
    int bld=div(siz-1,midi,sj);
    int brw=qs[endi-1][endj-1]-qs[endi-1][midj-1]-qs[midi-1][endj-1]+qs[midi-1][midj-1];
    int brb=abs(qs[endi-1][endj-1]-qs[endi-1][midj-1]-qs[midi-1][endj-1]+qs[midi-1][midj-1]-((1<<siz)*(1<<siz)/4));
    int brd=div(siz-1,midi,midj);
    ma=min(ma,tld+trd+blb+brw);
    ma=min(ma,tld+trd+brb+blw);
    ma=min(ma,tld+bld+trb+brw);
    ma=min(ma,tld+bld+brb+trw);
    ma=min(ma,tld+brd+blb+trw);
    ma=min(ma,tld+brd+trb+blw);
    ma=min(ma,bld+trd+tlb+brw);
    ma=min(ma,bld+trd+brb+tlw);
    ma=min(ma,brd+trd+blb+tlw);
    ma=min(ma,brd+trd+tlb+blw);
    ma=min(ma,brd+bld+trb+tlw);
    ma=min(ma,brd+bld+tlb+trw);
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
    printf("%d\n",div(log2(n),1,1));
    return 0;
}
