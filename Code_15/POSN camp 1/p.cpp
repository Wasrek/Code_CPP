/*#include<bits/stdc++.h>
using namespace std;
int n,r,k,a[15],b[15],cou=0;
void permu(int state)
{
    int i;
   if(state==r)
   {
       cou++;
       if(cou==k){
        for(i=0;i<r;i++)
        {
            printf("%d ",b[i]);
        }
        exit(0);
       }
   }
   for(i=1;i<=n;i++)
   {
       if(a[i]!=1){
        a[i]=1;
        b[state]=i;
        permu(state+1);
        a[i]=0;
       }
   }
}
int main()
{
   scanf("%d %d %d",&n,&r,&k);
   permu(0);
   return 0;
}
*/
/*

#include<bits/stdc++.h>
using namespace std;
int k,n,cou=0,r,b[15],a[15];
void permu(int state){
    int i;
    if(state==r)
    {
        cou++;
        if(cou==k){
            for(i=0;i<r;i++)
            {
                printf("%d ",b[i]);
            }
            exit(0);
        }
        return ;
    }
    for(i=1;i<=n;i++){
        if(a[i]!=1){
            a[i]=1;
            b[state]=i;
            permu(state+1);
            a[i]=0;
        }
    }
}

int main()
{
   scanf("%d %d %d",&n,&r,&k);
   permu(0);
   return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
int n,r,k,a[15],b[15],cou=0;
void permu(int state)
{
    int i;
    if(state==r)
    {
        cou++;
        if(k==cou){
            for(i=0;i<r;i++)
            {
                printf("%d ",b[i]);
            }
            exit(0);
        }
        return ;
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]!=1){
            a[i]=1;
            b[state]=i;
            permu(state+1);
            a[i]=0;
        }
    }
}
int main(){
scanf("%d %d %d",&n,&r,&k);
permu(0);
return 0;
}
