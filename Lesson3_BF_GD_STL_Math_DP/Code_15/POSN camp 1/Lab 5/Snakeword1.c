/*
    TASK:Snake word
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char a[50][50],b[150],mark[30][30];
int r,c,len,ch,di[4]= {1,-1,0,0},dj[4]= {0,0,1,-1};
int ans[150][2];
void play(int i,int j,int state)
{
    ans[state][0]=i+1, ans[state][1]=j+1;
    int k,ii,jj;
    if(state==len-1)
    {
        for(k=0; k<len; k++)
            printf("%d %d\n",ans[k][0],ans[k][1]);
        ch=0;
        return ;
    }
    for(k=0; k<4; k++)
    {
        ii=i+di[k],jj=j+dj[k];
        if(ii<0 || jj<0 || ii>=r || jj>=c)
            continue;
        if(mark[ii][jj])
            continue;
        if(b[state+1]!=a[ii][jj])
            continue;
        mark[ii][jj] = 1;
        play(ii,jj,state+1);
        mark[ii][jj] = 0;
    }


}

int main()
{
    int i,j,q;
    scanf("%d %d",&r,&c);
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            scanf(" %c",&a[i][j]);
            a[i][j] = toupper(a[i][j]);
        }
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf(" %s",b);
        len=strlen(b);
        for(i=0; i<len; i++)
            b[i] = toupper(b[i]);
        ch=1;
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if(a[i][j]==b[0])
                {
                    mark[i][j]=1;
                    play(i,j,0);
                    mark[i][j]=0;
                }
            }
        }

        if(ch)
            printf("No Matching Word\n");
    }

    return 0;
}
