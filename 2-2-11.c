#include<stdio.h>
int fun(int l1[],int l2[],int m,int n){
	int i=0,j=0,k=0;
	int mid=0;
	int tmp=0;
	if((m+n)%2==0){	
		mid=(m+n)/2;
	}else{
		mid=(m+n)/2+1;
	}
	while(i<m && j<n){
		if(l1[i]<=l2[j]){
			k++;
			if(k==mid){
				tmp=l1[i];
				break;
			}
			i++;
		}else if(l1[i]>l2[j]){
			k++;
			if(k==mid){
				tmp=l2[j];
				break;
			}
			j++;
		}
	}
	while(i<m){
		k++;
		if(k==mid){
			tmp=l1[i];
			break;
		}
		i++;
	}
	while(j<n){		
		k++;
		if(k==mid){
			tmp=l2[j];
			break;
		}
		j++;
	}
	return tmp;
}
int main(){
	int l1[6]={11,13,15,17,19,21};
	int l2[5]={2,4,6,8,20};
	int p=fun(l1,l2,6,5);
	//for(int i=0;i<6;i++){
	printf("%d\n",p);
	//	}
	return 0;
}
