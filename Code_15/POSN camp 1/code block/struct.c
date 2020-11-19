#include<stdio.h>

struct person{
    char name[25];
    int age ;
    char tel[12];
};

int main(){
    struct person student;
    printf("name??=");
    gets(student.name);//gets ใช้แทน scanf พวก char string
    printf("\nage??=");
    scanf("%d",&student.age);
    printf("\ntel??=");
    scanf("%s",&student.tel);

    printf("\nname= %s \nage= %d \ntel= %s", student.name, student.age, student.tel);
}
