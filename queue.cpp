#include <iostream>

using namespace std;

struct node{
	int value;
	node *next;
	node(int value){
		this-> value = value;
		this-> next=NULL;
	}
};

node *end, *front;

void push(int  x){
	if (front == NULL){
		front = end = new node(x);
	}else{
		node *n = new node(x);
		end -> next = n;
		end = n;
	}
}

void display(){
    if(front==NULL){
        cout<<"empty"<<endl;
        return;
    }
    node *temp = front;
    
    while(temp){
        cout << temp->value <<" ";
        temp = temp-> next;
    }
    cout << endl;
}

void pop(){
	
	if(front == NULL){
		cout << "empty";
		return;
	}
	cout << front-> value <<endl;
	if(front == end){
		front = end = NULL;
	}else{
		front = front-> next;
	}
	
}

int main(){
	push(3);
	push(1);
	display();
	push(2);
	push(4);
	pop();
	display();
	
}
