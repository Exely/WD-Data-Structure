#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int data;
	struct LNode* next;
}LNode, *LinkList;

int main(){
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
	s=L->next;
	while(s){
		printf("%d ",s->data);
		s=s->next;
	}
	free(s);
	free(L);
	return 0;
}
