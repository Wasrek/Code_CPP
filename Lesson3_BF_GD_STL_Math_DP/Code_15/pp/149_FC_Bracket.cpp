#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<cstring>
using namespace std;
char a[50001];
long long len,us[2][50001],ans,qs;
priority_queue <long long> q;
int main()
{
    long long i;
    scanf(" %s",a);
    len=strlen(a);
    for(i=0;i<len;i++)
        if(a[i]=='?')
            scanf("%lld %lld",&us[0][i],&us[1][i]);
    for(i=0;i<len;i++)
    {
        ans+=us[1][i];
        if(a[i]=='(')
            qs++;
        if(a[i]==')')
            qs--;
        if(a[i]=='?')
        {
            qs--;
            q.push(us[1][i]-us[0][i]);
        }
        if(qs==-1){
            ans-=q.top();
            q.pop();
            qs+=2;
        }
        //printf("%lld ",ans);
    }
    if(qs!=0)
        printf("-1");
    else
        printf("%lld",ans);
    return 0;
}
