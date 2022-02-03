/*
    TASK:Over sort
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
   char str[200];
   bool operator<(const A& o)const{
      if(strcmp(str,o.str)<0){return true;}
      return false;
   }
};
int a[100010];
double b[100010];
char c[100010];
A d[100010];
int main()
{
    int type,n,i;
    scanf("%d %d",&type,&n);
    if(type==1){
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        for(i=0;i<n;i++)
            printf("%d ",a[i]);
        printf("\n");
        for(i=n-1;i>=0;i--)
            printf("%d ",a[i]);
        printf("\n");
    }else if(type==2){
        for(i=0;i<n;i++)
            scanf("%lf",&b[i]);
        sort(b,b+n);
        for(i=0;i<n;i++)
            printf("%.0lf ",b[i]);
        printf("\n");
        for(i=n-1;i>=0;i--)
            printf("%.0lf ",b[i]);
        printf("\n");
    }else if(type==3){
        for(i=0;i<n;i++)
            scanf(" %c",&c[i]);
        sort(c,c+n);
        for(i=0;i<n;i++)
            printf("%c ",c[i]);
        printf("\n");
        for(i=n-1;i>=0;i--)
            printf("%c ",c[i]);
        printf("\n");
    }else if(type==4){
        for(i=0;i<n;i++)
            scanf(" %s",d[i].str);
        sort(d,d+n);
        for(i=0;i<n;i++)
            printf("%s ",d[i].str);
        printf("\n");
        for(i=n-1;i>=0;i--)
            printf("%s",d[i].str);
        printf("\n");
    }
return 0;
}
