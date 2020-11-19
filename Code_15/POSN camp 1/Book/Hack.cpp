/*
    TASK:Hack
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
string a[10100],b;
char c[100];
int main()
{
    int n,m,k,i;
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<n;i++)
    {
        scanf(" %s",&c);
        a[i]=c;
    }
    sort(a,a+n);
    while(m--){
        scanf(" %s",c);
        i=lower_bound(a,a+n,c)-a;
        if(a[i]==c)printf("Accepted\n");
        else       printf("Rejected\n");
    }
    return 0;
}
