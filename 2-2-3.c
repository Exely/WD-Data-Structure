#include<stdio.h>
int fun(int List[],int length,int val);
int main(){
	int List[6]={5,3,8,2,8,7};
	//printf("%d\n",fun(List,6));
	fun(List,6,8);
	for(int i=0;i<6;i++){
		printf("%d ",List[i]);
	}
	return 0;
}

int fun(int L[],int len,int val){
	int tmp;
	int i=0;
	int j=0;
	for(;i<len;i++){
		if(L[i]==val){
			j++;
		}else{
		L[i-j]=L[i];
		}
	}
	for(int k=len-j;k<len;k++){
		L[k]='\0';
	}	
	return 0;
}
