/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
map<vector<pair<int,int>>,int> mp; 
vector< pair<int,int> > g;
int main()
{
    int a,q,u,v,n;
    scanf("%d %d",&a,&q);
    for(int i=1;i<=a;i++){
        scanf("%d",&n);
        for(int j=1;j<n;j++){
            scanf("%d %d",&u,&v);
            if(u>v) swap(u,v);
            g.push_back({u,v});
        }
        sort(g.begin(),g.end());
        mp[g]++;
        g.clear();
    }
    for(int i=1;i<=q;i++){
        scanf("%d",&n);
        for(int j=1;j<n;j++){
            scanf("%d %d",&u,&v);
            if(u>v) swap(u,v);
            g.push_back({u,v});
        }
        sort(g.begin(),g.end());
        printf("%d\n",mp[g]);
        g.clear();
    }
    return 0;
}
/*
3 2
10
1 2
6 4
2 5
3 5
8 6
2 7
5 8
8 9
4 10
6
1 4
2 4
4 3
5 4
5 6
10
1 2
2 7
2 5
3 5
8 6
4 6
5 8
8 9
4 10
6
1 4
2 4
4 3
5 4
1 6
10
1 2
2 7
2 5
3 5
8 6
4 6
5 8
8 9
4 10
*/