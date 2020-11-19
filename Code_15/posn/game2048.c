#include<stdio.h>
int main()
{
   int N,x,y;
   char w[6];
   scanf(" %d",&N);
   int s[N][N];
   scanf(" %s",&w);
      for(x=0;x<N;x++){
      for(y=0;y<N;y++){
        scanf(" %d",&s[x][y]);
      }
   }
   int m=(N-1);

   if(w[0]=='r')
    {
    int a,e;
    for(y=0;y<N;y++){
for(x=m;x>0;x--){
  if(s[y][x]==0)
  {e=0;
   for(a=x;a>=0;a--){
    if(s[y][a]!=0 && e==0)
    {s[y][x]=s[y][a];
     s[y][a]=0;e++;
   }
   }
  }
}
}

    for(y=0;y<N;y++){
      for(x=0;x<N;x++){
      printf("%d ",s[y][x]);
      }printf("\n");
   }

for(y=0;y<N;y++){
for(x=m;x>0;x--){
if(s[y][x]==s[y][x-1] && s[y][x]!=2048)
{
s[y][x]=s[y][x]+s[y][x-1];
s[y][x-1]=0;
}
}
}

for(y=0;y<N;y++){
for(x=m;x>0;x--){
  if(s[y][x]==0)
  {e=0;
   for(a=x;a>=0;a--){
    if(s[y][a]!=0 && e==0)
    {s[y][x]=s[y][a];
     s[y][a]=0;e++;
   }
   }
  }
}
}
   }


if(w[0]=='l')
    {
    int a,e;
    for(y=0;y<N;y++){
for(x=0;x<N;x++){
  if(s[y][x]==0)
  {e=0;
   for(a=x;a<N;a++){
    if(s[y][a]!=0 && e==0)
    {s[y][x]=s[y][a];
     s[y][a]=0;e++;
   }
   }
  }
}
}

for(y=0;y<N;y++){
for(x=0;x<m;x++){
if(s[y][x]==s[y][x+1] && s[y][x]!=2048)
{
s[y][x]=s[y][x]+s[y][x+1];
s[y][x+1]=0;
}
}
}

for(y=0;y<N;y++){
for(x=0;x<N;x++){
  if(s[y][x]==0)
  {e=0;
   for(a=x;a<N;a++){
    if(s[y][a]!=0 && e==0)
    {s[y][x]=s[y][a];
     s[y][a]=0;e++;
   }
   }
  }
}
}
   }



   if(w[0]=='d')
    {
    int a,e;
    for(y=0;y<N;y++){
for(x=m;x>=0;x--){
  if(s[x][y]==0)
  {e=0;
   for(a=x;a>=0;a--){
    if(s[a][y]!=0 && e==0)
    {s[x][y]=s[a][y];
     s[a][y]=0;e++;
   }
   }
  }
}
}

for(y=0;y<N;y++){
for(x=m;x>=0;x--){
if(s[x][y]==s[x-1][y] && s[x][y]!=2048)
{
s[x][y]=s[x][y]+s[x-1][y];
s[x-1][y]=0;
}
}
}

for(y=0;y<N;y++){
for(x=m;x>=0;x--){
  if(s[x][y]==0)
  {e=0;
   for(a=x;a>=0;a--){
    if(s[a][y]!=0 && e==0)
    {s[x][y]=s[a][y];
     s[a][y]=0;e++;
   }
   }
  }
}
}
   }


if(w[0]=='u')
    {
    int a,e;
    for(y=0;y<N;y++){
for(x=0;x<N;x++){
  if(s[x][y]==0)
  {e=0;
   for(a=x;a<N;a++){
    if(s[a][y]!=0 && e==0)
    {s[x][y]=s[a][y];
     s[a][y]=0;e++;
   }
   }
  }
}
}

for(y=0;y<N;y++){
for(x=0;x<N;x++){
if(s[x][y]==s[x+1][y] && s[x][y]!=2048)
{
s[x][y]=s[x][y]+s[x+1][y];
s[x+1][y]=0;
}
}
}

 for(y=0;y<N;y++){
for(x=0;x<N;x++){
  if(s[x][y]==0)
  {e=0;
   for(a=x;a<N;a++){
    if(s[a][y]!=0 && e==0)
    {s[x][y]=s[a][y];
     s[a][y]=0;e++;
   }
   }
  }
}
}
   }

      for(y=0;y<N;y++){
      for(x=0;x<N;x++){
      printf("%d ",s[y][x]);
      }printf("\n");
   }
}
