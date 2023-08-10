#include <iostream>
using namespace std;

class node{
	public:
	
	//data part
	int data;
	//next node 
	node* next;
	
	node(int val){
		data=val;
		next =NULL;
	}
};

void insertEnd(node* &head,int val){
	
	node* n = new node(val);
	
	//If no element is present
	if(head == NULL){
		head = n;
		return;
	}
	
	node* t = head;	
	while(t->next != NULL){
		t =t->next;
	}
	
	t->next = n;
}

void insertFront(node* &head,int val){
	
	node* n = new node(val);
	n->next = head;
	head =n;	
}

void deleteHead(node* &head){
	
	node* del = head;
	head = head->next;
	delete del;
}

void deleteNode(node* &head, int val){
	
	//No element is present
	if(head == NULL)	
		return;
		
	//Only one element is present
    if(head->next==NULL){
		deleteHead(head);
		return;
	}
	
	// Delete First Element
   if(head->data==val){
		deleteHead(head);
		return;
	}
	
	node* temp = head;
	while(temp->next->data != val)
		temp = temp->next;
	
	node* del = temp->next;	
	temp->next = temp->next->next;
	cout<<"Deleted "<<val<<endl;
	delete del;
}


//Iterative reverse linked list
node* reverse1(node* &head){
	
	if(head == NULL or head->next==NULL )
		return head;
		
	node* previousptr = NULL;
	node* currentptr = head;
	node* nextptr ;
	
	while(currentptr != NULL){
		nextptr = currentptr->next;
		currentptr->next = previousptr;
		
		previousptr = currentptr;
		currentptr = nextptr;
	}
	return previousptr;	
}
		
//recursive reverse linked list
node* reverse2(node* head){	

	if(head== NULL || head->next==NULL )
		return head;
		
	node* newHead = reverse2(head->next);
	/* Choice 1.
    node* temp = newHead;
    while(temp->next!=NULL){
    temp = temp->next;
    }
    temp->next = head;
    */
    
    //Choice 2.
    head->next->next = head;
    head->next = NULL;
    	
	return newHead;
}
	
//reverse k nodes
node* reverseKNode(node* &head, int k){
	
	node* previousptr = NULL;
	node* currentptr = head;
	node* nextptr ;
	
	int count = 0;
	while(currentptr != NULL and count < k){
		nextptr = currentptr->next;
		currentptr->next = previousptr;
		
		previousptr = currentptr;
		currentptr = nextptr;
		
		count++;
	}
	
	if(nextptr != NULL)
		head->next = reverseKNode(nextptr,k);
	return previousptr;	
}


/*
NORMAL		1->2->3->4->5->6->7->NULL
------------------------------------------------------------------
CYCLE			1->2->3->4->5
								         ↑   ↓
										 7<-6
*/


//make a cycle in linked list
void makeCycle(node* &head, int n){
	node* temp = head;
	node* startNode;
	
	int count=1;
	while(temp->next != NULL){
		
		if(count == n)
			startNode = temp;
		
		temp = temp->next;
		count++ ;
	}
	
	temp->next = startNode;
}

//find cycle in linked list
bool detectCycle(node* &head){
	
	node* fast = head;
	node* slow = head;
	
	while(fast != NULL and fast->next != NULL){
		
		slow = slow->next;
		fast = fast->next->next;
		
		if(slow == fast)
			return true;
	}
	
return false;		
}


//delete cycle if present
void removeCycle(node* &head){
	
	//if(detectCycle(head)){
		
		node* fast = head;
		node* slow = head;
	
		do{
			slow = slow->next;
			fast = fast->next->next;
		}while(slow !=fast);
	
		fast = head;
		while(slow->next != fast->next){
			slow = slow->next; 
			fast = fast->next;
		}
	
		slow->next = NULL;	
//	}
}



//Find the length of linked list
int lengthOfLL(node* head){
	
	int l=0;
	node* t = head;
	while(t != NULL){
		l++;
		t = t->next;
	}
	return l;
}



// Inset K nodes at the last of linked list
node* insertKLast(node* &head, int k){
		
	node* tail = head;
	node* newTail ;
	node* newHead ;
	
	int c=1;	
	int l=lengthOfLL(head);
	k%=l;
	
	while(tail->next != NULL){
		
		if(c == (l-k))
			newTail = tail;
		if(c == (l-k+1))
			newHead = tail;
			
		tail = tail->next;
		c++;
	}
	
	newTail->next = NULL;
	tail->next = head;
	
	return newHead;
}


//Create Intersection
void createIntersection(node* &head1, node* &head2, int p){
	
	p--;
	node* temp1 = head1;
	while(p--)
		temp1 = temp1->next;

	node* temp2 = head2;
	while(temp2->next != NULL)
		temp2 = temp2->next;
		
	temp2->next = temp1;			
}

//Find Intersection
int findIntersection(node* &head1, node* &head2){
	
	if(head1==NULL or head2 == NULL)
		return -1;
	
	int l1 = lengthOfLL(head1);
	int l2 = lengthOfLL(head2);
	
	int d=0;
	node* ptr1;
	node* ptr2;
	
	if(l1 > l2){
		d = l1-l2;
		ptr1 = head1;
		ptr2 = head2;
		
	}
	else{
		d = l2-l1;
		ptr1 = head2;
		ptr2 = head1;
	}
	
	while(d){
		ptr1= ptr1->next;
		if(ptr1 == NULL)
			return -1;
		d--;
	}
	
	while(ptr1 != NULL and ptr2 != NULL){
		if(ptr1 == ptr2)
			return ptr1->data;
		ptr1= ptr1->next;
		ptr2= ptr2->next;
	}

	return -1;	
	
}




//merge two sorted linked list by Iterative method
node* mergeIterative(node* &head1, node* &head2){
	
	if(head1 == NULL || head2 == NULL){
		if(head1 == NULL){
			return head2;
		}
		else{
			return head1;
		}
	}
		
		
	node* p1 = head1;
	node* p2 = head2;
	node* dummy = new node(-1);
	node* p3 = dummy;
	
	while(p1 != NULL && p2 != NULL){
		
		if(p1->data < p2->data){
			p3->next = p1;
			p1= p1->next;
		}
		else{
			p3->next = p2;
			p2= p2->next;
		}
		
		p3 = p3->next;
	}
	
	while(p1 != NULL){
		p3->next = p1;
		p1= p1->next;
		p3 = p3->next;
	}
	
	while(p2 != NULL){
		p3->next = p2;
		p2= p2->next;
		p3 = p3->next;
	}
		
	return dummy->next;

}


//merge two sorted linked list by recursive method
node* mergeRecursive(node* &head1, node* &head2){
		
	if(head1 == NULL){
		return head2;
	}
	if(head2 == NULL){
		return head1;
	}
		
	node* result ;
	
	if(head1->data < head2->data){
		result = head1;
		result->next = mergeRecursive( head1->next, head2);
	}
	else{
		result = head2;
		result->next = mergeRecursive( head1, head2->next);
	}
	
	return result ;
	
}



//Evens index elements after odd index elements
void evenAfterOdd(node* &head){
	
	node* odd = head;
	node* even = head->next;
	node* evenStart = even;
	
	while(odd->next != NULL && even->next != NULL){
		
		odd->next = even->next;
		odd = odd->next;
		
		even->next = odd->next;
		even = even->next;
	}
			
	odd->next = evenStart;
	
	if(odd->next == NULL){
		even->next = NULL;	
	}
	
}




void display(node* head){
	
	node* t = head;
	while(t != NULL){
		cout << t->data<<"->";
		t = t->next;
	}
	cout<<"NULL"<<endl;
}

bool search(node* head , int v){
	
	while(head != NULL){
		if(head->data ==v)
			return true;
		head=head->next;
	}
	return false;
}


int main(int argc, char *argv[])
{
	/*
	//Create a node
	node* head = NULL;
	*/
	
	
	/*
	//inserting elements
	insertEnd(head,2);
	*/
	
	
	/*		
	//Deletion if only one element is present
	deleteNode(head,2);
	//displaying elements
	display(head);
	*/
	
		
	/*	
	//inserting elements from end
	insertEnd(head,0);
	insertEnd(head,4);
	insertEnd(head,62);
	insertEnd(head,24);
	insertEnd(head,67);
	insertEnd(head,80);
	//displaying elements
	display(head);
	*/
		
	
	/*	
	//inserting elements from start
	insertFront(head,78);
	insertFront(head,99);
	insertFront(head,6);
	insertFront(head,10);
	//displaying elements
	display(head);
	*/
	
	
	/*
	//delete node at start
	deleteHead(head);
	display(head);
		
	//delete node
	int m; cout<<"Delete : "; cin>>m;
	deleteNode(head,m);
	//displaying elements
	display(head);
	*/
	
	/*
	//linear search
	int n; cout<<"Search : "; cin>>n;
	if(search(head,n))
		cout<<"found "<<n<<endl;
	else
		cout<<"not found "<<n<<endl;
	*/
	
	/*
	//Iterative reverse linked list/	
	node* newHead1= reverse1(head);
	display(newHead1);
	
	//recursive reverse linked list
	node* newHead2=reverse2(newHead1);
	display(newHead2);
	
	
	//Reverse k nodes in linked list	
	int o; cout<<"K node reverse :"; cin>>o;	
	node* nodeK=reverseKNode(head,o);
	display(nodeK);		
	*/
	
	/*
	//Creating a cycle
	makeCycle(head,3);
	
	//find the cycle if present
	if (detectCycle(head))
		cout <<"Detected cycle"<<endl;
	else
		 cout <<"Not detected cycle"<<endl;	
	
	//deleting the cycle if present
	removeCycle(head);	
	display(head);
	*/
	
	
	//Memory leakage
	/*
	delete head;
	delete head2;
	delete newHead1;
	delete newHead2;
	*/
	
	
	/*
	// Inset K nodes at the last of linked list
	node* newHead4 = insertKLast(head,3);
	display (newHead4);
	*/

	/*
	//[ Intersection Problem ]
	//Creating and inserting elements in LL
	node* n1 = NULL;
	insertEnd(n1,0);
	insertEnd(n1,4);
	insertEnd(n1,62);
	insertEnd(n1,24);
	insertEnd(n1,67);
	insertEnd(n1,80);
	display(n1);
	node* n2 = NULL;
	insertEnd(n2,7);
	insertEnd(n2,12);
	display(n2);
	
	//Create Intersection
	createIntersection(n1,n2,5);
	display(n1);
	display(n2);
	
	//Find Intersection
	cout<<"Intersection point : ";
	cout<<findIntersection(n1,n2)<<endl;	
	*/
	
	
	/*
	//[ Merge Two sorted Linked list ]
	//Creating and inserting elements in LL
	node* n1 = NULL;
	insertEnd(n1,0);
	insertEnd(n1,4);
	insertEnd(n1,6);
	insertEnd(n1,12);
	insertEnd(n1,17);
	insertEnd(n1,18);
	display(n1);
	node* n2 = NULL;
	insertEnd(n2,2);
	insertEnd(n2,7);
	insertEnd(n2,13);
	insertEnd(n2,15);
	display(n2);
	
	//Merging Liked list
	
	//Iterative
	node* h1= mergeIterative(n1,n2);
	display(h1);
	
	//Recursive
	node* h2 = mergeRecursive(n1,n2);
	display (h2);
	*/
	
	
	/*
	//Evens index elements after odd index elements	
	node* headOE = NULL;
	insertEnd(headOE,1);
	insertEnd(headOE,2);
	insertEnd(headOE,3);
	insertEnd(headOE,4);
	insertEnd(headOE,5);
	insertEnd(headOE,6);
	insertEnd(headOE,7);
	insertEnd(headOE,8);
	insertEnd(headOE,9);
	insertEnd(headOE,0);
	display(headOE);
	evenAfterOdd(headOE);
	display(headOE);
	*/
	
	cout<<"\n\n\nKhatam";
	return 0;
}