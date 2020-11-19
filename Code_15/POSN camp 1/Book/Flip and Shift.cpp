/*
TASK: Flip and Shift
LANG: CPP
AUTHOR: KersW
*/
#include <bits/stdc++.h>n
using namespace std;
int main()
{
    int q,n,i,ke,ku,num;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        ke=ku=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&num);
            if(num==1){
                if(i%2==0) ku++;
                else ke++;
            }
        }
        if(n%2==1||abs(ku-ke)<=1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
