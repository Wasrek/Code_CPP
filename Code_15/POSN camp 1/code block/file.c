#include<stdio.h>
int main()
{
    char name[24];
    char gender;
    char GD[7];
    int age;

    printf("Input your name? ");
    gets(name);
    printf("Input your gender M or F? ");
    scanf(" %c",&gender);
    printf("Input your age? ");
    scanf("%d",&age);

    if(gender=='M' || gender=='m')
    {
        strcpy(GD,"boy");
    }else{strcpy(GD,"girl");}

    FILE *f;
    f = fopen("filec.txt", "w");
    fprintf(f, "Hello %s.\n", name);
    fprintf(f, "you are a %s.\n",GD);
    fprintf(f,"%d years old",age);

    fclose(f);

}
