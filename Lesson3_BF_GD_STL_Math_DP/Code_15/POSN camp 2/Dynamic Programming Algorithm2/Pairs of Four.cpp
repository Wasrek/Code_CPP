/*
    TASK:Pairs of Four
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char x[1010];
int mic[1010][1010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf(" %c",&x[i]);
    for(int j=1;j<=n;j++){
        for(int i=j-1;i>=1;i--){
            if(x[i]==x[j])
                mic[i][j]=mic[i+1][j-1]+1;
            for(int k=1;k<j;k++)
                mic[i][j] = max(mic[i][j],mic[i][k]+mic[k+1][j]);
        }
    }
    printf("%d\n",mic[1][n]);
    return 0;
}
