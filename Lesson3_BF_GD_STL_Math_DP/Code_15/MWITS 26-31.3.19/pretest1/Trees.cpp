/*
    TASK:Trees
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[100100],b[100100];
int main(){
    int n,i,ch;
    int l=5;
    while(l--){
    ch=0;
    scanf("%d",&n);
    for(i=1;i<n;i++){
    scanf("%d %d",&a[i].first,&a[i].second);
    if(a[i].first>a[i].second)swap(a[i].first,a[i].second);
    }
    for(i=1;i<n;i++){
    scanf("%d %d",&b[i].first,&b[i].second);
    if(b[i].first>b[i].second)swap(b[i].first,b[i].second);
    }
    sort(a+1,a+n);
    sort(b+1,b+n);
    for(i=1;i<=n;i++){
        if(a[i].first!=b[i].first || a[i].second!=b[i].second){
            ch=1;break;
        }
    }
    if(ch)printf("N\n");
    else printf("Y\n");
    }
    printf("\n");
}
/*
4
1 2 2 3 3 4
1 2 1 3 1 4
9
9 4 3 5 7 5 7 8 2 4 6 4 1 4 1 5
1 4 9 4 1 5 2 4 6 4 3 5 7 5 7 8
9
2 4 6 4 1 4 1 5 9 4 3 5 7 5 7 8
1 4 9 4 1 5 2 4 6 4 3 5 7 5 7 8
9
2 4 9 4 6 4 1 4 1 5 3 5 7 5 7 8
1 4 9 4 1 5 2 4 6 4 3 5 7 5 7 8
9
2 4 9 4 6 4 1 4 1 5 3 5 7 5 7 8
1 4 4 9 1 5 6 4 3 5 7 5 7 8 2 4
*/
