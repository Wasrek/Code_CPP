/*
    TASK:Brick
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
char a[100][100];
int main()
{
    int n,m,i,j,k;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)

        for(j=0;j<m;j++)

            scanf(" %c",&a[i][j]);


    for(i=0;i<m;i++){

        scanf("%d",&k);
        for(j=0;j<n && a[j][i]=='.';j++);
            for(j--;j>=0 && k>0;j--,k--)

                a[j][i]='#';
    }


    for(i=0;i<n;i++){
        for(j=0;j<m;j++)

            printf("%c",a[i][j]);
        printf("\n");
    }
    return 0;
}

