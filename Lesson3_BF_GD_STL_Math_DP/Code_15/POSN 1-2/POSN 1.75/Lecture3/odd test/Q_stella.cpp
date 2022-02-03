/*
    TASK:Q_stella
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    long long t,w,day,d,p;//n=1,r=2
    bool operator < (const A&o) const
    {
        if(w!=o.w)
        {
            return w<o.w;
        }
        else if(p!=o.p)
        {
            return p>o.p;
        }
    }
};
priority_queue<A> h;
int main()
{
    long long q;
    scanf("%lld",&q);
    char a,b;
    long long i,j,k,l,cou=0,weight=0;
    for(i=1; i<=q; i++)
    {
        scanf(" %c",&a);
        int np;
        if(a=='c')
        {
            scanf(" %c",&b);
            if(b=='n')
            {
                scanf("%lld",&k);
                h.push({1,k,i,0,i});
            }
            else if(b=='r')
            {
                scanf("%lld %lld",&k,&l);
                h.push({2,k,i,l,i});
            }
        }
        else if(a=='u')
        {
            long long nt,nw,nday,nd,mark=0,dd;
                while(!h.empty())
                {
                    nt=h.top().t;
                    nw=h.top().w;
                    nday=h.top().day;
                    nd=h.top().d;
                    dd=nw;
                    np=h.top().p;
                    h.pop();
                    if(nw==0)
                    {
                        continue;
                    }
                    if(nt==2)
                    {
                        if(nday+nd>i)
                        {
                            weight+=nw;
                            break;
                        }
                        else
                        {
                            nday+=nd;
                            nw/=2;
                            h.push({2,nw,nday,nd,np});
                            continue;
                        }

                    }
                    if(nt==1)
                    {
                        weight+=nw;
                        break;
                    }
                }
        }
    }
    //printf("klef");
    long long nday,nd,nw,np,nt;
    cou=0;i--;
    while(!h.empty())
    {
        nt=h.top().t;
        nday=h.top().day;
        nd=h.top().d;
        nw=h.top().w;
        np=h.top().p;
        h.pop();
        if(nw!=0 && nt==1){
            cou++;continue;
        }
        if(nday+nd<=i){
                nday+=nd;
                nw/=2;
                h.push({2,nw,nday,nd,np});
                continue;
        }
        if(nw!=0)
            cou++;
    }
    //printf("\n%d\n",(int)h.size());
    //printf("klef");
    printf("%lld\n%lld\n",weight,cou);
    return 0;
}
/*
5
c n 100
c r 58 2
u
u
c r 1 1
*/
