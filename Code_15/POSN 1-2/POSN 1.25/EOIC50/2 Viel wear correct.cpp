#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num=0,n,i;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&i);
        if(i>num+1){
            printf("%d\n",num+1);
            return 0;
        }
        num+=i;
    }
    printf("%d\n",num+1);
    return 0;
}
