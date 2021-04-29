#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a); i<=(b); ++i)
#define ROF(i,a,b) for(int i=(a); i>=(b); --i)
#define pb push_back
#define eb emplace_back
#define SZ(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define make_unique(a) sort(all((a))), (a).erase(unique(all((a))),(a).end())
#define x first
#define y second
#define MP make_pair
#define MT make_tuple
#define debug(x) cout << #x << " = " << x << endl
#define debug2(x,y) FOR(i,1,y) cout << "##"; cout << #x << " = " << x << endl

using namespace std;

typedef long long i64;
typedef tuple<int,int,int> iii;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;

int readInt(){ int a; scanf("%d",&a); return a; }
i64 readLong(){ i64 a; scanf("%lld",&a); return a;}
void readString(char *s){ scanf(" %s",s); }

struct node {
    node *l, *r;   
    int prior, key, sz;
    node(int key):key(key),l(NULL),r(NULL){
        prior = rand()*rand();
		sz = 1;
    }
};

typedef node* pnode;

pnode root = NULL;

int sz(pnode t){
	return t ? t->sz : 0;
}

void upd(pnode t){
	if(t) t->sz = 1+sz(t->l)+sz(t->r);
}

void split(pnode t, pnode &l, pnode &r, int key, int add=0){
	if(!t){ l = r = NULL; return ; }
	int idx = add+1+sz(t->l);
	if(idx <= key) split(t->r,t->r,r,key,idx), l=t;
	else split(t->l,l,t->l,key,add), r=t;
	upd(t);
}

void merge(pnode &t, pnode l, pnode r){
	if(!l||!r){ t = (l)?l:r; return ; }
	if(l->prior > r->prior) t=l, merge(l->r,l->r,r);
	else t=r, merge(r->l,l,r->l);
	upd(t);
}

// method for print out the in-order traversal
void dfs(pnode t){
	if(!t) return ;
	dfs(t->l); printf("%d ",t->key); dfs(t->r);
}

// method for finding i-th idx
pnode find(pnode t, int i, int add=0){
	if(!t) return NULL; // cant find
	int cur = add+1+sz(t->l);
	if(cur == i) return t; // found
	if(i < cur) return find(t->l, i, add);
	else return find(t->r, i, cur);
}

int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	int i, j;
	for(i=1;i<=n;++i){
		int val;
		scanf("%d",&val);
		pnode new_node = new node(val);
		merge(root,root, new_node);
	}
	// dfs(root);
	while(m--){
		int cmd, A, L, B;
		scanf("%d %d",&cmd,&A);
		if(cmd == 1){
			scanf("%d %d",&L,&B);
			if(B >= A+L) B-=L;
			--B;
			pnode p1, p2, p3;
			split(root,p1,p3,A+L-1);
			split(p1,p1,p2,A-1);
			merge(root,p1,p3);
			split(root,p1,p3,B);
			merge(root,p1,p2);
			merge(root,root,p3);
			/*
			dfs(root);
			puts("");
			*/
		}else{
			pnode ans = find(root, A);
			printf("%d\n",ans->key);
		}
	}
    return 0;
}
// 1
