/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
long long cnt=0;
void ms(int l,int r){
    if(l>=r) return;
    int mid=(l+r)/2;
    ms(l,mid);
    ms(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid && j<=r){
        if(a[i]<=a[j]){
            b[k++]=a[i];
            i++;
        }else {
            b[k++]=a[j];
            j++;
            cnt+=mid-i+1;
        }
    }
    while(i<=mid){
        b[k++]=a[i];
        i++;
    }
    while(j<=r){
        b[k++]=a[j];
        j++;
    }
    for(int i=l;i<=r;i++){
        a[i]=b[i];
    }
    return ;
}
int main()
{
    int n,q;
    scanf("%d",&q);
    while(q--){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    cnt=0;
    ms(1,n);
    // printf("%d\n",cnt);
    if(cnt%2) printf("no\n");
    else printf("yes\n");
    }
    return 0;
}