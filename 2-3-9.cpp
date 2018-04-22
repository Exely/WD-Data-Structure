#include<iostream>
using namespace std;
typedef struct LNode{
	int data;
	struct LNode* next;
}LNode, *LinkList;
void fun(LinkList &L){
	LinkList p=L->next,pre=L,q,premin;
	int minx=p->data;
	while(L->next){
		pre=L;
		p=L->next;
		premin=pre;
		minx=p->data;
		while(p){
			if(p->data<minx){
				premin=pre;
				minx=p->data;
			}
			pre=p;
			p=p->next;
		}
		q=premin->next;
		premin->next=q->next;
		cout<<minx<<" ";
		free(q);
	}
	cout<<endl;
}
void fun_start(LinkList &L){
	LinkList s=L->next;
	fun(L);
}























int main(){
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
	LinkList tmp,pre,now;
	//原地逆转算法：pre置初值NULL，now为当前节点,为头结点下一节点，迭代。
	//分析单个节点情况，tmp保存当前节点next，当前now的next指向pre,pre迭代为当前节点now
	//now迭代为tmp
	pre=NULL;
	now=L->next;
	while(now){
		tmp=now->next;
		now->next=pre;
		pre=now;
		now=tmp;

	}
	//带头结点
	L->next=pre;
	fun_start(L);
	//打印链表
	//不带头结点
	return 0;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
