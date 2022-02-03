/*
    TASK:Magnet YTOPC
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[200100],b[200100];
int main(){
    int n,m,q,i,r,s,cnt=0,j;
    scanf("%d %d %d",&n,&m,&q);
    while(m--){
        scanf("%d %d",&r,&s);
        a[cnt++]=r,a[cnt++]=r+s;
    }
    sort(a,a+cnt);
    for(i=0,r=0;i<cnt;i=j){
        for(j=i+1;j<cnt && a[i]==a[j];j++);
            if((j-i)%2==1){
                b[r++]=a[i];
            }
    }
    while(q--){
        scanf("%d",&s);
        if(s<b[0])printf("%d\n",b[0]-1);
        else if(s>=b[r-1])printf("%d\n",n-b[r-1]+1);
        else {
            i=upper_bound(b,b+r,s)-b;
            printf("%d\n",b[i]-b[i-1]);
        }
    }
    return 0;
}
/*
10 3 2
2 4
4 5
3 7
7
5
10 3 2 1 1 2 1 1 3 7 5
*/
