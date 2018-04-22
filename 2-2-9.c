#include<stdio.h>
#define false 0
#define true 1
#define Maxsize 10
#define length 6
int fun(int l[],int left,int right,int x){
	int i=0,j=0,k=0;
	int mid=(left+right)/2;
	if(left==right){
//		printf("%d\n",left);
		if(l[left]<x)return left;
		if(l[left]>x)return left-1;
	}
//	printf("%d\n",mid);
	if(l[mid]==x){
		return mid;
	}
	if(l[mid]<x){
		return fun(l,mid+1,right,x);
	}
	if(l[mid]>x){
		return fun(l,left,mid-1,x);
	}
}
int main(){
	int List[length+1]={1,2,3,5,6,9,0};
	int x=0;
	scanf("%d",&x);
	if(x>=List[length-1]){
		List[length]=x;
	}else if(x<List[0]){
		for(int i=length;i>0;i--){
			List[i]=List[i-1];
		}
		List[0]=x;
	}else{
		int pos=fun(List,0,length-1,x);
		printf("%d\n",pos);
		if(List[pos]==x){
		int tmp=List[pos+1];
		List[pos+1]=x;
		List[pos]=tmp;
		}else{
		for(int j=length;j>pos+1;j--){
			List[j]=List[j-1];
		}
		List[pos+1]=x;
		}
	}
	for(int i=0;i<length+1;i++){
		printf("%d ",List[i]);
	}
	return 0;
}
