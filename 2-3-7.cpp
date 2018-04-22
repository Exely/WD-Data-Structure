#include<iostream>
using namespace std;
typedef struct LNode{
	int data;
	struct LNode* next;
}LNode, *LinkList;
void fun(LinkList &L,int x,int y){
	LinkList p=L->next,pre=L,q;
	while(p){
		if(p->data<=y && p->data>=x){
			q=p;
			p=p->next;
			pre->next=p;
			free(q);
		}else{
			pre=p;
			p=p->next;
		}
	}
}
void fun_start(LinkList &L){
	LinkList s=L->next;
	int count=0;
	while(s){
		count++;
		s=s->next;
	}
	int x=0,y=0;
	cin>>x>>y;
	fun(L->next,min(x,y),max(x,y));
}










































////////////////////main 
//////////////////////
////////////////////
int main(){
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
	s=L->next;
	while(s){
		cout<<s->data<<" ";
		s=s->next;
	}
	cout<<endl;
	free(s);
	LinkList p=L;
	while(L){
		p=L;
		L=L->next;
		free(p);
	}

	return 0;
}
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
