/*
    TASK:Plantation_TOI14
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
#define INF 2e9
struct A{
    long long x,y;
};
A a[100100];
bool cmpbyx(A a,A b){
    return a.x < b.x;
}//sort  by x
bool cmpbyy(A a,A b){
    return a.y < b.y;
}//sort by y
double dis(A a,A b){
    return sqrt((double)((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}//find the distance between 2 points
double closest(A b[],int n){
    double dl,dr,d,old;
    int mid,i,j,k;
    if(n<=3){
        for(i=0,d=INF;i<n;i++){
            for(j=i+1;j<n;j++){
                d=min(d,dis(b[i],b[j]));
            }
        }
        return d;
    }//base case
    mid=n/2;
    dl=closest(b,mid);//closest pair of the left side;the minimum value from the left side
    dr=closest(b+mid,n-mid);//closest pair right side;the minimum value from the right side
    d=min(dl,dr);
    A strip[n+3],mp=b[mid];
    for(i=0,j=0;i<n;i++){
        if(abs(b[i].x-mp.x)<=d)
            strip[j++]=b[i];
    }
    sort(strip,strip+j,cmpbyy);
    old = d;
    for(i=0;i<j;i++){
        for(k=i+1;k<j && strip[k].y-strip[i].y<=old ;k++){//strip[k].y-strip[i].y<=old important function so it check only 6 points
            d=min(d,dis(strip[i],strip[k]));
        }
    }
    return d;
}//closest pair
int main(){
    int q,n,i;
    double dist,r,d;
    scanf("%d",&q);
    while(q--){
        scanf("%d %lf %lf",&n,&r,&d);//r=radius of each circle d=the distance that we want to check if any circle closer to each other than d or not
        for(i=0;i<n;i++){
            scanf("%d %d",&a[i].x,&a[i].y);
        }
        sort(a,a+n,cmpbyx);
        dist = closest(a,n);
//        printf("%lf\n",dist);
        printf((dist>=2*r+d)?"Y\n":"N\n");
    }
    return 0;
}
/*


*/
