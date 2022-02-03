#include<stdio.h>
char l[1200][150];
int cou,w,h;
void play(int x,int y)
{
    l[x][y]='.',cou++;
    if(x-1>=0 && l[x-1][y]=='*'){play(x-1,y);}
    if(x+1<h && l[x+1][y]=='*'){play(x+1,y);}
    if(y-1>=0 && l[x][y-1]=='*'){play(x,y-1);}
    if(y+1<w && l[x][y+1]=='*'){play(x,y+1);}
}
int main()
{
    int i,j,Max=0;
    scanf("%d %d",&w,&h);
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            scanf(" %c",&l[i][j]);
        }
    }
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            if(l[i][j]=='*')
            {
                cou=0;
                play(i,j);
                if(cou>Max){
                    Max=cou;
                }
            }
        }
    }
    printf("%d",Max);
    return 0;
}
