/*
    TASK:RT_CutString
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int bucket[29],tmp[29];
char str[300005];
long long ans[29];
int main(){
    int i,j;
    scanf(" %s",str+1);
    int n = strlen(str+1);
    for(i=1;i<=n;i++){
        bucket[str[i]-'a']=i;
        for(j=0;j<26;j++)tmp[j+1]=bucket[j];
        sort(tmp,tmp+27);
        for(j=25;j>=0;j--)ans[26-j]+=tmp[j+1]-tmp[j];
    }
    int cnt=26;
    while(ans[cnt]==0)cnt--;
    printf("%d\n",cnt);
    for(i=1;i<=cnt;i++)printf("%lld\n",ans[i]);
}
