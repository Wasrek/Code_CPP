/*
    TASK:Easiest
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<int> h;
int main()
{
    int p,num;
    char a;
    scanf("%d",&p);
    while(p--){
        scanf(" %c",&a);
        if(a=='A'){
            scanf("%d",&num);
            h.push(num*-1);
        }
        else if(a=='B'){
            if(h.empty())
                printf("-1\n");
            else{
                printf("%d\n",h.top()*-1);
                h.pop();
            }
        }
    }

    return 0;
}
