/*
    TASK:Tanya and Candies
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[200100],odd[100100],even[100100];
int main(){
    int n,i,cd=0,ce=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(i%2){
            odd[++cd]=odd[cd-1]+a[i];
        }else{
            even[++ce]=even[ce-1]+a[i];
        }
    }
    int cou=0,se,so;
    for(i=1;i<=n;i++){
        if(i%2){
            so=odd[i/2]+even[ce]-even[i/2];
            se=even[i/2]+odd[cd]-odd[i/2+1];
        }else{
            so=odd[i/2]+even[ce]-even[i/2];
            se=even[i/2-1]+odd[cd]-odd[i/2];
        }
        if(so==se){
            cou++;
        }
    }
    printf("%d\n",cou);
    return 0;
}
