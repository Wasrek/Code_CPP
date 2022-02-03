#include<stdio.h>
int main()
{
    struct product{
       char id[5];
       int price;
       int amount;
    }p[3];
    int i,j;
    for(i=0;i<3;i++)
    {
        printf("product ID : ");
        scanf(" %s",p[i].id);
        printf("product price : ");
        scanf(" %d",&p[i].price);
        printf("product amount : ");
        scanf(" %d",&p[i].amount);
        printf("\n");
    }
    int total =0;
    printf(">>>>> Report Output <<<<<\n");
    printf("ID\tprice\tamount\n");
    for(i=0;i<3;i++)
    {
    printf("%s\t%d\t%d\n",p[i].id,p[i].price,p[i].amount);
    total+=p[i].price*p[i].amount;
    }
    printf("Total . %d",total);
}
