/*
    TASK:Permutation
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
#include<stdlib.h>
int a[15],b[15],n,r,k,cou=0,m;//array a is for marking and b is for answer
void permu(int state)// state บอกจะใส่ลงช่องไหน
{
    int i;
    if(state==r)//already get the all answer(r)
    {
        cou++;//1//count for the k is it already the order that we want to find
        if(cou==k)
        {
            for(i=0; i<r; i++)
            {
                printf("%d ",b[i]);
            }
            exit(0);
        }
        return ;//not the right order so return to the func that calL it
    }
    for(i=1; i<=n; i++)//the number if used or not ++ it
    {
        if(a[i]!=1)//not yet
        {
            //for(m=1;m<=n;m++){printf(" .%d %d. ",a[i],i);}
            a[i]=1;//check that it is already used for next time
            b[state]=i;//set the answer[number] equal to the number that not yet used
            //printf(" -%d %d- ",state,b[state]);
            //printf("\n");
            permu(state+1);//check the next state to find the next answer
            a[i]=0;//when it return back that it not yet the order we want to find reset the number already used-->not yet used
        }//when the order is not correct it will find the next number that not yet used in for loop and set it as an answer
    }
    /* state will return back to the before one if i is max at n */
}
int main()
{
    scanf("%d %d %d",&n,&r,&k);//4 3 7
    permu(0);

    return 0;
}
//หาเลขตัวแรกในarray aที่ยังไม่ถูกใช้ใช้ละmarkละเก็บคำตอบ
