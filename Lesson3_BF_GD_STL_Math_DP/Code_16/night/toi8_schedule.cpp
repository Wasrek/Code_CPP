/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010],b[1010],day[1010][1010],mi[1010][1010];
int main(){
    int m,n,ld,lm,ud,um;
    scanf("%d %d",&m,&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++){
        day[i][0]=day[i-1][0];
        mi[i][0]=mi[i-1][0];
        if(mi[i][0]+a[i]>m)
            day[i][0]++,mi[i][0]=a[i];
        else
            mi[i][0]+=a[i];
    }
    for(int i=1;i<=n;i++){
        day[0][i]=day[0][i-1];
        mi[0][i]=mi[0][i-1];
        if(mi[0][i]+b[i]>m)
            day[0][i]++,mi[0][i]=b[i];
        else
            mi[0][i]+=b[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ld=day[i][j-1];
            lm=mi[i][j-1];
            if(lm+b[j]>m) ld++,lm=b[j];
            else lm+=b[j];
            
            ud=day[i-1][j];
            um=mi[i-1][j];
            if(um+a[i]>m) ud++,um=a[i];
            else um+=a[i];

            if(ud<ld || (ud==ld && um<=lm))
                day[i][j]=ud,mi[i][j]=um;
            else
                day[i][j]=ld,mi[i][j]=lm;
        }
    }
    printf("%d\n%d\n",day[n][n]+1,mi[n][n]);
    return 0;
}