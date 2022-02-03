/*
    TASK:Pancake Smile
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[110];
int main(){
    int q,i,len,cnt,j;
    scanf("%d",&q);
    for(j=1;j<=q;j++){
        printf("Case #%d: ",j);
        scanf(" %s",a);
        len=strlen(a);
        a[len++]='+';
        for(i=1,cnt=0;i<len;i++)
            if(a[i]!=a[i-1])
            cnt++;
        printf("%d\n",cnt);
    }
}
