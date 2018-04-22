#include<stdio.h>
int fun(int l[],int m,int n){
	int mid=(m+n)/2;
	for(int i=0;i<=(n-m)/2;i++){ // m+i<=n-i
		int tmp=l[n-i];
		l[n-i]=l[m+i];
		l[m+i]=tmp;
	}
	return 0;

}
int main(){
	int p=3;
	int List[6]={4,1,7,5,6,9};
	fun(List,0,p-1);
	fun(List,p,5);
	fun(List,0,5);
	for(int i=0;i<6;i++){
		printf("%d ",List[i]);
	}
	return 0;
}
