/*
    TASK:Briquette
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int p[10100],ch[10100];
int fin(int i){
   if(p[i]==i) return i;
   else return p[i]=fin(p[i]);
}
int main()
{
    int n,m,k,nl,l,j,i,ans=0,last;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){p[i]=i;}
    for(i=1;i<=n;i++){
        scanf("%d",&nl);
        if(nl==0){ans++;continue;}
        scanf("%d",&k);last=k;ch[k]=1;//printf(" check %d = %d \n",k,ch[k]);
        for(j=1;j<nl;j++){
            scanf("%d",&l);ch[l]=1;//printf(" check %d = %d \n",l,ch[l]);
            p[fin(last)]=p[fin(l)];
            last=l;
        }
    }
    //printf("before: %d %d\n",ans,ch[1]);

    for(j=1;j<=m;j++){
       //printf("parant :%d %d %d\n",p[j],ch[j],ch[fin(j)]);
        if(ch[fin(j)]==1)
            ans++,ch[fin(j)]=2;//,printf("\n---%d - %d %d\n",fin(j),j,ch[j])
        }
    printf("%d\n",ans-1);


}
/*
8 7
0
3 1 2 3
1 1
2 5 4
2 6 7
1 3
2 7 4
1 1
*/
