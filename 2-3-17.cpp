#include<iostream>
using namespace std;
typedef struct LNode{
	int data;
	struct LNode* prior;
	struct LNode* next;
}LNode, *LinkList;
int fun(LinkList L,LinkList rear){
	LinkList p=L->next,q=L->prior;
	rear=q;
	//bug 笔记： 此处应用与 如果是或的话死循环！
	//因为：或运算的条件恒成立 跳出循环条件是或的
	//因为这是带头结点的双链表（懒得改）仅用rear!=p就成立
	//（会循环一轮）
	while(rear!=p&&rear->prior!=p){
		if(rear->data==p->data){
			p=p->next;
			rear=rear->prior;
		}else{
			return 0;
		}
	}
	if((rear->prior==p)&&(rear->data==p->data))return 1;
	if(rear==p)return 1;
	return 0;
}
void fun_start(LinkList &L1,LinkList &rear){
	cout<<(fun(L1,rear)?"true":"false")<<endl;
}
//带头结点
void build_list(LinkList &L,LinkList &rear){
	LinkList s;
	int x=0;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	rear=L;
	cin>>x;
	//头插法 懒得改尾插
	while(x!=9999){
		s=(LinkList)malloc(sizeof(LNode));
		s->data=x;
		rear->next=s;
		/////双链表
		s->prior=rear;
		/////
		rear=rear->next;
		cin>>x;
	}
	//循环双链表
	rear->next=L;
	L->prior=rear;
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
