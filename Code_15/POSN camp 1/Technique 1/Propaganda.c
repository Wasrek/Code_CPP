/*
    TASK:Propaganda
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,m,ch=1;
    scanf("%d",&n);
    m=(int)sqrt(n);
    for(i=2;i<=m;i++){
        if(n%i==0){
            ch=0;break;
        }
    }
    if(ch && n!=1) printf("Yes\n");
    else printf("No\n");

    return 0;
}
