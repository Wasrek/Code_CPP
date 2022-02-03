/*
    TASK:Silent Sound
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
deque<int> Ma,Mi;
int a[1000100];
int main(){
    int n,m,c,i,ch=1;
    scanf("%d %d %d",&n,&m,&c);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        while(!Ma.empty() && a[i]>=a[Ma.back()])Ma.pop_back();
        while(!Mi.empty() && a[i]<=a[Mi.back()])Mi.pop_back();
        while(!Ma.empty() && Ma.front()<=i-m)Ma.pop_front();
        while(!Mi.empty() && Mi.front()<=i-m)Mi.pop_front();
        Ma.push_back(i),Mi.push_back(i);
        if(i>=m && a[Ma.front()]-a[Mi.front()]<=c){
            printf("%d\n",i-m+1);
            ch=0;
        }
    }
    if(ch)printf("NONE\n");
    return 0;
}
