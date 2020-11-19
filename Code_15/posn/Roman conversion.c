#include<stdio.h>
int main()
{
   int Q,a,b,d;
   scanf(" %d",&Q);
   int m[Q],I[Q],X[Q],C[Q],M[Q];
   for(a=0;a<Q;a++)
   {
       scanf(" %d",&m[a]);
       I[a]=(m[a]%10);
       X[a]=(((m[a]%100)-I[a])/10);
       C[a]=(((m[a]%1000)-(I[a]+X[a]))/100);
       M[a]=(m[a]/1000);
   }
   for(a=0;a<Q;a++)
   {
       for(b=0;b<M[a];b++)
       {
           printf("M");
       }

       if(C[a]!=9)
       {
       d=C[a]/5;
       if(d==1)
       {
        printf("D");
        C[a]=C[a]-5;
       }
       if(C[a]!=4)
       {
           for(b=0;b<C[a];b++)
           {
               printf("C");
           }
       }else{printf("CD");}
       }else(printf("CM"));

       if(X[a]!=9)
       {
       d=X[a]/5;
       if(d==1)
       {
        printf("L");
        X[a]=X[a]-5;
       }
       if(X[a]!=4)
       {
           for(b=0;b<X[a];b++)
           {
               printf("X");
           }
       }else{printf("XL");}
       }else(printf("XC"));

       if(I[a]!=9)
       {
       d=I[a]/5;
       if(d==1)
       {
        printf("V");
        I[a]=I[a]-5;
       }
       if(I[a]!=4)
       {
           for(b=0;b<I[a];b++)
           {
               printf("I");
           }
       }else{printf("IV");}
       }else(printf("IX"));
       printf("\n");
   }
}
