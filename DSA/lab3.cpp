#include <iostream>
#include <string>
using namespace std;
//stacks: LIFO
# include <stack>

stack<char> s;
char temp[100];
int i=0;

void input(){
	string ele;
	cout<<"Enter the stack elements (characters): ";
	cin>>ele;
	for(int i=0; i<ele.length();i++){
		s.push(ele[i]);	
	}
}
void display(){
	while(!s.empty()){
		cout<<s.top()<<endl;
		temp[i]=s.top();
		s.pop();
		i++;
	}
}
void reverse(){
	for(int n=0; n<i; n++){
		s.push(temp[n]);
	}
}

int main(){
	
	input();
	//reversing a stack
	cout << "Original stack (top to bottom):\n";
	display();
	cout<<"\nThe reversed stack (top to bottom):\n";
	reverse(); 	
	display();
}
