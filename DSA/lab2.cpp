#include <iostream>
using namespace std;

int n, arr[25], target;

void display(int no, int arr[]){
	
	for(int i=0; i<no;i++){
		cout<<"Element at "<<i+1<<": "<<arr[i]<<endl;	
	}
	
}

void del(int pos){
	
	if(pos==n){
		n--;
	}
	
	else{
		for(int i=pos-1; i<n-1;i++){
			arr[i]=arr[i+1];
		}
		n--;
	}
}

void unique(){
	
	for(int i=0;i<n;i++){
		
		for(int j=i+1; j<n;j++){
			
			if(arr[i]==arr[j]){
				
				del(j+1);
				break;
			}
		}
	}
}

void getData(void){
	
	cout<<"enter no. of elements: ";
	cin>>n;
	
	for(int i=0; i<n;i++){
		cout<<"Element at "<<i+1<<": ";	
		cin>>arr[i];
	}
}

void sum_pair(int sum){
	
	for(int i=0; i<n;i++){
		for(int j=i+1; j<n;j++){
			
			if(sum==arr[i]+arr[j]){
				cout<<"\nTarget found at indeces "<<i<<", "<<j<<endl;
				cout<<"Elements are "<<arr[i]<<", "<<arr[j]<<endl;
				break;
			}
		}
	}
	
	
}



int main(){
	
	getData();
	cout<<"Enter target sum: ";
	cin>>target;
	sum_pair(target);
	cout<<"\n";
	
/*	getData();
	cout<<"\n UNIQUE DATA \n";
	unique();
	cout<<"\n";
	display(n, arr);
	cout<<"\n";
*/
}
