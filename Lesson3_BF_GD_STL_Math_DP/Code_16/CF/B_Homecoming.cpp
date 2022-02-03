#include<bits/stdc++.h>
using namespace std;
struct A{
    char c;
    int a;
};
A st[100010];
char s[100010];
int main()
{
    int q,a,b,c,len,now;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&a,&b,&c);
        scanf(" %s",s+1);
        len=strlen(s+1);
        if(c<a && c<b){printf("%d\n",len);continue;}
        now=1;
        st[now].c=s[1];
        st[now].a=1;
        for(int i=2;i<=len;i++){
            if(st[now].c==s[i]){
                st[now].a++;
            }else{
                st[++now].c=s[i];
                st[now].a=1;
            }
        }
        // printf("here %d %d\n",now,len);
        // for(int i=1;i<=now;i++){
        //     printf("%c %d\n",st[i].c,st[i].a);
        // }
        if(st[now].a==1)now--;
        int l=0,r=now+1;
        long long sum,mid;
        // printf("%d\n",now);
        while(l<r){
            mid=(l+r)/2;
            sum=0;
            for(int i=mid;i<=now;i++){
                if(st[i].c=='A')sum+=a;
                else sum+=b;
            }
            if(sum>c)l=mid+1;
                else r=mid;
            // printf("'bs %d %d %d\n",sum,l,r);
        }
        // printf("%d %d\n",l,r);
        sum=1;
        for(int i=1;i<l;i++){
            sum+=st[i].a;
        }
        if(sum>len)sum=len;
        printf("%lld\n",sum);
    }
    return 0;
}
//can't to can