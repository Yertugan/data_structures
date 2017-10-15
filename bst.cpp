#include <iostream>
using namespace std;

struct node{
	int value;
	struct node *left;
	struct node *right;
};

struct node *top = NULL;

struct node* search( node* top, int value)
{
    
    if (top == NULL || top->value == value){
       return top;
    }
    
    
    if (top->value < value){
       return search(top->right, value);
    }
 
    
    return search(top->left, value);
}

void add(node *top, int x){
  if (top == NULL){
    top = new node;
    top->value = x;
    return;
  }
  if(top->value > x){
  	if(top->left == NULL){
  		top->left = new node;
	    top->left->value = x;
	    return;
  	}
  	add(top->left, x);
  	return;
  }
  else{
  	if(top->right == NULL){
  		top->right = new node;
  		top->right->value = x;
  		return;
  	}
  	add(top->right, x);
	}
}

node* minValue(node *top){
	struct node *current = top;
	while (current->left != NULL){
	current = current->left;
	}
	return current;
}

node* deleteNode(node *top, int key){
	if (top == NULL) {
		return top;
	}
	if (key < top->value){
		top->left = deleteNode(top->left, key);
	}
	else if (key > top->value){
		top->right = deleteNode(top->right, key);
	}
	else{
		if (top->left == NULL){
			struct node *temp = top->right;
			delete(top);
			return temp;
			}
			if (top->right == NULL){
			struct node *temp =top->left;
			delete(top);
			return temp;
			}

		}
	return top;
}

int main(){
	add(top, 1);
	add(top, 5);
	search(top , 5);
	deleteNode(top, 5);
}
