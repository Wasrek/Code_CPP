/*
    TASK:Plate Sort
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int n[300100];
int main()
{
    int q;
    scanf("%d",&q);
    while(q--){
        int i,a,most;
        scanf("%d",&a);
        for(i=1;i<=a;i++){
            scanf("%d",&n[i]);
            if(n[i]==a){
                most=i;
            }
        }
        int cou=0,k=a;
        for(i=most;i>0;i--){
            if(n[i]==k){
                cou++;
                k--;
            }
        }
        //printf("%d %d\n",a,cou);
        printf("%d\n",a-cou);
    }
    return 0;
}
