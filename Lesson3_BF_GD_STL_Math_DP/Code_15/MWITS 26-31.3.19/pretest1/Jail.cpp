/*
    TASK:Jail
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
deque<int> a,b;
int main(){
    int n,m,i,last=0,cou=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)a.push_back(i);
    while(1){
        while(!a.empty()){
            last++;last%=m;
            if(last==0){printf("%d ",a.front());cou++;}else{a.push_back(a.front());}
            if(cou==n)return 0;
            a.pop_front();
        }
        while(!b.empty()){
            last++;last%=m;
            if(last==0){printf("%d ",b.front());cou++;}else{a.push_back(b.front());}
            if(cou==n)return 0;
            b.pop_front();
        }
    }
}
