/*
    TASK:Pattern matching
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char s[110][110],ans[103][10010];
int main()
{
    int q,n,Q,len,ch,now,ni;
    scanf("%d",&Q);
    for(int q=1;q<=Q;q++){
        scanf("%d",&n);
        ch=1;
        for(int i=1;i<=n;i++){
            scanf(" %s",s[i]+1);
            if(!ch) continue;
            len=strlen(s[i]+1);
            // printf("%d\n",len);
            if(s[i][1]!='*'){
                now=1;
                ni=1;
                while(s[i][ni]!='*'){
                    if(ans[q][now]!=s[i][ni] && ans[q][now]!=ans[q][0]){
                        ch=0;
                        break;
                    }else ans[q][now]=s[i][ni];
                    now++;
                    ni++;
                }
            }
            if(s[i][len]!='*'){
                now=10000;
                ni=len;
                while(s[i][ni]!='*'){
                    if(ans[q][now]!=s[i][ni] && ans[q][now]!=ans[q][0]){
                        ch=0;
                        break;
                    }else ans[q][now]=s[i][ni];
                    now--;
                    ni--;
                }
            }
        }
        printf("Case #%d: ",q);
        if(ch){
            for(int i=1;i<=10000;i++){
                if(ans[q][i]==ans[q][0])continue;
                printf("%c",ans[q][i]);
            }
            printf("\n");
        }else printf("*\n");
    }
    return 0;
}