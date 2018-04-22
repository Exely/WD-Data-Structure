#include<iostream>
using namespace std;
typedef struct LNode{
	int data;
	struct LNode* next;
}LNode, *LinkList;
void fun(LinkList &L,LinkList &La,LinkList &Lb){
	int count=0;
	LinkList lasta=La,lastb=Lb;
	while(L->next){
		count++;
		if((count%2)==1){
			lasta->next=L->next;
			lasta=lasta->next;
			L->next=L->next->next;
		}else{
			lastb->next=L->next;
			lastb=lastb->next;
			L->next=L->next->next;
		}
	}
	lasta->next=NULL;
	lastb->next=NULL;
}
void fun_start(LinkList &L){
	LinkList s=L->next;
	LinkList La=(LinkList)malloc(sizeof(LNode));
	LinkList Lb=(LinkList)malloc(sizeof(LNode));
	LinkList q;
	fun(L,La,Lb);
	while(La->next){
		cout<<La->next->data<<" ";
		q=La->next;
		La->next=q->next;
		free(q);
	}
	cout<<endl;
	while(Lb->next){
		cout<<Lb->next->data<<" ";
		q=Lb->next;
		Lb->next=q->next;
		free(q);
	}
	cout<<endl;
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
