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

struct node *top = NULL;

void push(int x){

  if(top == NULL){
    top = new node(x);
    top -> value = x;
  }else{
    struct node *a;
    a = new node(x);
    a -> value = x;
    a -> next = top;
    top = a;
  }
   
}
void pop() {
  struct node *a;
  if(top == NULL){
    cout << "empty";
  }else{
  a = top;
  top = top-> next;
  cout << a->value;
  delete a;
  }
  
}

int main(){

  push(5);
  push(4);
  pop();
  cout << top->value;
	
}
