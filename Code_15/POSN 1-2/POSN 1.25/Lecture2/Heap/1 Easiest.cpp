/*
    TASK: Easiest
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<int> heap;
int main()
{
    int p,num;
    char a;
    scanf("%d",&p);
    while(p--){
        scanf(" %c",&a);
        if(a=='A'){
            scanf("%d",&num);
            heap.push(num*-1);//normally it will be set as maxheap
        }
        else{
            if(heap.empty())
                printf("-1\n");
            else{
                printf("%d\n",heap.top()*-1);
                heap.pop();
            }
        }
    }
    return 0;
}
