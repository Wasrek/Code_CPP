/*
    TASK:Overexcited_Fan
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char m[1010];
int main()
{
    int q,Q,len,x,y;
    scanf("%d",&Q);
    for(int q=1;q<=Q;q++){
        scanf("%d %d",&x,&y);
        scanf(" %s",m+1);
        len=strlen(m+1);
        printf("Case #%d: ",q);
        if(x==0 && y==0){
            printf("0\n");
            continue;
        }
        for(int i=1;i<=len;i++){
            if(m[i]=='N'){
                y++;
            }else if(m[i]=='S'){
                y--;
            }else if(m[i]=='E'){
                x++;
            }else{
                x--;
            }
            if(abs(x)+abs(y)<=i){
                printf("%d\n",i);
                goto jump;
            }
        }
        printf("IMPOSSIBLE\n");
        jump:;
    }
    return 0;
}