/*
    TASK:Space station
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[20000][20],b[20],n,r=1,cou=0,m,d,k[20],h,c,p[20],o,ch;
void permu(int state)
{
    int i,j,l;
    if(state==d)
    {
        for(i=0; i<d; i++)
            {
                if(b[i]==1){k[i]=0;}
                if(b[i]==0){k[i]=1;}
            }
        for(i=d-1; i>=0; i--)
        {
            h=b[i];

            for(j=0; j<d; j++)
            {
                p[j]=b[j];
            }
            b[i]=h;
 /*           for(o=0;o<c;o++){
                ch=0;
            for(n=0;n<d;n++)
            {

                if(p[n]!=a[o][n]){ch++;}
            }
            if(ch==0){r=1;}//same
            }*/
         //   if(k[i]<=p[i]){
            for(l=0; l<d; l++)
            {
                printf("%d",b[l]);
                a[c][l]=b[l];
            }
            c++;
            printf(" ");
            h=b[i];
            b[i]=k[i];
            for(j=0; j<d; j++)
            {
                printf("%d",b[j]);
            }
            b[i]=h;
            printf("\n");
        }
        return ;
    }
    for(i=0; i<2; i++)
    {
            b[state]=i;
            permu(state+1);
}
}
//}
int main()
{
    int u;
    for(c=0;c<20000;c++){
    for(u=0;u<15;u++)
        a[c][u]=-1;
    }
    c=0;
    scanf("%d",&d);
    permu(0);

    return 0;
}


