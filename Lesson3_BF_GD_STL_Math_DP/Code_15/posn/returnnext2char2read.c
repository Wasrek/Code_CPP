#include<stdio.h>
#include<math.h>
int main()
{
    char n;
    scanf("%c",&n);
    if(n>=97 && n<=122)
    {
        printf("%c\n",(((n-97)+2)%26)+97);
    }
    else if(n>=65 && n<=90)
    {
        printf("%c\n",(((n-65)+2)%26)+65);
    }
    return 0;
}
