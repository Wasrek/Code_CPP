/*
    TASK:android
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010],b[1010],mark[1010];
queue<int> q;
int main()
{
    int n,s,m,i,j,now,fr;
    scanf("%d %d %d",&n,&s,&m);
    now=m;
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1; i<=s; i++)
    {
        scanf("%d",&b[i]);
        q.push(b[i]);
        if(mark[b[i]]){
            mark[b[i]]++;
            continue;
        }
        if(now>=a[b[i]])
        {
            now-=a[b[i]];
            mark[b[i]]++;
            continue;
        }
        while(!q.empty() && now<a[b[i]]){
            fr=q.front();
            q.pop();
            if(mark[fr]>1){
                mark[fr]--;
                continue;
            }
            mark[fr]--;
            now+=a[fr];
        }
        now-=a[b[i]];
        mark[b[i]]++;
    }
    printf("%d",now);
}