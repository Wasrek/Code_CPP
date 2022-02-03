/*
    TASK: Peatt Package
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int w[100100],c[100100],mark[100100];
int main()
{
	int q,counter=0,i,n,sum,l,r,mid,Max,cou,ch,k;
	scanf("%d",&q);
	while(q--){
        scanf("%d %d",&n,&k);
        for(i=0,sum=0,Max=0;i<n;i++){
            scanf("%d %d",&w[i],&c[i]);
            if(w[i]>Max)    Max=w[i];
            sum+=w[i];
        }
        l=Max,r=sum+1,ch=0;
        while(l<r){
            mid=(l+r)/2;
            counter++,cou=1,sum=0;
            for(i=0;i<n;i++){
                if(sum+w[i]>mid || mark[c[i]]==counter)
                    cou++,counter++,sum=w[i],mark[c[i]]=counter;
                else
                    sum+=w[i],mark[c[i]]=counter;
            }
            if(cou<=k)  r=mid,ch=1;
            else        l=mid+1;
        }
        if(ch)  printf("%d\n",l);
        else    printf("-1\n");
	}
    return 0;
}
/*
2 5 3 10 1 10 2 40 1 30 3 30 4 5 2 10 1 10 2 40 1 30 3 30 1
*/
