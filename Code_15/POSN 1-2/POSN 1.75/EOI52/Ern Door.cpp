/*
    TASK:Ern Door
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
string a,b;
int main(){
    int i,ansa=0,ansb=0,coua=0,coub=0,cha=0,chb=0;
    cin>>a;
    cin>>b;
    //cout<<a.size()<<endl;
    while(a.size()<b.size()){a='0'+a;}
    while(b.size()<a.size()){b='0'+b;}
    //cout<<a<<endl;
    for(i=(a.size()-1);i>=0;i--){
        //cout<<endl<<b[i]<<" "<<a[i];
        if(a[i]>b[i]){
            ansa+=((a[i]-'0')*(pow(10.0,coua))),coua++;
            cha=1;
        }else if(a[i]<b[i]){
            ansb+=((b[i]-'0')*(pow(10.0,coub))),coub++;
            //cout<<"ansb"<<" "<<ansb<<endl;
            chb=1;
        }else if(a[i]==b[i]){
            ansa+=((a[i]-'0')*(pow(10.0,coua))),coua++;
            ansb+=((b[i]-'0')*(pow(10.0,coub))),coub++;
            cha=1,chb=1;
        }
    }
    if(cha==0)cout<<"Ern"<<endl;
    else{
        cout<<ansa<<endl;
    }
    if(chb==0)cout<<"Ern"<<endl;
    else{
        cout<<ansb<<endl;
    }
}
