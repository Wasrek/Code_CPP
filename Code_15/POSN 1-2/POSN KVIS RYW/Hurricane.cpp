/*
    TASK:Hurricane
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
stack<PII> st;
PII temp;
int main(){
    int n,h;
    long long ans=0;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&h);
        temp.first=h,temp.second=1;
        for(;!st.empty() && h>=st.top().first;st.pop()){
            if(st.top().first==h)
                temp.second+=st.top().second;
            ans+=st.top().second;
        }
        if(!st.empty()) ans++;
        st.push(temp);
    }
    printf("%lld\n",ans);
    return 0;
}
