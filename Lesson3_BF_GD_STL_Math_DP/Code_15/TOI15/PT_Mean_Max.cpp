/*
    TASK:PT_Mean Max
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
double a[300010],qs[300010],temp[300010],comp[300010];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lf",&a[i]);
        qs[i] = qs[i-1]+a[i];
    }
    double l = 1,r = 1e6,mid;
    while(r-l>1e-6){
        mid = (l+r+(1e-6))/2;
        int idx = 1,now,ans = 0;
        printf("-----------------------------\n");
        printf("%lf %lf %lf\n",mid,l,r);
        for(int i=1;i<=n;i++){
            temp[i] = min(temp[i-1],qs[i]-(i*mid));
            printf("%d %lf %lf\n",i,temp[i],qs[i]-(i*mid));
            if(i-k>=0){
                if(qs[i]-(i*mid)-temp[i-k]>1e-6){
                    printf("can -- %lf %lf\n",qs[i]-(i*mid),temp[i-k]);
                    ans = 1;
                    break;
                }
            }
        }
//        printf("%lf %d\n",mid,ans);
        if(ans) l = mid;
        else    r = mid-(1e-6);
    }
    printf("%.1lf\n",l);
	return 0;
}