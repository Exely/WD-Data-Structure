#include<iostream>
using namespace std;
#define MAXSIZE 10
#define ELEMTYPE node
typedef struct{
	int p;
	int no;
}node;
typedef struct{
	ELEMTYPE data[MAXSIZE];
	int top; //top 指针	
}SqStack;
void InitStack(SqStack &stk){
	stk.top=0;
}
bool StackEmpty(SqStack stk){
	if(!stk.top)return true;
	return false;
} 
//注意：一定要加引用型！
bool push(SqStack &stk,ELEMTYPE x){
	//MAXIZE
	if(stk.top<MAXSIZE){
		stk.data[stk.top++]=x;
		return true;
	}
	return false;
}
bool pop(SqStack &stk,ELEMTYPE &x){
	if(stk.top>0){
		x=stk.data[--stk.top];
		return true;
	}
	return false;
}
bool gettop(SqStack stk,ELEMTYPE &x){
	if(stk.top){
		x=stk.data[stk.top-1];
		return true;
	}
	return false;
}

int main(){
	SqStack s;
	InitStack(s);
	int x,n,p,t;
	cout<<"x: ";
	cin>>x;
	cout<<"n: ";
	cin>>n;
	t=n;
	ELEMTYPE nd,tmp;
	for(;n>=2;n--){
		nd.no=n;
		push(s,nd);
	}
	int p0=1,p1=2*x;
	while(pop(s,tmp)){
		p=2*x*p1-2*(tmp.no-1)*p0;
	//	cout<<"p"<<tmp.no<<"="<<p<<"="<<"2x*"<<p1<<"-2*("<<tmp.no-1<<")*"<<p0<<" ";
		p0=p1;
		p1=p;
	}
	if(t>1)cout<<p<<endl;
	else if(t==0)cout<<1<<endl;
	else if(t==1)cout<<2*x<<endl;
	return 0;
}
