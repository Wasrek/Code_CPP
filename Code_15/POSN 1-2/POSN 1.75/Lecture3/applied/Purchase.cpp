/*
    TASK:Purchase
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,aa,bb,cc,dd,ee,na,nb,nc,nd,ne;
int main()
{
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    aa=a,bb=b,cc=c,dd=d,ee=e;
    //Greedy 50
    if(e>=50)
    {
        nd=e/50;
        if(nd<=d)
            e%=50,d-=nd;//can use
        else
            nd=d,d=0,e=e-(nd*50);
    }
    if(e>=20)
    {
        nc=e/20;
        if(nc<=c)
            e%=20,c-=nc;//can use
        else
            nc=c,c=0,e=e-(nc*20);
    }
    if(e>=10)
    {
        nb=e/10;
        if(nb<=b)
            e%=10,b-=nb;//can use
        else
            nb=b,b=0,e=e-(nb*10);
    }
    na=e/5;
    if(na<=a && na*5+nb*10+nc*20+nd*50==ee)
    {
        printf("%d %d %d %d %d\n",na,nb,nc,nd,na+nb+nc+nd);
        return 0;
    }
    //not 50
    a=aa,b=bb,c=cc,d=dd,e=ee,na=nb=nc=nd=ne=0;
    if(e>=100)
    {
        nd=e/100;
        nd*=2;
        if(nd<=d)
            e%=100,d-=nd;//can use
        else
            nd=d,d=0,e=e-(nd*50);
    }
    if(e>=20)
    {
        nc=e/20;
        if(nc<=c)
            e%=20,c-=nc;//can use
        else
            nc=c,c=0,e=e-(nc*20);
    }
    if(e>=10)
    {
        nb=e/10;
        if(nb<=b)
            e%=10,b-=nb;//can use
        else
            nb=b,b=0,e=e-(nb*10);
    }
    na=e/5;
    if(na<=a && na*5+nb*10+nc*20+nd*50==ee)
    {
        printf("%d %d %d %d %d\n",na,nb,nc,nd,na+nb+nc+nd);
        return 0;
    }
    printf("-1\n");
    return 0;
}
