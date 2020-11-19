/*
    TASK:Special Number
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
#include<math.h>
    int x[10],t[10],p[10],c[10];
int main()
{
    int P,n,d,w,f;
    for(n=0;n<5;n++)
    {
        scanf(" %d",&x[n]);
        t[n]=x[n];f=0;
        for(w=4;w>=1;w--)//4 3 2 1
        {
             P=pow(10.00,(double)(w-1));printf(" %d-%d",P,w);//1000
             p[w]=t[w]/P;//158/1000
             t[w]=t[w]-(p[w]*P);
             c[w]=pow(p[w],f)+c[w];
             f++;
            // printf("%d ",p[w]);
        }
    }
    for(n=0;n<5;n++){
           // printf("%d ",c[n]);
    if(x[n]==c[n])
    {
        printf("Y");
    }else{printf("N");}
    }

    return 0;
}
