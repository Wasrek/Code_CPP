#include "guess.h"
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,char>> query;
int find_answer(int n, int k) {
    int i,j,l,r,mid,mid1,mid2,m,p,mid3;
    char ans;
    if(k==1){
        if(n==1024){
            l=0,r=n-1;
            while(l<r){
                mid=(l+r)/2;
                query.clear();
                for(i=l;i<=mid;i++) query.push_back({i,'R'});
                ans=ask(query);
                if(ans!='R') l=mid+1;
                else r=mid;
            }
            return l;
        }else{
            l=0,r=n-1,m=n,p=1;
            while(l+p<r){
                mid1=(2*l+r)/3;
                mid2=(l+2*r)/3;
                query.clear();
                for(i=l;i<mid2;i++){
                    if((i+p-l)%(2*p)!=0) query.push_back({i,'R'});
                }
                ans=ask(query);
                if(ans=='R') l=l,r=mid2,m/=3,m*=2,p*=2;
                else if(ans=='C') l=l+p,r=mid2+p,m/=3,m*=2,p*=2;
                else l=mid2+1,m/=3;
            }
            return l;
        }

    }else{
        l=0,r=n-1;
        if(n==729){
            while(l<r){
                mid1=(2*l+r)/3;
                mid2=(l+2*r)/3;
                query.clear();
                for(i=l;i<=mid1;i++) query.push_back({i,'R'});
                for(i=mid1+1;i<=mid2;i++) query.push_back({i,'B'});
                ans=ask(query);
                if(ans=='R') r=mid1;
                else if(ans=='B') l=mid1+1,r=mid2;
                else l=mid2+1;
            }
        }else{
            l=0,r=n-1,m=n,p=1;
            while(l+2*p<r){
                mid1=(3*l+r)/4;
                mid2=(2*l+2*r)/4;
                mid3=(l+3*r)/4;
                query.clear();
                for(i=l;i<mid3;i++){
                    if(((i-l)/p)%3==0) query.push_back({i,'R'});
                    else if(((i-l)/p)%3==1) query.push_back({i,'B'});
                }
                ans=ask(query);
                if(ans=='R') m=(m*3)/4,p*=3,l=l,r=l+m-1;
                else if(ans=='B') m=(m*3)/4,l=l+p,r=l+m-1,p*=3;
                else if(ans=='C') m=(m*3)/4,l=l+2*p,r=l+m-1,p*=3;
                else m=m/4,l=mid3+1;
            }
            return l;
        }
        return l;
    }
}