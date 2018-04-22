#include<stdio.h>
int fun(int List[],int length);
int main(){
	int List[6]={5,3,8,2,6,7};
	printf("%d\n",fun(List,6));
	for(int i=0;i<6;i++){
		printf("%d ",List[i]);
	}
	return 0;
}

int fun(int L[],int len){
	int tmp;
	int i=0;
	int j=len-1;
	for(;j>i;i++,j--){
		tmp=L[j];
		L[j]=L[i];
		L[i]=tmp;
	}
	return 0;
}
