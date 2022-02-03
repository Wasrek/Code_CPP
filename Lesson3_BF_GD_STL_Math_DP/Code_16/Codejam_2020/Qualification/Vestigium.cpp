/*
    TASK:Vestigium
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[110][110];
unordered_map<int,int> c;
int main()
{
    int q,Q,n,dia,ch,sr,sc;
    scanf("%d",&Q);
    for(int q=1;q<=Q;q++){
        scanf("%d",&n);
        dia=sr=sc=0;
        for(int i=1;i<=n;i++){
            ch=0;
            for(int j=1;j<=n;j++){
                scanf("%d",&a[i][j]);
                if(i==j){
                    dia+=a[i][j];
                }
                // printf(" - %d %d  %d - ",j,a[i][j],r[j][a[i][j]]);
                if(c[a[i][j]])ch=1;
                c[a[i][j]]++;
                // printf(" - %d  %d - ",a[i][j],r[j][a[i][j]]);
            }
            // printf("\n");
            sc+=ch;
            c.clear();
        }
        for(int i=1;i<=n;i++){
            ch=0;
            for(int j=1;j<=n;j++){
                // printf(" - %d %d  %d - ",j,a[i][j],r[j][a[i][j]]);
                if(c[a[j][i]])ch=1;
                c[a[j][i]]++;
                // printf(" - %d  %d - ",a[i][j],r[j][a[i][j]]);
            }
            // printf("\n");
            sr+=ch;
            c.clear();
        }
        printf("Case #%d: %d %d %d\n",q,dia,sc,sr);
    }
    return 0;
}
/*
3
4
1 2 3 4
2 1 4 3
3 4 1 2
4 3 2 1
4
2 2 2 2
2 3 2 3
2 2 2 3
2 2 2 2
3
2 1 3
1 3 2
1 2 3
*/