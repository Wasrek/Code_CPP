#include<stdio.h>
#include<stdlib.h>


char *genpwd(char *pwd, int len) {
  int i = 0;
  for (i=0; i<len; ++i ){
     pwd[i] =(char)((rand() % 10 )+ '0');
 }
 pwd[i] = '\0';
 return pwd;

}

int main (){
    srand(time(NULL));
char pwd[1] = "";
char a[1],b[1];
strcpy(b,genpwd(pwd,1));
scanf("%s",a);
if(a[0]==b[0])
{
    printf("yes\n");
}
else{
    printf("no\n");
}
printf("%c",b[0]);

getch();return 0;
}
