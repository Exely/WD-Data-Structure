#include<iostream>
using namespace std;
int main(){
	char x;
	cin>>x;
	int count=0;
	while(x!='q'){
		switch(x){
			case 'I':
				count++;
				break;
			case 'O':
				count--;
				break;
			default:
				cout<<"error";
				return 1;
		}
		if(count<0){
			cout<<"false"<<endl;
			return 1;
		}
		cin>>x;
	}
	if(count){
		cout<<"false"<<endl;
		return 1;
	}
	cout<<"true"<<endl;
	return 0;
}
