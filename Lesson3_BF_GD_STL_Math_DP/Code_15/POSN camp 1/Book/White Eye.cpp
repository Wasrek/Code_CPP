/*
    TASK:White Eye
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
stack<int> st;
int main()
{
    int n,m,i,j;
    char a ;
    scanf("%d %d",&n,&m);
    for(i=0;i<n+m;i++){
        scanf(" %c",&a);
        if(a=='A'){
            scanf("%d",&j);
            while(!st.empty() && j>=st.top())
                st.pop();
            st.push(j);
        }else{
            printf("%d\n",st.size());
        }
    }
    return 0;
}
