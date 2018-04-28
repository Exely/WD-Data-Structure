#include<iostream>
using namespace std;
#define MAXSIZE 10
#define ELEMTYPE char
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
	char x,tmp;
	cin>>x;
	while(x!='q'){
		switch(x){
			case '{':
				push(s,x);
				break;
			case '}':
				if(!pop(s,tmp))return 1;
				if(tmp!='{'){
					cout<<"error:}"<<endl;
					return 1;
				}
				break;
			case '(':
				push(s,x);
				break;
			case ')':
				if(!pop(s,tmp))return 1;
				if(tmp!='('){
					cout<<"error:)"<<endl;
					return 1;
				}
				break;
			case '[':
				push(s,x);
				break;
			case ']':
				if(!pop(s,tmp))return 1;
				if(tmp!='['){
					cout<<"error:]"<<endl;
					return 1;
				}
				break;
			default:
				cout<<"error:char"<<endl;
				return 1;
		}	
		cin>>x;
	}
	if(StackEmpty){
		cout<<"error:last"<<endl;
		return 1;
	}
	cout<<"true"<<endl;
	return 0;
}
