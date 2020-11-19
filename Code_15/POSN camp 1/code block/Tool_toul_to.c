#include<stdio.h>
int l[120][120],k[120];
int main()
{
    int r,c,n,m,x,y,i,j;
    scanf(" %d %d",&n,&m);
    for(r=0;r<n;r++){
            for(c=0;c<m;c++){
                scanf(" %d",&l[r][c]);
            }
    }
    scanf("%d",&x);
    while(x--)
    {
        scanf("%d %d",&i,&j);
        if(i>n || j>m){
            printf("-1\n");
            return 0;
        }
        i--,j--;
        int h=0;
        for(r=0;r<n;r++){
            if(l[r][j]>h){
                h=l[r][j];
            }
        }
        for(c=0;c<m;c++){
            if(l[i][c]>h){
                h=l[i][c];
            }
        }
        printf("%d\n",h);
    }
    return 0;

}
