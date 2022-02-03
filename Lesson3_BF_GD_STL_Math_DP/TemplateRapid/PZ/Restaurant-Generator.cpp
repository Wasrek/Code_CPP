#include<bits/stdc++.h>
using namespace std;
string filename[10]={"1.in","2.in","3.in","4.in","5.in","6.in","7.in","8.in","9.in","10.in",};
map<pair<long long,long long>,long long> mp;
int main(){
    long long Q,N,i,j,l,r,t,c;
    for(i=0;i<10;i++){
    ofstream MyFile(filename[i]);
    if(i<3) Q=3,N=15;
    else Q=3,N=200;
    MyFile << Q << '\n';
    while(Q--){
        MyFile << N<< '\n';
        t=N;
        while(t){
            l=(rand()*rand())%1000000000;
            r=(rand()*rand())%1000000000;
            if(l>r) swap(l,r);
            c=(rand()*rand())%2000000000;
            if(mp[make_pair(l,r)]==0){
                mp[make_pair(l,r)]=1;
                MyFile << l <<' '<< r << ' '<< c << '\n';
                t--;
            }
        }
    }
    }
return 0;
}
