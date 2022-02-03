/*
    TASK: Coca Land 2.0
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
   int type,beauty,day,newb;
   bool operator < (const A& o)const{
      if(beauty!=o.beauty) return beauty > o.beauty;
      else                 return type > o.type;
   }
};
priority_queue< A > h;
int main()
{
    int p,opr,i,a,b,c;
    A temp;
    scanf("%d",&p);
    for(i=0;i<p;i++){
        scanf("%d",&opr);
        if(opr==1){//type2 normal
            scanf("%d %d",&a,&b);
            h.push({2,a,b,0});
        }else
        if(opr==2){//type 3 last forever
            scanf("%d",&a);
            h.push({3,a,0,0});
        }else
        if(opr==3){//type 1 evolution
            scanf("%d %d %d",&a,&b,&c);
            h.push({1,a,b,c});
        }else{
           while(1){
            if(h.empty()){
                printf("GREAN\n");break;
            }
            temp = h.top();
            h.pop();
            if(temp.type==2 && temp.day<=i)continue;
            if(temp.type==1 && temp.day<=i){
                temp.beauty = temp.newb;
                temp.day = 2000000;
                h.push(temp); continue;
            }
            printf("%d\n",temp.beauty);
            break;
           }
        }
    }
    return 0;
}
