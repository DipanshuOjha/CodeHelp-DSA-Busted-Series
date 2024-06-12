#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
	Node(int data){
        this->next = NULL;
        this->data = data;
	}
	~Node(){
		int value = this->data;
        if(this->next!=NULL){
        	delete next;
        	next = NULL;
        }
	}
	
};

int getlength(Node* head){
	 int len = 1;
	 Node* curr = head->next;
	 while(curr!=head){
	 	  len++;
	 	  curr = curr->next;
	 }

	 return len;
}

void split(Node* head,Node* &head1,Node* &head2){

    if(head==NULL){

    	cout<<"Empty linked list"<<endl;
    	return;
    }

    int len = getlength(head);
    head1 = head;
    int cnt=1;

    Node* trace = head;
    while(cnt<len/2){
    	 cnt++;
    	 trace = trace->next;
    }

    Node* temp = trace->next;
    trace->next = head1;
    head2 = temp;
        
    while(temp->next!=head){
     	   temp = temp->next;
    }

    temp->next = head2;

}