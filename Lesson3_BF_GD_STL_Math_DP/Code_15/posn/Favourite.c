#include<stdio.h>
int main()
{
   int N,a,x,y,z,r;
   scanf(" %d",&N);
   int f[N],m[N];
   for(a=0;a<N;a++)
   {
      scanf(" %d",&f[a]);
   }
   for(a=0;a<N;a++)
   {
      scanf(" %d",&m[a]);
   }
   for(z=1;z<=N;z++)
    {x=z;
    for(a=0;a<z;a++)
    {
        for(y=0;y<z;y++)
        {
            if(f[a]==m[y]){if(x!=0){x=x-1;}}
            if(x==0){{printf("%d",z);return 0;}}
        }
    }
    }
}
