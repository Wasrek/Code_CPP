#include<stdio.h>
#include<string.h>
#define hashsize 500009
char hash[50][hashsize][60];
char str[10005];
char ans[60];
int main()
{
    long long n,i,len,coun,q,j,k,temp;
    scanf("%lld",&n);
    while(n--)
    {
        scanf(" %s",str);
        len=strlen(str);
        coun=0;
        for(i=0;i<len;i++)
        {
            coun*=29;
            coun+=str[i]-'a';
            coun%=hashsize;
        }
        i=1;
        while(hash[len-1][(coun+i)%hashsize][0]!=0)
            i<<=1;
        strcpy(hash[len-1][(coun+i)%hashsize],str);
    }
    scanf("%lld",&q);
    while(q--)
    {
        coun=0;
        scanf(" %s",str);
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            temp=0;
            for(j=0;j<50&&i+j<len;j++)
            {
                temp*=29;
                temp+=str[i+j]-'a';
                temp%=hashsize;
                k=1;
                while(hash[j][(temp+k)%hashsize][0]!=0&&strncmp(hash[j][(temp+k)%hashsize],&str[i],j+1))
                    k<<=1;
                if(strncmp(hash[j][(temp+k)%hashsize],&str[i],j+1)==0)
                {
                    coun++;
                    if(coun==1)
                        strcpy(ans,hash[j][(temp+k)%hashsize]);
                }
            }
        }
        if(coun==0)
            printf("NO\n");
        else if(coun==1)
            printf("%s\n",ans);
        else
            printf("AMBIGUOUS\n");
    }
    return 0;
}
