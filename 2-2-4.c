#include<stdio.h>
int fun(int List[],int length,int s,int t);
int main(){
	int List[6]={1,5,4,5,6,1};
	//printf("%d\n",fun(List,6));
	fun(List,6,5,9);
	for(int i=0;i<6;i++){
		printf("%d ",List[i]);
	}
	return 0;
}

int fun(int L[],int len,int s,int t){
	if(len==0||s>=t){
		printf("error");
		return 0;
	}
	int tmp;
	int i=0;
	int j=0;
	int k=0;
	for(i=0;i<len;i++){
		if(s<=L[i] && L[i]<=t){
//			printf("%d ",L[i]);
		}else{
			L[k]=L[i];
			k++;
		}
	}
	for(;k<len;k++){
		L[k]='\0';
	}	
	return 0;
}
