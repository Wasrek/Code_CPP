#include<bits/stdc++.h>
using namespace std;
int n[10000000];
int main()
{
    int sum=0,i=0;
    while(1)
    {
        scanf("%d",&n[i]);
        if(n[i]!=1234567890)
        {
            sum+=n[i];
            printf("%d\n",sum);
            i++;
        }
        else{
            printf("\n----------------------------------");break;
        }
    }
    int j;
    for(j=0; j<i; j++)
    {
        printf("\n%d",n[j]);
    }
}
