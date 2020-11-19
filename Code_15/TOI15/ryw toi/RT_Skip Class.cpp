/*
    TASK:RT_Skip Class
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100];
int main(){
    int n,k,p,l,r,mid,i,c;
    scanf("%d %d %d",&n,&k,&p);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    l=1,r=100000;
    while(l<r){
        mid=(l+r)/2;
        for(i=0,c=0;i<n;){
            if(a[i]>mid) i+=p,c++;
            else i++;
        }
        if(c<=k) r=mid;
        else l=mid+1;
    }
    printf("%d\n",l);
    return 0;
}
