





#include<bits/stdc++.h>
using namespace std;
struct A{
	int w,v,d,id;
	bool operator<(const A& o)const{
		return w > o.w;
	}
};
struct B{
	int w,v,d,id;
	bool operator<(const B& o)const{
		return d > o.d;
	}
};
priority_queue< A > hat;
priority_queue< B > tim;
int mark[200100];
int main()
{
	int n,m,opr,w,v,d,x,k,ch,i;
	scanf("%d %d",&n,&m);
	for(i=0;i<n+m;i++){
		scanf("%d",&opr);
		if(opr==1){
			scanf("%d",&k);
			if(k==1){
				scanf("%d %d",&w,&v);
				hat.push({w,v,200001,i});
			}
			else if(k==2){
				scanf("%d %d %d",&w,&v,&d);
				hat.push({w,v,d,i});
			}
			else if(k==3){
				scanf("%d %d %d %d",&w,&v,&d,&x);
				hat.push({w,v,d,i});
				tim.push({x,v,d,i});
			}
		}
		else if(opr==2){
			while(!tim.empty() && tim.top().d <= i){
				hat.push({tim.top().w, tim.top().v ,200001,tim.top().id});
				tim.pop();
			}
			ch=1;
			while(!hat.empty()){
				if(hat.top().d <= i){ hat.pop(); continue; }
				if(mark[hat.top().id]){ hat.pop(); continue;}
				printf("%d\n",hat.top().v);
				mark[hat.top().id]=1;
				hat.pop();
				ch=0;
				break;
			}
			if(ch) printf("0\n");	
		}
	}
	return 0;
}
