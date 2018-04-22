#include<stdio.h>
#include<stdlib.h>
int* merge(int l1[],int len1,int l2[],int len2){
	int i=0,j=0,k=0;
	int *L=(int *)malloc((len1+len2)*sizeof(int)); //指针必须要赋值。
	if(!L){
		return 0;
	}
	while(i<len1 && j<len2){
		if(l1[i]<=l2[j]){
			L[k++]=l1[i];
			i++;
		}
		if(l1[i]>l2[j]){
			L[k++]=l2[j];
			j++;

		}
	}
	while(i<len1){
		L[k++]=l1[i++];
	}
	while(j<len2){
		L[k++]=l2[j++];
	}
	return L;
}
int main(){
	int L1[6]={4,5,5,6,6,9};
	int L2[7]={1,3,5,5,6,7,8};
	int *L=merge(L1,6,L2,7);
	for(int i=0;i<13;i++){
		printf("%d ",L[i]);
	}
	free(L);
	return 0;
}
