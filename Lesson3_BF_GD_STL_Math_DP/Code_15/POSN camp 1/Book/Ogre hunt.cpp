/*
    TASK:Ogre hunt
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
string ans;
int main()
{
    int n;
    scanf("%d",&n);
    for(n++;n>1;n/=2)
        ans = ((n&1)?"7":"4") + ans;//n&((2 power of i)-1) equal to n%(2power of i)
    cout<<ans;//printf("%s",ans.c_str());
    return 0;
}
