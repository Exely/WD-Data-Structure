#include<iostream>
#define MAXSIZE 50
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
bool QueueEmpty(Queue q){
	if(q.front==q.rear&&q.tag==0)return true;
	return false;
}
int main(){
	Queue q1;//客车
	InitQue(q1);
	Queue q2;//货车
	InitQue(q2);
	int x;
	cout<<"客车:";
	cin>>x;
	while(x!=9999){
		EnQueue(q1,x);
		cin>>x;
	}
	cout<<"货车:";
	cin>>x;
	while(x!=9999){
		EnQueue(q2,x);
		cin>>x;
	}
	int n=0,count=0;
	while(!QueueEmpty(q1)||!QueueEmpty(q2)){
		n=0;
		while(n<10&&(!QueueEmpty(q1)||!QueueEmpty(q2))){
			if(count<4&&!QueueEmpty(q1)){
				DeQueue(q1,x);
				cout<<x<<" ";
				count++;
				n++;
			}else if(!QueueEmpty(q2)){
				count=0;
				DeQueue(q2,x);
				cout<<x<<" ";
				n++;
			}else if(!QueueEmpty(q1)){
				DeQueue(q1,x);
				cout<<x<<" ";
				n++;
			}
		}
		cout<<endl;
	}
	return 0;
}
