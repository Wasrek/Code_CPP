/*
    TASK:Lunla Sequence
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[30];
int main()
{
    int q,i,len;
    scanf("%d",&q);
    while(q--){
        a[0]='0';
        scanf(" %s",&a[1]);
        len = strlen(a);
        next_permutation(a,a+len);
        if(a[0]=='0')
            printf("%s\n",&a[1]);
        else
            printf("%s\n",a);
    }

    return 0;
}
