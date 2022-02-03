#include<bits/stdc++.h>
using namespace std;
int a[15],b[15],n;
void permu(int state){
    int i,j;
    if(state==n){
        for(j=n-1;j>=0;j--){
            if(a[j]==0){
                for(i=0;i<n;i++){
                    printf("%d",a[i]);
                }
                a[j]=1;
                printf(" ");
                for(i=0;i<n;i++){
                    printf("%d",a[i]);
                }
                a[j]=0;
                printf("\n");
            }
        }
        return;
    }
        /*printf(" ");
         for(i=0;i<n;i++){
            printf("%d",b[i]);
        }
        printf("\n");
        return;
    }*/
    a[state]=0;
    permu(state+1);
    a[state]=1;
    permu(state+1);
}
int main(){
    scanf("%d",&n);
    permu(0);
return 0;
}
