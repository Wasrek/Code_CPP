/*
    TASK:FC_Oil Drilling
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
set<int> a;
set<int>:: iterator l,r;
int main(){
    int n,k,x;
    scanf("%d %d",&n,&k);
    while(k--){
        scanf("%d",&x);
        if(a.empty()){
            printf("%d\n",n);
        }else{
            l = r =a.lower_bound(x);
            l--;
            if(r==a.begin())
            printf("%d\n",(*r)-x);
            else if(r==a.end()) printf("%d\n",x-(*l));
            else printf("%d\n",min((*r)-x,x-(*l)));
        }
        a.insert(x);
    }
    return 0;
}
