#include<bits/stdc++.h>
using namespace std;
struct A{
   int to,score;
   bool operator < (const A& o) const{
       if(score != o.score) return score < o.score;
       else return to < o.to;
   }
};
int psc[1000050],mark[1000050];
priority_queue< A >heap;
int main()
{
    int n,ord,ask,i,fr,t,r,al=5;
    char ch;
    scanf("%d %d %d",&n,&ord,&ask);
    r=ord+ask;
    for(i=1;i<=n;i++)
    {
        heap.push({i,0});
    }
    for(i=0;i<r;i++)
    {
        scanf(" %c",&ch);
        if(ch=='L'){
            scanf("%d %d",&fr,&t);
            psc[t]+=1;
            heap.push({t,psc[t]});
        }else  if(ch=='C'){
            scanf("%d %d",&fr,&t);
            psc[t]+=3;
            heap.push({t,psc[t]});
        }else  if(ch=='R'){
            while(1000000)
            if(mark[heap.top().to]==1)  heap.pop();else break;
            printf("%d\n",heap.top().to);
        }else  if(ch=='D'){
            while(1000000)
            if(mark[heap.top().to]==1)  heap.pop();else break;
            mark[heap.top().to]=1;
            heap.pop();
        }
    }
    return 0;
}
