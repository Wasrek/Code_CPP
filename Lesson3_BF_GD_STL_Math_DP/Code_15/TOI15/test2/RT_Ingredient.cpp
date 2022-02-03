/*
    TASK:RT_Ingredient
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int x[410],y[410];
int main(){
    int n,m,i,j,cou=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d",&x[i],&y[i]);
        x[i]--;
        y[i]--;
    }
    for(i=0;i<(1<<n);i++){
        cou++;
        //printf("%d\n",i);
        for(j=1;j<=m;j++){
            //printf("%d ",j);
            if(i&(1<<x[j]) && i&(1<<y[j])){cou--;break;}
        }
        //printf("\n");
    }
    printf("%d\n",cou);
    return 0;
}
