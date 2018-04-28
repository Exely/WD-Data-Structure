#include<iostream>
#include"3-1-SqStack.cpp"
using namespace std;
typedef struct LNode{
	int data;
	struct LNode* next;
}LNode, *LinkList;
//bug 笔记:因为在SqStack31中没有用引用型参数
//导致top没有值，出现莫名其妙的访问错误
//所以，访问错误也可能是由于未赋值的变量引起的
void fun(LinkList L,SqStack &s){
	LinkList p=L->next;
	int x=0;
	for(;p!=NULL;p=p->next){
		if(push(s,p->data)){
			//bug笔记：由于top无值，报栈满
		}else{
			cout<<"error:push"<<endl;
			return;
		}
	}
	for(p=L->next;p;p=p->next){
		if(pop(s,x)){
			if(x!=p->data){
				cout<<"false"<<endl;
				return;
			}
		}else{
		cout<<"error:pop"<<endl;
		}
	}
	cout<<"true"<<endl;
	return;

}
void fun_start(LinkList L1,LinkList &rear,SqStack &s){
	fun(L1,s);
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
		rear=rear->next;
		cin>>x;
	}
	rear->next=NULL;
}

void print_list(LinkList &L){
	//打印链表
	//带头结点
	LinkList s=L->next;
	//while(s){
	//双链表
	while(s){
		cout<<s->data<<" ";
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
	SqStack s;
	InitStack(s);
	build_list(l1,rear1);
	//	build_list(l2);
	fun_start(l1,rear1,s);
	print_list(l1);
	//	print_list(l2);
	return 0;
}
/////////////////////////////////////////////////
