#include<iostream>
using namespace std;
typedef struct LNode{
	int data;
//	struct LNode* prior;
	struct LNode* next;
}LNode, *LinkList;
void fun(LinkList &L1,LinkList &L2){
	LinkList p=L1->next;
	while(p->next!=L2){
		if(p->next==L1){
			p->next=L2->next;
		}
			p=p->next;
	}
	p->next=L1;
}
void fun_start(LinkList &L1,LinkList &L2){
	fun(L1,L2);
}
//带头结点
void build_list(LinkList &L,LinkList &rear){
	LinkList s;
	int x=0;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	rear=L;
	cin>>x;
	while(x!=9999){
		s=(LinkList)malloc(sizeof(LNode));
		s->data=x;
		rear->next=s;
		/////双链表
//		s->prior=rear;
		/////
		rear=s;
		cin>>x;
	}
	//循环单链表
	rear->next=L;
//	L->prior=rear;
}

void print_list(LinkList &L){
	//打印链表
	//带头结点
	LinkList s=L->next;
	//while(s){
	//双链表
	while(s!=L){
		cout<<s->data<<" ";
		s=s->next;
	}
	cout<<endl;
	LinkList p=L,tmp=L;
	while(L!=tmp){
		p=L;
		L=L->next;
		free(p);
	}
}
void test(LinkList L,LinkList rear){
	//测试前后
	LinkList p=L->next;
	cout<<"test1:front"<<endl;
	while(p!=L){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl<<"test2:rear"<<endl;
//	while(rear!=L){
//		cout<<rear->data<<" ";
	//	rear=rear->prior;
//	}
	cout<<endl;	
}
////////////////////////////////////////////////////
int main(){
	LinkList l1,l2,rear1,rear2;
	build_list(l1,rear1);
	build_list(l2,rear2);
	fun_start(l1,l2);
//	test(l1,rear1);
	print_list(l1);
//	print_list(l2);
	return 0;
}
/////////////////////////////////////////////////
