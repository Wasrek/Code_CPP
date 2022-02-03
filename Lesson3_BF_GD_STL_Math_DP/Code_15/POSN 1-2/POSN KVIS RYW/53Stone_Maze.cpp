/*
    TASK:53Stone_Maze
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q,cou,r,c,i,j;
    char a;
    scanf("%d",&q);
    while(q--){
        cou=0;
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                scanf(" %c",&a);
                if(a=='.')cou++;
            }
        }
        printf("%d\n",(cou-1)*2);
    }
    return 0;
}
