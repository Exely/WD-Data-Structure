#include<iostream>
using namespace std;
typedef struct LNode{
	int data;
	int freq;
	struct LNode* prior;
	struct LNode* next;
}LNode, *LinkList;
int Locate(LinkList &L,int x){
	LinkList p=L->next,q;//q保存插入的前结点
	for(;p&&p->data!=x;p=p->next);
	if(p){
		p->freq++;
		for(q=p->prior;q!=L&&q->freq<=p->freq;q=q->prior);
		//删除p
		p->prior->next=p->next;
		if(p->next){
			p->next->prior=p->prior;
		}
		//插入p
		p->next=q->next;
		q->next->prior=p;
		p->prior=q;
		q->next=p;
		return 0;
	}
	return 1;
}
void fun_start(LinkList &L1,LinkList &rear){
	int x;
	cin>>x;
	while(x!=9999){
		Locate(L1,x);
		cin>>x;
	}
}
//带头结点
void build_list(LinkList &L,LinkList &rear){
	LinkList s;
	int x=0;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	rear=L;
	cin>>x;
	//尾插
	while(x!=9999){
		s=(LinkList)malloc(sizeof(LNode));
		s->data=x;
		s->freq=0;
		rear->next=s;
		/////双链表
		s->prior=rear;
		/////
		rear=rear->next;
		cin>>x;
	}
	rear->next=NULL;
	L->prior=NULL;
	//循环双链表
	//rear->next=L;
	//L->prior=rear;
}

void print_list(LinkList &L){
	//打印链表
	//带头结点
	LinkList s=L->next;
	//while(s){
	//双链表
	while(s){
		cout<<s->data<<":"<<s->freq<<" ";
		s=s->next;
	}
	cout<<endl;
	LinkList p=L,tmp=L;
	while(L){
		p=L;
		L=L->next;
		free(p);
	}
}
////////////////////////////////////////////////////
int main(){
	LinkList l1,l2,rear1,rear2;
	build_list(l1,rear1);
	//	build_list(l2);
	fun_start(l1,rear1);
	print_list(l1);
	//	print_list(l2);
	return 0;
}
/////////////////////////////////////////////////
