/*
    TASK:Limbo2
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
char a[1500][300];
int r,c,cou=0,Min;
void play(int i,int j){
   a[i][j]='.',cou++;
   if(i-1>=0 && a[i-1][j]=='*')play(i-1,j);
   if(j-1>=0 && a[i][j-1]=='*')play(i,j-1);
   if(i+1<r && a[i+1][j]=='*')play(i+1,j);
   if(j+1<c && a[i][j+1]=='*')play(i,j+1);

   if(i-1>=0 && j-1>=0 && a[i-1][j-1]=='*')play(i-1,j-1);
   if(i+1<r  && j+1<c && a[i+1][j+1]=='*')play(i+1,j+1);
   if(i+1<r  && j-1>=0 && a[i+1][j-1]=='*')play(i+1,j-1);
   if(i-1>=0 && j+1<c && a[i-1][j+1]=='*')play(i-1,j+1);


}
int main()
{
    int i,j, Min=10000000;;
    scanf(" %d %d",&c,&r);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf(" %c",&a[i][j]);
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(a[i][j]=='*'){
                    cou=0;
                play(i,j);

                if(cou<Min)
                {
                    Min=cou;
                }
            }
        }
    }
    printf("%d",Min);

    return 0;
}
