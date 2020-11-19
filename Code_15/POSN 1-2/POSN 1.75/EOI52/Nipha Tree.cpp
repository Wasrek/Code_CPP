/*
    TASK:Nipha Tree
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int d[1000000000000100];
int main()
{
    int n,k,q;
    scanf("%d %d %d",&n,&k,&q);
    for(int i=2;i<=n;i+=3){
        d[i+1]=d[i+2]=d[i]=(i+1)/3;
    }
    while(q--){
        int a,b
        scanf("%d %d",&a,&b);
        if(d[a]==d[b])printf("2\n");
        else{

        }

    }
    return 0;
}
