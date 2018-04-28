#include<iostream>
using namespace std;
#define MAXSIZE 10
#define ELEMTYPE int
typedef struct{
	ELEMTYPE data[MAXSIZE];
	int top1;
	int top2;
}SharedStack;
bool InitStack(SharedStack &s){
	s.top1=0;
	s.top2=MAXSIZE-1;
}
bool push1(SharedStack &s,ELEMTYPE x){
	if(s.top1<=s.top2){
		s.data[s.top1++]=x;
		return true;
	}
	cout<<"error:push1"<<endl;
	return false;
}
bool push2(SharedStack &s,ELEMTYPE x){
	if(s.top2>=s.top1){
		s.data[s.top2--]=x;
		return true;
	}
	cout<<"error:push2"<<endl;
	return false;
}
bool pop1(SharedStack &s,ELEMTYPE &x){
	if(s.top1){
		x=s.data[--s.top1];
		return true;
	}
	return false;
}
bool pop2(SharedStack &s,ELEMTYPE &x){
	if(s.top2<MAXSIZE-1){
		x=s.data[++s.top2];
		return true;
	}
	return false;
}
bool EnQueue(SharedStack &s,ELEMTYPE &x){
	if(push1(s,x))return true;
	return false;
}
bool DeQueue(SharedStack &s,ELEMTYPE &x){
	while(pop1(s,x))push2(s,x);
	int tmp=0;
	bool tag=false;
	if(pop2(s,x)){
		tmp=x;
		tag=true;
	}
	while(pop2(s,x))push1(s,x);
	if(tag){
		x=tmp;
		return true;
	}
	return false;
}
bool QueueEmpty(SharedStack &s){
	if(s.top1==0&&s.top2==MAXSIZE-1)return true;
	return false;
}
int main(){
	SharedStack s;
	InitStack(s);
	int x;
	cin>>x;
	while(x!=9999){
		EnQueue(s,x);
		cin>>x;
	}
	while(DeQueue(s,x))cout<<x<<" ";
	cout<<endl;
	return 0;
}
