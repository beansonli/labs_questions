#include <iostream>
using namespace std;
int option, arr[10], n, pos, val;

void create(){
            cout<<"Enter number of elements: ";
            cin>>n;
            
            for(int i=0; i<n; i++){
                cout<<"Enter element for index "<<i<<": ";
                cin>>arr[i];
            }
            
            cout<<"ARRAY SAVED SUCCESSFULLY!"<<endl;
            
    }
    
void display(){
    for(int i=0; i<n;i++){
            cout<<arr[i]<<" ";
        }
    cout<<"\n";
}
    
    void insert(){
            if (n == 0) {
                cout << "Create array first.\n";
                return;
            }
            
            cout<<"Enter new element: ";
            cin>>val;
            cout<<"Enter position to insert: ";
            cin>>pos;
            
            if(n==pos){
                arr[n]=val;
            }
            else{
                for(int i=n; i>=pos-1; i--){
                    arr[i]=arr[i-1];
                }
                arr[pos-1]=val;
            }
            n = n + 1;
            cout<<"Inserted "<<val<< " successfully at position "<<pos<<endl;
    }
    
    void del(){
            if (n == 0) {
                cout << "Create array first.\n";
                return;
            }
            
            cout<<"Enter element's position to delete: ";
            cin>>pos;
                
            if(n==pos){
                val=arr[pos-1];
            }
            else{
                val = arr[pos - 1];
                for(int i=pos-1; i<n-1; i++){
                    arr[i]=arr[i+1];
                }
            }
                
            n= n-1;
    }
    
    void reverse(){
            if (n == 0) {
                cout << "Create array first.\n";
                return;
            }
            
            int start = 0;
            int end = n-1;
                
            while(start<end){
                int temp=arr[start];
                arr[start]=arr[end];
                arr[end]=temp;
                start++; 
                end--;
            }
                
            cout<<"Array successfully reversed!"<<endl;
    }
    
    void linear_search(){
        cout<<"Enter element to find: ";
        cin>>val;
        
        for(int i=0; i<n ;i++){
            if(arr[i]==val){
                cout<<"Element found at "<<i+1<<" position."<<endl;
            }
        }
    }

int main(){
    do{
        cout<<"SELECT ACTION TO PERFORM"<<endl<<"---------MENU----------"<<endl<<"1. Create"<<endl<<"2. Display"<<endl<<"3. Insert"<<endl<<"4. Delete"<<endl<<"5. Reverse"<<endl<<"6. Linear Search"<<endl<<"7. Exit"<<endl;
        cin>>option;
        
        switch(option){
            case 1:
                create();
                break;
                
            case 2:
                display();
                break;
                
            case 3:
                insert();
                break;
                
            case 4:
                del();
                break;
                    
            case 5:
                reverse();
                break;
                
            case 6:
                linear_search();
                break;
                
        }
    } while(option != 7);
    
}
