/*
    TASK:PVZ_51
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k,h,q;
    scanf("%d",&q);
    while(q--){
    scanf("%d",&n);
    k=(6*n)+3;
        for(j=1;j<=((2*n)-1);j+=2){
            for(h=0;h<((k-j)/2);h++){
                printf(" ");
            }
            for(h=0;h<j;h++)
            {
                printf("*");
            }
            for(h=0;h<((k-j)/2);h++){
                printf(" ");
            }
        printf("\n");
        }
        for(j=0;j<n;j++){printf(" ");}
        for(h=0;h<n;h++)
            {
                printf("*");
            }
        for(h=0;h<((2*n)+3);h++)printf(" ");
        for(h=0;h<n;h++)
            {
                printf("*");
            }
        for(j=0;j<n;j++){printf(" ");}
        printf("\n");
        for(j=n-1;j>=0;j--)
        {
            for(h=0;h<n;h++){printf(" ");}
            for(h=0;h<j;h++)
            {
                printf("*");
            }
            printf(" ");
            for(h=0;h<(4*n)+1-(2*j);h++)
            {
                printf("+");
            }
            printf(" ");
            for(h=0;h<j;h++)
            {
                printf("*");
            }
            for(h=0;h<n;h++){printf(" ");}
            printf("\n");
        }
        for(j=1;j<n;j++){
            for(h=0;h<(n-j);h++)printf(" ");
            for(h=0;h<j;h++)printf("*");
            printf(" ");
            for(h=0;h<(4*n)+1;h++)printf("+");
            printf(" ");
            for(h=0;h<j;h++)printf("*");
            for(h=0;h<(n-j);h++)printf(" ");
            printf("\n");
        }




            for(h=0;h<n;h++)printf("*");
            printf(" ");
            for(h=0;h<(4*n)+1;h++)printf("+");
            printf(" ");
            for(h=0;h<n;h++)printf("*");
            printf("\n");



        for(j=n-1;j>=1;j--){
            for(h=0;h<(n-j);h++)printf(" ");
            for(h=0;h<j;h++)printf("*");
            printf(" ");
            for(h=0;h<(4*n)+1;h++)printf("+");
            printf(" ");
            for(h=0;h<j;h++)printf("*");
            for(h=0;h<(n-j);h++)printf(" ");
            printf("\n");
        }
        for(j=0;j<=n-1;j++)
        {
            for(h=0;h<n;h++){printf(" ");}
            for(h=0;h<j;h++)
            {
                printf("*");
            }
            printf(" ");
            for(h=0;h<(4*n)+1-(2*j);h++)
            {
                printf("+");
            }
            printf(" ");
            for(h=0;h<j;h++)
            {
                printf("*");
            }
            for(h=0;h<n;h++){printf(" ");}
            printf("\n");
        }
        for(j=0;j<n;j++){printf(" ");}
        for(h=0;h<n;h++)
            {
                printf("*");
            }
        for(h=0;h<((2*n)+3);h++)printf(" ");
        for(h=0;h<n;h++)
            {
                printf("*");
            }
        for(j=0;j<n;j++){printf(" ");}
        printf("\n");

        for(j=((2*n)-1);j>=1;j-=2){
            for(h=0;h<((k-j)/2);h++){
                printf(" ");
            }
            for(h=0;h<j;h++)
            {
                printf("*");
            }
            for(h=0;h<((k-j)/2);h++){
                printf(" ");
            }
        printf("\n");
        }

}
}
