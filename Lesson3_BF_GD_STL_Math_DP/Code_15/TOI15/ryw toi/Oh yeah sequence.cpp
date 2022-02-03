/*
    TASK:Oh yeah sequence
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[200100],add[200100];
int main(){
    int n,cnt=1,i,opr,x,y;
    long long sum=0;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&opr);
        if(opr==1){
            scanf("%d %d",&x,&y);
            sum+=(x*y);
            add[x-1]+=y;
        }else
        if(opr==2){
            scanf("%d",&a[cnt]);
            add[cnt]=0;
            sum+=a[cnt];
            cnt++;
        }else
        if(opr==3){
            cnt--;
            sum-=(a[cnt]+add[cnt]);
            add[cnt-1]+=add[cnt];
        }
        printf("%lld %d\n",sum,cnt);
    }
    return 0;
}
/*
6
2 1
1 2 20
2 2
1 2 -3
3
3
*/
