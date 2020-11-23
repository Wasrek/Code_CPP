/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
};
bool cmpx(A a,A b){
    return a.x<b.x;
};
bool cmpy(A a,A b){
    return a.y<b.y;
}
double dis(A a,A b){
    double now=sqrt(1.0*(a.x-b.x)*(a.x-b.x)+1.0*(a.y-b.y)*(a.y-b.y));
    return now;
}
A pts[100010];
double clo_pair(A a[],int n){
    if(n<=3){
        double mi=2000000000.0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mi=min(mi,dis(a[i],a[j]));
            }
        }
        return mi;
    }
    int mid=n/2;
    double mil=clo_pair(a,mid);//right
    double mir=clo_pair(a+mid,n-mid);//left
    double d,mi;
    mi=d=min(mil,mir);
    A strip[n+2];
    int idx=0;
    for(int i=0;i<n;i++){
        if(abs(a[i].x-a[mid].x)<d){
            strip[idx++]=a[i];
        }
    }
    sort(strip,strip+idx,cmpy);
    for(int i=0;i<idx;i++){
        for(int j=i+1;j<idx && abs(strip[i].y-strip[j].y)<=d ;j++){
            mi=min(mi,dis(strip[i],strip[j]));
        }
    }
    return mi;
}
int main()
{
    int q,n;
    double cp,r,d;
    scanf("%d",&q);
    while(q--){
        scanf("%d %lf %lf",&n,&r,&d);
        for(int i=0;i<n;i++){
            scanf("%d %d",&pts[i].x,&pts[i].y);
        }
        sort(pts,pts+n,cmpx);
        cp=clo_pair(pts,n);
        printf((cp>=2*r+d)?"Y\n":"N\n");
    }
    return 0;
}