/*
    TASK:FC_Cooking
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[20],b[20];
int main(){
    int n,i,m,aa,bb,mi=1<<30,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d",&a[i],&b[i]);
    m=1<<n;
    for(i=1;i<m;i++){
        aa=1,bb=0;
        for(j=0;j<n;j++){
            if(i & (1<<j))
                aa*=a[j],bb+=b[j];
        }
        mi=min(mi,abs(aa-bb));
    }
    printf("%d\n",mi);
    return 0;
}
