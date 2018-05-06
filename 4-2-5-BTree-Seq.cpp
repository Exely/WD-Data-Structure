#include<iostream>
#define ELEMTYPE int
#define MAXSIZE 50
using namespace std;
typedef struct{
	ELEMTYPE treelsit[MAXSIZE];
	int nums;
}BiTree;
int fun(BiTree* T,int i,int j){
	if(i<T->nums&&j<T->nums){
		while(i!=j){
			if(i<j)j/=2;
			else i/=2;
		}
		return T->treelsit[i];
	}
	cout<<"error"<<endl;
	return -1;
}
int main(){
	BiTree *T=(BiTree*)malloc(sizeof(BiTree));
	int x;
	cin>>x;
	T->nums=x;
	//顺序存储的二叉树初始化
	for(int i=0;i<T->nums;i++){
		cin>>x;
		T->treelsit[i]=x;
	}
	int m,n;
	cout<<"input i,j:"<<endl;
	cin>>m>>n;
	cout<<"result:"<<fun(T,m,n)<<endl;;
	for(int i=0;i<T->nums;i++){
		cout<<T->treelsit[i]<<" ";
	}
	free(T);
	cout<<endl;
	return 0;
}
