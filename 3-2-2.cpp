#include<iostream>
#include"3-1-SqStack.cpp"
#define MAXSIZE 10
//注意MAXSIZE与3-1冲突
using namespace std;
#define ELEMTYPE int
typedef struct{
	ELEMTYPE data[MAXSIZE];
	int front;
	int rear;
	int tag;
}Queue;
void InitQue(Queue &q){
	q.front=0;
	q.rear=0;
	q.tag=0;
}
bool EnQueue(Queue &q,ELEMTYPE x){
	if(q.front==q.rear&&q.tag==1){
		cout<<"error:enq"<<endl;
		return false;}
	else{
		q.data[q.rear]=x;
		q.rear=(q.rear+1)%MAXSIZE;//rear为第一个可用结点
		if(q.rear==q.front){
			q.tag=1;
		}
		return true;
	}
}
bool DeQueue(Queue &q,ELEMTYPE &x){
	if(q.front==q.rear&&q.tag==0)return false;
	else{
		x=q.data[q.front];//q为队头有值结点
		q.front=(q.front+1)%MAXSIZE;
		if(q.front==q.rear){
			q.tag=0;
		}
		return true;
	}
}
void fun(Queue &q,SqStack &s){
	int x;
	while(DeQueue(q,x)){
		push(s,x);
	}
	while(pop(s,x)){
		EnQueue(q,x);
	}
}
int main(){
	Queue q;
	SqStack s;
	InitStack(s);
	InitQue(q);
	int x;
	cin>>x;
	while(x!=9999){
		EnQueue(q,x);
		cin>>x;
	}
	fun(q,s);
	while(DeQueue(q,x)){
		cout<<x<<" ";
	}
	cout<<endl;
	return 0;
}
