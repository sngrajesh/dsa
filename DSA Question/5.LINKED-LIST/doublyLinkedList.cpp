#include<iostream>
using namespace std;

class node{
	public:
	node* previous;
	int data;
	node* next;
	
	node(int val){
		previous = NULL;
		data = val;
		next = NULL;
	}
};


void insertAtHead(node* &head , int val){
	
	node* n = new node(val);
	
	n->next = head;
	if(head != NULL)
		head->previous = n;
	
	head=n;		
}

void insertAtTail(node* &head , int val){
	
	if(head == NULL){
		insertAtHead(head ,val);
		return;
	}
	
	node* n = new node(val);
	node* temp = head;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next=n;
	n->previous=temp;
		
}
void deleteAtHead(node* &head){
	
	if(head == NULL)
		return;
	
	node* toDelete = head;
	
	head = head->next;
	if(head != NULL)
          head->previous = NULL;	
	
	delete toDelete;
	
}

void deletion(node* &head , int n){
	
	if(n == 1){
		deleteAtHead(head);
		return;
	}
	

	int c=1;
	node* temp = head ;
	while(temp != NULL and c != n){
		temp = temp->next;
		c++;
	}
	
	temp->previous->next = temp->next;
	if(temp->next !=NULL){
	temp->next->previous=temp->previous;
	}
		
	delete temp;
}


void display(node* &head){
	
	if(head==NULL)
		return;
	
	node* temp = head;
	
	while(temp->next != NULL){
		cout << temp->data <<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

int main(int argc, char *argv[]){
	
	//create a node
	node* head;

	//Deletion if no element is present	
	deletion(head,1);
	display (head);
	
	//Insertion from last/end
	insertAtTail(head ,5);
	display (head);
	
	//Deletion if one element is present		
	deletion(head,1);
	display (head);
	
	//Insertion
	insertAtTail(head ,10);
	insertAtTail(head ,15);
	insertAtTail(head ,20);
	insertAtTail(head ,25);
	display (head);
	
	//Insertion from head
	insertAtHead(head,0);
	display (head);
		
	//Deletion from head
	deletion(head,1);
	display(head);
	
	//Deletion from head
	deleteAtHead(head);
	display (head);
	
	delete head;
	return 0;
}