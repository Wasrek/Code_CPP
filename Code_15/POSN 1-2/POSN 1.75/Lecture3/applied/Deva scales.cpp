/*
    TASK:Deva scales
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,l=0,r=0,cou=0,val=1,b;
    scanf("%d",&a);
    while(a){
        b=a%3;
        a/=3;
        if(b==1)r+=val,cou++;
        if(b==2)l+=val,a++,cou++;
        val*=3;
    }
    printf("%d %d\n",cou,r);

    return 0;
}
