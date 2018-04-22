#include<iostream>
using namespace std;
typedef struct LNode{
	int data;
	struct LNode* next;
}LNode, *LinkList;

// p为L的尾指针用于尾插法，初始时为L
void fun(LinkList &L,LinkList &L1,LinkList &L2){
	LinkList p=L,p1=L1->next,p2=L2->next;//扫描指针
	LinkList tmp;
	// bug 笔记：这里不能改为 if() if() 的形式，因为if(A) A会被执行
	// 如 if(p1->data) 如果之前p1递增了 p1->next为空了，这里就会访问错误
	// 尽管if条件可能不成立，但if条件却被执行了
	// 需要用 else if 用 else if
	while(p1&&p2){
		if(p1->data<p2->data){
			p1=p1->next;
		}else if(p1->data>p2->data){
			p2=p2->next;
		}else if(p1->data==p2->data){
			p->next=(LinkList)malloc(sizeof(LNode));
			p=p->next;
			p->data=p1->data;
			p1=p1->next;
			p2=p2->next;
		}
	}
	p->next=NULL;
}
void fun_start(LinkList &L,LinkList &L1,LinkList &L2){
	fun(L,L1,L2);
}
void build_list(LinkList &L){
	LinkList s;
	int x=0;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	cin>>x;
	//头插法 懒得改尾插
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
}

void print_list(LinkList &L){
	//打印链表
	//带头结点
	LinkList s=L->next;
	while(s){
		cout<<s->data<<" ";
		s=s->next;
	}
	cout<<endl;
	LinkList p=L;
	while(L){
		p=L;
		L=L->next;
		free(p);
	}
}
////////////////////////////////////////////////////
int main(){
	LinkList l1,l2;
	build_list(l1);
	build_list(l2);
	LinkList L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	fun_start(L,l1,l2);
	print_list(L);
	print_list(l1);
	print_list(l2);
	return 0;
}
/////////////////////////////////////////////////
