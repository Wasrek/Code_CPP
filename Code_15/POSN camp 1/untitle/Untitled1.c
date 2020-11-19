#include<stdio.h>
#include<string.h>
void main()
{
   char sur[25];
   int x,y=0,z;
   scanf(" %s",sur);
    z=strlen(sur);
   for(x=0;x<z;x++){
        if(sur[x]>90){y=1;break;}
    }
    if(y==0){printf("%s",sur);}else
    {printf("There are a lower case character");}
}
