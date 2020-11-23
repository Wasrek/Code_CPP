/*
    TASK: Plantation TOI14
    LANG: CPP
    AUTHOR: PeaTT~
*/
#include<bits/stdc++.h>
using namespace std;
#define INF 2000000000
struct A{
    int x,y;
};
A a[100100];
bool cmpbyx(A a,A b){
    return a.x < b.x;
}
bool cmpbyy(A a,A b){
    return a.y < b.y;
}
double dist(A a,A b){
    return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+(double)(a.y-b.y)*(a.y-b.y));
}
double closest(A a[],int n){
    int i,j,mid,k;
    double d,dl,dr,old;
    if(n<=3){
        for(i=0,d=INF;i<n;i++)
            for(j=i+1;j<n;j++)
                d=min(d,dist(a[i],a[j]));
        return d;
    }
    mid = n/2;
    dl = closest(a,mid);
    dr = closest(a+mid,n-mid);
    old = d = min(dl,dr);
    A strip[n+5];
    for(i=0,j=0;i<n;i++){
        if(abs(a[i].x-a[mid].x)<d)
            strip[j++]=a[i];
    }
    sort(strip,strip+j,cmpbyy);
    for(i=0;i<j;i++){
        for(k=i+1;k<j&&abs(strip[i].y-strip[k].y)<=old;k++){
            d=min(d,dist(strip[i],strip[k]));
        }
    }
    return d;
}
int main()
{
	int q,n,i;
	double dis,r,d;
	scanf("%d",&q);
	while(q--){
        scanf("%d %lf %lf",&n,&r,&d);
        for(i=0;i<n;i++)
            scanf("%d %d",&a[i].x,&a[i].y);
        sort(a,a+n,cmpbyx);
        dis = closest(a,n);
        printf((dis>=d+2*r)?"Y\n":"N\n");
	}
    return 0;
}
/*
5 2 1 1 0 0 4 0 2 1 1 0 0 2 0
3 1 2 0 0 -2 2 2 1 3 1 2 0 0 4 1 -4 0 3 1 2 0 0 3 1 -4 0
*/
