/*
    TASK:Roman Conversion
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
int main()
{
    int Q,Q1,n,M,D,hun,thou,ten,unit,C,L,X,V,I,y;
    scanf(" %d",&Q);
    for(Q1=0;Q1<Q;Q1++)
    {
        scanf(" %d",&n);
        thou=n/1000;

        for(y=0;y<thou;y++)
        {
            printf("M");
        }

                hun=(n-(thou*1000))/100;
        ten=(n-(thou*1000)-(hun*100))/10;
        unit=n-(thou*1000)-(hun*100)-(ten*10);
        if(hun==9)
        {
            printf("CM");hun=0;
        }else if(hun==4)
        {
            printf("CD");hun=0;
        }else if(hun>=5)
        {
            printf("D");hun=hun-5;
        }
        if(hun<4){
        for(y=0;y<hun;y++)
        {
            printf("C");
        }
        }

        if(ten==9)
        {
            printf("XC");ten=0;
        }else
        if(ten==4)
        {
            printf("XL");ten=0;
        }else
        if(ten>=5)
        {
            printf("L");ten=ten-5;
        }
        if(ten<4)
        {
        for(y=0;y<ten;y++)
        {
            printf("X");
        }
        }

        if(unit==9)
        {
            printf("IX");unit=0;
        }else if(unit==4)
        {
            printf("IV");unit=0;
        }else if(unit>=5)
        {
            printf("V");unit=unit-5;
        }
        if(unit<4)
        {
        for(y=0;y<unit;y++)
        {
            printf("I");
        }
        }

    }


    return 0;
}
