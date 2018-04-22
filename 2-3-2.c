#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int data;
	struct LNode* next;
}LNode, *LinkList;

LinkList fun(LinkList L,int x){
	if(L){
		if(L->data==x){
			LinkList p;
			L->next=fun(L->next, x);
			p=L; //注意内存泄露！！！
			L=L->next;
			free(p);
		}else{
			L->next=fun(L->next,x);
		}
		return L;
	}
	return NULL;
}
int main(){
	////////////////////////////////////////////////////////////
	////////////////////建立链表////////////////////////////////
	LinkList L,s;
	int x=0;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	scanf("%d",&x);
	while(x!=9999){
		s=(LinkList)malloc(sizeof(LNode));
		s->data=x;
		s->next=L->next;
		L->next=s;
		scanf("%d",&x);
	}
	//带头结点：
	s=L->next;
	//不带头结点：
	//L=L->next;
	//s=L;
	////////////////////////////////////////////////////////////

	//函数调用：返回链表
	scanf("%d",&x);
	L->next=fun(L->next,x);
	s=L->next;


	//打印链表：
	while(s){
		printf("%d ",s->data);
		s=s->next;
	}
	free(s);
	free(L);
	return 0;
}
