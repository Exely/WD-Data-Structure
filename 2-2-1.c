#include<stdio.h>
int fun(int List[],int length);
int main(){
	int List[5]={5,3,2,6,7};
	printf("%d\n",fun(List,5));
	for(int i=0;i<5;i++){
		printf("%d ",List[i]);
	}
	return 0;
}

int fun(int L[],int len){
	if(len==0){
		printf("error\n");
		return 0;
	}
	int min=L[0];
	int j=0;
	for(int i=0;i<len;i++){
		if(min>L[i]){
			min=L[i];
			j=i;
		}
	}
	L[j]=L[len-1];
	L[len-1]='\0';
	return min;
}
