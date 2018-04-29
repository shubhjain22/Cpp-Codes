#include <bits/stdc++.h>
using namespace std;

struct Node {
   int data;
   Node *next;
};
Node *head = NULL;
void add(int data){
   Node *n = new Node();
   n->data = data;
   if(head==NULL){
      head = n;
      n->next = NULL;
      return;
   }
   Node *prev, *curr;
   for(prev = curr = head;curr!=NULL;prev=curr,curr=curr->next){

   }
   prev->next = n;
   n->next = NULL;
}

void traverse(Node *head){
   Node *temp;
   for(temp= head;temp!=NULL;temp = temp->next){
      cout << temp->data << "\n";
   }
}

int main(void){
   
   add(10);
   add(20);
   add(30);
   traverse(head);
}