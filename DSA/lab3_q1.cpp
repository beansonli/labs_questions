#include <iostream>
#include <string>
using namespace std;
//stacks: LIFO
# include <stack>
stack<char> s;
char temp[100];
int i=0, option;

void input(){
	cout<<"-------- STACK MENU s---------\n1. push() \n2. pop() \n3. isEMPTY() \n4. isFULL() \n5. display()\n6. peek() \n7. EXIT \n";
	cin>>option;
}

void display(){
	while(!s.empty()){
		cout<<s.top()<<endl;
		temp[i]=s.top();
		s.pop();
		i++;
	}
}
void Push(){
	int ele;
	cout<<"Enter element into the stack: ";
	cin>>ele;
	s.push(ele);
}

void isEMPTY(){
	if(s.empty())
		cout<<"YES! It's empty. \nFill me up NOW!"<<endl;
	else
		cout<<"NAH man, its good."<<endl;
}

void isFULL(){
	if(!s.empty())
		cout<<"YES! It's FULL. CHILL!"<<endl;
	else
		cout<<"NAH man, get to work."<<endl;
}

void peek(){
	cout<<"Last element entered: "<<s.top()<<endl;
}

int main(){
	
	
	while(option!=7){
		input();
		
		switch(option){
			case 1:
				Push();
				break;
			case 2:
				s.pop();
				break;
			case 3:
				isEMPTY();
				break;
			case 4:
				isFULL();
				break;
			case 5:
				display();
				break;
			case 6:
				peek();
				break;
		}
	}
}
