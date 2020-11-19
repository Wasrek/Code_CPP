/*
    TASK: Van Booking2
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
   int id,day;
   bool operator < (const A& o)const{
      if(day!=o.day) return day > o.day;//heap is opposite when sort day > o.day normally it will be decrease from max to min but it is heap so it will be opposite
      else           return id > o.id;//equal -> order by id
   }
};
priority_queue< A > he;
A temp;
int main()
{
    int n,k,i;
    scanf("%d %d",&n,&k);
    for(i=1;i<=k;i++)
       he.push({i,0});//i=id 0=day order by tuaprae
    while(n--){
        temp = he.top();
        he.pop();
        printf("%d\n",temp.id);
        scanf("%d",&i);
        temp.day+=i;
        he.push(temp);
    }
    return 0;
}
