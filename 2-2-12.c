#include<stdio.h>
int fun(int l[],int n){
	int tmp=l[0];
	int count=0;
	for(int i=0;i<n;i++){
		if(l[i]==tmp){
			count++;
		}else{
		if(count>0){
			count--;
		}else{
				count++;
				tmp=l[i];
			}
		}
	}
	count=0;
	for(int i=0;i<n;i++){
		if(l[i]==tmp){
			count++;
		}
	}
	if(count>n/2)return tmp;
	else return -1;
}
int main(){
	int p=3;
	int List[6]={4,0,1,1,1,1};
	p=fun(List,6);
//	for(int i=0;i<6;i++){
		printf("%d ",p);
//	}
	return 0;
}
