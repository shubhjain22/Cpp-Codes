#include <bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node *next;
};

Node *head = NULL;

void add(int data){
	//struct Node *n = (struct Node*)malloc(sizeof(struct Node)); 
	Node *n = new Node();
	n->data = data;
	n->next = NULL;
	if(head == NULL){
		head = n;
		n->next = NULL;
		return;
	}
	
		Node *curr, *prev;
		for(prev = curr = head;curr!=NULL;prev = curr, curr = curr->next){
			
		}
		prev->next = n;
		prev = n;
		n->next = NULL;
		return;
	
}

void remove(int data){
	Node *prev,*curr;
	while(curr->data!=data){
		prev = curr;
	}
	if(curr!=NULL){
		prev->next = curr->next;
	}
}

void traverse(){
	Node *temp;
	for(temp = head;temp!=NULL;temp = temp->next){
		cout << temp->data << endl;
	}
}
int main(void){
	std::ios::sync_with_stdio(false);
	add(1);
	add(2);
	add(3);
	traverse();
}