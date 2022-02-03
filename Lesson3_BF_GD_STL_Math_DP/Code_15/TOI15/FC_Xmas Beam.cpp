/*
    TASK:FC_Xmas Beam
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
    bool operator<(const A &o)const{
        if(y!=o.y)return y<o.y;
        return x<o.x;
    }
};
A a[100010];
int main(){
    int q,n,h,i,mi,j;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&h);
        for(i=1;i<=n;i++){
            scanf("%d %d",&a[i].x,&a[i].y);
        }
        sort(a+1,a+1+n);
        j=1,mi=-1;
        for(i=n;i>=1;i--){
            if(a[i].y-a[1].y<h){
                //printf("-");
                break;
            }
            //printf("%d",i);
            while(j<=i){
                if(mi!=-1)
                mi=min(mi,abs(a[i].x-a[j].x));
                else mi=abs(a[i].x-a[j].x);
                j++;
                if(a[i].y-a[j].y<h){
                    break;
                }
            }
            j=1;
        }
        printf("%d\n",mi);
    }
    return 0;
}
