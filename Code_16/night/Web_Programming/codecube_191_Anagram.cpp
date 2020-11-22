/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[2020],b[2020];
long long ha[30];
vector< long long > g;
int main()
{
    scanf(" %s",a+1);
    scanf(" %s",b+1);
    long long lena,lenb,now,prime=1000000007,ma=0,lb;
    lena=strlen(a+1);
    lenb=strlen(b+1);
    ha[0]=1;
    for(int i='B';i<='Z';i++){
        ha[i-'A']=ha[i-'A'-1]*prime;
    }
    // printf("%lld\n",ha[1]);
    for(int i=1;i<=lena;i++){
        now=0;
        for(int j=i;j<=lena;j++){
            now+=ha[a[j]-'A'];
            g.push_back(now);
        }
    }
    sort(g.begin(),g.end());
    for(int i=1;i<=lenb;i++){
        now=0;
        for(int j=i;j<=lenb;j++){
            now+=ha[b[j]-'A'];
            lb=lower_bound(g.begin(),g.end(),now)-g.begin();
            if(lb>g.size()) continue;
            if(g[lb]==now){
                ma=max(ma,(long long)j-i+1);
            }
        }
    }
    printf("%lld\n",ma);
    return 0;
}