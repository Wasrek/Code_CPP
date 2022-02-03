#include<bits/stdc++.h>
using namespace std;
map<long long,long long> toilet; // LOL
map<long long,long long>::iterator it; // iterator
int main(){
    long long a,b;
    int q,qq;
    scanf(" %d",&q);
    for(qq=1;qq<=q;qq++){
        scanf(" %lld %lld",&a,&b);
        long long sent=0; // people that already used toilet
        toilet[a]=1;
        it=toilet.end();
        it--;
        while(1){
            if(sent+it->second>=b){ // answer this!
                printf("Case #%d: %lld %lld\n",qq,it->first/2,(it->first-1)/2);
                break;
            }
            sent+=it->second;
            toilet[it->first/2]+=it->second;
            toilet[(it->first-1)/2]+=it->second;
            it--;
        }
        toilet.clear();
    }
    return 0;
}
