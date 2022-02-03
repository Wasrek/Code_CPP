#include<bits/stdc++.h>
using namespace std;
int d[100100][7],c[100100][4],c1[100100][4],k[10];
char a[100100],b[100100];
int main(){
    int n,q,i,j,x,y,ans;
    scanf("%d%d",&n,&q);
    scanf(" %s",a+1);
    scanf(" %s",b+1);
    for(i=1;i<=n;i++){
        for(j=0;j<6;j++){
            d[i][j]=d[i-1][j];
            if(j<3){
                c[i][j]=c[i-1][j];
                c1[i][j]=c1[i-1][j];
            }
        }
        if(a[i]=='A'&&b[i]=='T')d[i][0]++;
        else if(a[i]=='A'&&b[i]=='C')d[i][1]++;
        else if(a[i]=='T'&&b[i]=='A')d[i][2]++;
        else if(a[i]=='T'&&b[i]=='C')d[i][3]++;
        else if(a[i]=='C'&&b[i]=='A')d[i][4]++;
        else if(a[i]=='C'&&b[i]=='T')d[i][5]++;
        if(a[i]=='A')c[i][0]++;
        if(a[i]=='T')c[i][1]++;
        if(a[i]=='C')c[i][2]++;
        if(b[i]=='A')c1[i][0]++;
        if(b[i]=='T')c1[i][1]++;
        if(b[i]=='C')c1[i][2]++;
    }
    while(q--){
        scanf("%d%d",&x,&y);
        x++;y++;
        for(j=0;j<6;j++){
            k[j]=d[y][j]-d[x-1][j];
        }
        if(c[y][0]-c[x-1][0]!=c1[y][0]-c1[x-1][0]||
           c[y][1]-c[x-1][1]!=c1[y][1]-c1[x-1][1]||
           c[y][2]-c[x-1][2]!=c1[y][2]-c1[x-1][2]){
            printf("-1\n");
            continue;
        }

        ans=min(k[0],k[2])+min(k[1],k[4])+min(k[3],k[5]);
        ans+=(max(k[0],k[2])-min(k[0],k[2]))*2;
        printf("%d\n",ans);
    }
    return 0;
}
