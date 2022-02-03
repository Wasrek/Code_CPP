/*
    TASK: Soldier
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int id,ran,tim;
    bool operator < (const A& o)const{
       if(ran!=o.ran) return ran < o.ran;
       else           return tim > o.tim;
    }
};
priority_queue< A > heap;
int main()
{
    int n,r,opr,i,id;
    scanf("%d %d",&n,&r);
    for(i=0;i<n;i++){
        scanf("%d",&opr);
        if(opr==1){
            scanf("%d %d",&id,&r);
            heap.push({id,r,i});
        }
        else{
            if(heap.empty())
                printf("-1\n");
            else{
                printf("%d\n",heap.top().id);
                heap.pop();
            }
        }
    }
    return 0;
}
