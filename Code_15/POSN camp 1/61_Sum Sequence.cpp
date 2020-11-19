/*
    TASK:\
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[30],s,cou=0;
void play(int k,int sum,int n){
    if(sum>s)return ;
    int i;
    if(sum==s)
    {
        cou++;
        if(cou==k)
        {
            for(i=0; i<n; i++)
            {
                printf("%d",a[i]);
            }
            printf("\n");
        }
        return ;
    }
    for(i=1; i<=9; i++)
    {
        a[n]=i;
        if(sum+i>s)break;
        play(k,sum+i,n+1);
    }

}
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&s,&n);
        cou=0;
        play(n,0,0);
    }
    return 0;
}
