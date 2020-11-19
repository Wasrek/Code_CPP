#include<stdio.h>
int main()
{
    FILE *r;
    if((r=fopen("C:\\Arduino17\\revisions.txt", "r"))==NULL)
    {
        printf("Error! opening file");
    }
    char buffer[255];
    char ch;
    //ch=fgets(buffer,255,r);

    ch=getc(r);
    while (ch!=EOF)
    {
    //fgets(buffer,225,r);
    ch=getc(r);
    printf("%c", ch);
    }
    fclose(r);
}
