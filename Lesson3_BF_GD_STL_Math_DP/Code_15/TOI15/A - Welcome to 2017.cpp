/*
	TASK:A - Welcome to 2017
	LANG: CPP
	AUTHOR: KersaWC
	SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	int w,p;
	bool operator<(const A&o)const{
		if(w!=o.w)
		return w>o.w;
		return p>o.p;
	}
};
int a[2100],cnt[4100];
priority_queue< A > h;
int main(){
	int n,i,x,y,p1,p2,m;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<=2017)m=-1;
		else m=1;
		h.push({abs(2017-a[i]),m});
		cnt[a[i]]++;
	}
	while(!h.empty()){
	    while(!h.empty() && cnt[2017+(h.top().w*h.top().p)]>2)h.pop();
        if(!h.empty()){
		x=h.top().w;
		p1=h.top().p;
		h.pop();
        }else{
            printf("-1\n");
            return 0;
        }
		if(cnt[2017+(p1*x)]>2)continue;
		while(!h.empty() && cnt[2017+(h.top().w*h.top().p)]>2)h.pop();
		if(!h.empty()){
		y=h.top().w;
		p2=h.top().p;
		h.pop();
		if(x!=y){
			printf("%d\n",(2017+(x*p1)));
			return 0;
		}else{
			if(p1!=p2){
			p1=min(p1,p2);
			printf("%d\n",(2017+(x*p1)));
			return 0;
			}else continue;
		}
		continue;
		}else{
			printf("%d\n",(2017+(x*p1)));
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
