/*
    TASK:Awit Cat
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
#include<string.h>
char a[10000],*ptr;
int main()
{
    int q,len,i,ch,ch2;
    scanf(" %d\n",&q);
    while(q--)
    {
        gets(a);
        len=strlen(a);
        if(a[len-1]=='\r') a[len-1]='\0';
        len =strlen(a);
        ptr = strtok(a," ");
        ch2=1;
        while(ptr!=NULL)
        {
            len = strlen(ptr);
            if(len%4==0)
            {
                for(i=0,ch=0;i<len;i+=4){
                    if(strncmp(&ptr[i],"meow",4))
                    {
                        ch=1;
                    }
                }
                if(!ch){
                    printf("YES\n");ch2=0;break;
                }
            }
            ptr = strtok(NULL," ");
        }
        if(ch2){printf("NO\n");}

    }

    return 0;
}
