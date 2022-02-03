/*
    TASK:Prison_Leia
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
int main()
{
    int A,B,C,a,b,c,d;
    scanf(" %d %d %d",&A,&B,&C);
    //A=ac B=ad+bc C=bd
    for(a=1;a<=100;a++)
    {
        for(c=1;c<=100;c++)
        {
            for(b=-100;b<=100;b++)
            {
                for(d=-100;d<=100;d++)
                {
                    if((a*c)==A && (a*d)+(b*c)==B && (b*d)==C)
                    {
                        printf("%d %d %d %d",a,b,c,d);return 0;
                    }
                }
            }
        }
    }
    printf("No Solution");


    return 0;
}
