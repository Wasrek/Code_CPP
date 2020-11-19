/*
    TASK:Nesting Depth
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[110];
vector< char > ans;
int main()
{
    int Q,q,now,len;
    scanf("%d",&Q);
    for(int q=1;q<=Q;q++){
        scanf(" %s",a+1);
        len=strlen(a+1);
        now=0;
        for(int i=1;i<=len;i++){
            a[i]-='0';
            if(now==a[i]){ans.push_back(a[i]+'0');continue;}
            if(a[i]>now){
                while(now<a[i]){
                    ans.push_back('(');
                    now++;
                }                
            }
            if(a[i]<now){
                while(now>a[i]){
                    ans.push_back(')');
                    now--;
                }
            }
            ans.push_back(a[i]+'0');
        }
        while(now){
            ans.push_back(')');
            now--;
        }
        printf("Case #%d: ",q);
        for(auto x: ans) printf("%c",x);
        printf("\n");
        ans.clear();
    }
    return 0;
}