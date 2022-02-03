/*
    TASK:Ice Bucket Challenge
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
int ans[500],x[500],y[500],w[500];
int main()
{
    int n,q,p=1;
    scanf("%d",&n);
    for(q=0;q<n;q++)
    {
        scanf("%d %d",&x[q],&y[q]);
        if(x[q]<=100)
        {
            printf("0");
        }else if(x[q]>100){
            p=1;
        //w[q]++;x[q]=x[q]-10;
        while(x[q]>0)
        {
            if(x[q]<=p*100)
        {
            printf("%d\n",ans[q]);break;
        }else if(x[q]>p*100){
            p=p-1+y[q];
            x[q]-=10;
            ans[q]+=1;
        }
        }
        }

    }

    return 0;
}
