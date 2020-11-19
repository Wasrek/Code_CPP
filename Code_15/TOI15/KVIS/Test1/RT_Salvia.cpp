/*
    TASK:RT_Salvia
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[30],ans,n;
char str[120];
void play(int state,int now){
    if(state==n){
        if(now==(1<<26)-1)ans++;
        return ;
    }
    play(state+1,now);
    play(state+1,now|a[state]);
}
int main(){
    int q,len,i,j,bit;
    scanf("%d",&q);
    while(q--){
        scanf("%lld",&n);
        for(i=0;i<n;i++){
            scanf(" %s",str);
            len = strlen(str);
            for(j=0,bit=0;j<len;j++)
                bit|=1<<(str[j]-'a');
            a[i]=bit;
        }
        ans=0;
        play(0,0);
        printf("%lld\n",ans);
    }
    return 0;
}
/*
2
9
the
quick
brown
fox
jumps
over
a
lazy
dog
3
abcdefghijklmnopqrstuvwx
abcdefghijklmnopqrstuvwxy
abcdefghijklmnopqrstuvwxyz
*/
