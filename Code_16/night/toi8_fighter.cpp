/*
    TASK:TOI8_fighter
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,num,cnto,cnte,odd,even;
    odd=even=cnto=cnte=0;
    scanf("%d",&n);
    for(int i=1;i<=n*2;i++){
        scanf("%d",&num);
        if(num%2){
            cnto++;
            cnte=0;
            if(cnto>2){
                odd+=3;
            }else{
                odd++;
            }
        }else{
            cnte++;
            cnto=0;
            if(cnte>2){
                even+=3;
            }else{
                even++;
            }
        }
        if(odd>=n){
            printf("1\n");
            printf("%d\n",num);
            return 0;
        }
        if(even>=n){
            printf("0\n");
            printf("%d\n",num);
            return 0;
        }
    }
    return 0;
}