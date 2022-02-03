/*
    TASK:Mango Encryption
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[1000100],b[1000100];
vector< int > ans;
int main()
{
    int len,now;
    scanf(" %s",b+1);
    scanf(" %s",a+1);
    len=strlen(a+1);
    for(int i=1;i<=len;i++){
        a[i]=toupper(a[i]);
        b[i]=toupper(b[i]);
        // printf("%c %c\n",a[i],b[i]);
        // printf("%d\n",(b[i]+'Z'-a[i]));
        if(a[i]<=b[i]){
            if(b[i]-a[i]<=9){
                ans.push_back(b[i]-a[i]);
                // printf("%d",b[i]-a[i]);
                // printf("%c %c %d\n",a[i],b[i],b[i]-a[i]);
            }else{
                goto jump;
            }
        }else if((b[i]+'Z'-a[i]-'A'+1)<=9){
                ans.push_back(b[i]+'Z'-a[i]-'A'+1);
                // printf("%c %c %d\n",a[i],b[i],b[i]+'Z'-a[i]);
        }else{
            goto jump;
        }
    }
    // printf("here\n");
    for(auto x: ans){
        printf("%d",x);
    }
    return 0;
    jump:
    printf("R.I.P.");
    return 0;
}