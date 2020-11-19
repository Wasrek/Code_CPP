/*
    TASK:RT_Rasengan
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int h[300100];
vector<int> peak,canyon;
int main(){
    int n,m,i,r,s;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&h[i]);
    for(i=1;i<=n;i++){
        if(h[i]>h[i-1] && h[i]>h[i+1])peak.push_back(h[i]);
        if(h[i]<h[i-1] && h[i]<h[i+1])canyon.push_back(h[i]);
    }
    sort(peak.begin(),peak.end());
    sort(canyon.begin(),canyon.end());
    while(m--){
        scanf("%d",&i);
        r = lower_bound(peak.begin(),peak.end(),i)-peak.begin();
        s = lower_bound(canyon.begin(),canyon.end(),i)-canyon.begin();
        printf("%d\n",(peak.size()-r)-(canyon.size()-s));
    }
    return 0;
}
