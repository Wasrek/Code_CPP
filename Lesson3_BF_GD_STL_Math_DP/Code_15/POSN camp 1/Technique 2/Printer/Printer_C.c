/*
TASK: Printer
LANG: C
AUTHOR: KersW
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct list{
	char val[50];
	struct list *l;
	struct list *r;
};
typedef struct list list;
list *head = NULL,*cur;
list* CreateNode(char* x){
	list *node;
	node = (list*)malloc(sizeof(list));
	strcpy(node->val,x);
	node->l = NULL;
	node->r = NULL;
	return node;
}
void Insert(char* x){
	list* node = CreateNode(x);
	node->r = cur->r;
	node->l = cur;
	if(cur->r!=NULL)
		cur->r->l=node;
	cur->r=node;
	cur = cur->r;
}
void Back(){
	list *p = cur->l;
	list *node=cur;
	if(cur->l!=NULL){
		if(cur->r==NULL)
			p->r=NULL;
		else{
			p->r = p->r->r;
			p->r->l = p;
		}
		cur = p;
		free(node);
	}
}
void Del(){
	list *node;
	if(cur->r!=NULL){
		node = cur->r;
		cur->r = node->r;
		if(cur->r!=NULL)
			cur->r->l = cur;
		free(node);
	}
}
void Left(){
	if(cur->l!=NULL)
		cur = cur->l;
}
void Right(){
	if(cur->r!=NULL)
		cur = cur->r;
}
void PrintList(){
	cur = head;
	while(cur->r!=NULL)
	{
		cur = cur->r;
		printf("%s ",cur->val);

	}
}

int main(){
	int n,i;
	char s[50],*word;
	head = CreateNode("xxx");
	cur = head;
	scanf("%d",&n);
	for(i=0;i<=n;i++){
		gets(s);
		if(s[0]=='i'){
			word = &s[2];
			Insert(word);
		}
		else if(s[0]=='l')
			Left();
		else if(s[0]=='r')
			Right();
		else if(s[0]=='b')
			Back();
		else if(s[0]=='d')
			Del();
	}
	PrintList();
	return 0;
}
