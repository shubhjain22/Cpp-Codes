#include<bits/stdc++.h>
using namespace std;
#define null NULL
struct node{
	int data,height;
	node *left,*right,*par;
};
node* insert(node* root,int data){
	node *n = new node();
	n->left = null;
	n->right = null;
	n->data = data;
	if(root==null){
		n->par = null;
		return n;
	}
	node *curr=root,*prev=null;
	while(curr!=null){
		prev=curr;
		curr = (value<curr->value)?curr->left:curr->right;
	}
	if(data<=prev->data){
		prev->left = n;
		n->par = prev;
		n->height = prev->height+1;
	}
	else{
		prev->right = n;
		n->par = prev;
		n->height = prev->height+1;
	}
}
void inorder(node* root){
	if(root==null){return ;}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		while(n--){
			int temp;
			cin >> temp;
			root = insert(root,temp);
		}
	}
}