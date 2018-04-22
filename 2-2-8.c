#include<stdio.h>
int fun(int l[],int m,int n){
	int i=0,j=0,k=0;
	int tmp=0;
	
	for(;i<n;i++){
	tmp=l[m+n-1];
		for(j=m+n-1;j>0;j--){
			l[j]=l[j-1];
		}
		l[0]=tmp;
		
	}
	return 0;

}
int main(){
	int List[6]={4,1,7,5,6,9};
	fun(List,3,3);
	for(int i=0;i<6;i++){
		printf("%d ",List[i]);
	}
	return 0;
}
