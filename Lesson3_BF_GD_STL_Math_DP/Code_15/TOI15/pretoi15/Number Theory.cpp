/*
	TASK:Number Theory
	LANG: CPP
	AUTHOR: KersaWC
	SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	int s,e;
};
int a[200010],sub[200010],p[15][200010],bb[15][200010],mark[15][200010];
vector<int> g;
A b[15];
int main(){
	int n,m,i,cou1=0,last=0,fr=0,ba=0,chch=1,s1;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}

	int j=0,l=0;
	for(i=1;i<=m;i++){
		scanf("%d",&sub[i]);
		l++;
		if(sub[i]==1){
			if(i-last>1){
				j++;
				b[j].s=last+1;
				b[j].e=i-1;
			}
			l=0;
			last=i;
			ba++;
		}else chch=0,ba=0;
		if(chch)fr++,last=i;
	}
	if(l){
		j++;
		b[j].s=last+1;
		b[j].e=m;
		ba=0;
	}
	int jj=j;
	if(jj==0){
		jj=1;
		b[1].s=1;
		b[1].e=m;
		fr=0;ba=0;
	}
//
//	for(i=1;i<=jj;i++){
//		printf("%d %d\n",b[i].s,b[i].e);
//	}
//    printf("%d %d\n",fr,ba);
	int r,k;

	//printf("%d\n",jj);

	for(k=1;k<=jj;k++){
	r=0;
//	printf("%d %d\n",b[k].s,b[k].e);
	for(i=b[k].s;i<=b[k].e;i++){
		bb[k][++r]=sub[i];
		//printf("%d ",bb[k][r]);
	}
	//printf("\n");
	}

	for(k=1;k<=jj;k++){
	j=0;
	for(i=2;i<=(b[k].e-b[k].s+1);i++){
		while(j>0 && bb[k][j+1]%bb[k][i])j=p[k][j];
		if(bb[k][i]%bb[k][j+1]==0)j++;
		p[k][i]=j;
	}
	}

//	for(i=1;i<=jj;i++){
//		for(j=1;j<=(b[k].e-b[k].s+1);j++){
//			printf("%d ",p[i][j]);
//		}
//		printf("\n");
//	}
	int cou=0;
	for(k=1;k<=jj;k++){
	for(i=1,j=0;i<=n;i++){
		while(j>0 && a[i]%bb[k][j+1])j=p[k][j];
		if(a[i]%bb[k][j+1]==0)j++;
		if(j==(b[k].e-b[k].s+1)){
			j=p[k][j];
			if(k==1){
			g.push_back(i);
			}
			mark[k][i]=1;
			cou++;
			//printf("%d %d\n",k,i);
		}
	}
	//printf("\n");
	}
	s1=b[1].e-b[1].s;
	cou=0;
	int ch;
//	printf("%d %d\n",fr,ba);
	for(auto x:g){
		ch=1;
		last=x;
		//printf("%d\n",last);
		//printf("---\n");
		if(x+ba>n)continue;
		//printf("-%d\n",last);
		if(last-fr-s1<=0)continue;
		for(i=2;i<=jj;i++){
			if(mark[i][last+(b[i].e-b[i-1].e)]){
			last=last+(b[i].e-b[i-1].e);
			//printf("--%d %d\n",last,ba);
			if(i==jj && ba+last>n){
                ch=2;
                //printf("*2* %d %d\n",last,ba);
			}
			}
			else{
			ch=3;
			}
		}
		//printf("---%d %d %d\n",ch,last,last-fr-s1);
		if(ch==1)cou++;
	}
	printf("%d\n",cou);
	return 0;
}
/*
10 3
1 2 3 4 6 1 1 2 3 4
1 2 3

10 5
3 3 5 3 5 3 7 9 3 5
3 1 1 1 1

10
5
2 3 5 7 9 3 5 3 5 5
1 1 1 5 1
10
2
2 3 5 7 9 3 5 3 5 5
5 1

2 2
2 2
2 1

2 2
2 2
1 2

8 3
2 3 2 2 3 2 3 2
2 3 2

8 5
13 11 13 11 13 17 13 13
11 1 1 13 1

*/
