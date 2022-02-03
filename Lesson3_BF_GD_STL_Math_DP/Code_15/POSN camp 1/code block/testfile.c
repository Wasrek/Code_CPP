#include<stdio.h>
int main()
{
    FILE *r;
    if((r=fopen("D:\\ctest.txt", "r"))==NULL)
    {
        printf("Error! opening file");
    }
    char buffer[255];
    char ch;

    ch=getc(r);
    while (ch!=EOF)
    {
    ch=getc(r);
    printf("%c", ch);
    }
    fclose(r);
}
