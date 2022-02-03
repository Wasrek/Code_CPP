/*
    TASK:BUU Internet
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[110];
int main()
{
    long long i,m,n,l,r,Max=0,coun,mid,sum;
    scanf("%lld %lld",&m,&n);// m=lan n=room
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
        Max = max(Max,a[i]);
    }
    l=Max,r=1ll<<31;                                                                                                                      //int is not enough so add ll mean long long but you can also use 30 instead it is enough
    while(l<r){
        mid=(l+r)/2;
        sum=0,coun=1;                                                                                                                                          //coun count how many สาย have been used
        for(i=0;i<n;i++){
            if(sum+a[i]>mid)                                                                                                                                         //รวมsumไปเรื่อยๆ เกินต้องตัด เริ่มห้องใหม่
                coun++,sum=a[i];
            else
                sum+=a[i];//ไม่ใช่บวกไป
        }
        if(coun<=m) r=mid;//
        else l=mid+1;//
    }
    printf("%lld",l);//l=r printf l or r will be fine
    return 0;
}
