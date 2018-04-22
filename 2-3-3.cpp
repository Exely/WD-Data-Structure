#include<iostream>
using namespace std;
typedef struct LNode{
	int data;
	struct LNode* next;
}LNode, *LinkList;

void fun(LinkList L){
	if(L==NULL){
		return;
	}else{
		fun(L->next);
		cout<<L->data<<" ";
	}
}
int main(){
	////////////////////////////////////////////////////////////
	////////////////////建立链表////////////////////////////////
	LinkList L,s;
	int x=0;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	cin>>x;
	while(x!=9999){
		s=(LinkList)malloc(sizeof(LNode));
		s->data=x;
		s->next=L->next;
		L->next=s;
		cin>>x;
	}
	//带头结点：
	s=L->next;
	//不带头结点：
	//L=L->next;
	//s=L;
	////////////////////////////////////////////////////////////

	//函数调用：返回链表
	//cin>>x;
	fun(L->next);
	s=L->next;


	//打印链表：
	//while(s){
	//	cout<<s->data<<" ";
	//	s=s->next;
	//}
	cout<<endl;
	free(s);
	LinkList q;
	while(L){
		q=L;
		L=L->next;
		free(q);
	}
	return 0;
}
