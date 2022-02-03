#include<bits/stdc++.h>
using namespace std;
char s[50];
int a[15]={0,9,189,2889,38889,488889,5888889,68888889,788888889,INT_MAX};
int main()
{
    int q,n;
    double k;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        k=n;
        for(int i=1;i<=n;i++){
            if(k>a[i]) continue;
            k-=a[i-1];
            k=ceil(k/i);
            k=k+(pow(10.0,i-1))-1;
            sprintf(s,"%d",int(k));
            printf("%c\n",s[(((n-a[i-1])%i)+i-1)%i]); 
            break;
        }
    }
    return 0;
}