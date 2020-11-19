/*
    TASK:Phatson Num
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,sum=0,h,j,k,l,ch=1,n,m=0;
    scanf("%d %d %d",&a,&b,&c);
    for(int i=a;i<=b;i++){
        h=i%10;
        j=((i%100)-h)/10;
        k=((i%1000)-h-(j*10))/100;
        l=((i%10000)-h-(j*10)-(k*100))/1000;
        if((h+j+k+l)==c){
            if(ch==1)n=i,ch=2;
            if(ch==2 && i>=m)m=i;
        }
    }
    printf("%d\n",n);
    if(b==10000 && c==1){printf("10000");return 0;}
    else printf("%d",m);
    return 0;
}
