#include<stdio.h>
int main()
{
    FILE *r;
    r=fopen("filec.txt", "r");
    char buffer[125];
    fgets(buffer ,125,r);
    printf(" %s",buffer);
    fgets(buffer ,125,r);
    printf(" %s",buffer);
    fgets(buffer ,125,r);
    printf(" %s",buffer);
    fclose(r);
}
