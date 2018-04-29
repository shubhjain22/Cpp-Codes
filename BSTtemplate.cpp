#include <bits/stdc++.h>
using namespace std;
struct Node{
	int64_t data,height,count;
	Node *left,*right,*par;
	Node(int64_t d){
		data = d;
		height = 0;
		count=0;
		left=NULL;
		right=NULL;
		par=NULL;
	}
};
int64_t getHeight(Node *root){
	if(root==NULL) return -1;
	return root->height;
}

// int64_t getCount(Node *root){
// 	if(root==NULL) return 0;
// 	return root->count ; 
// }
Node* insert(Node* root,int64_t data){
	if(root==NULL){
		Node *n = new Node(data);
		n->height = 0;
		n->count=0;
		root = n;
		return root;
	}
	if(data <= root->data){
		root->left = insert(root->left,data);
	}
	else{
		root->right = insert(root->right,data);
	}
	root->count++;
	root->height = 1+max(getHeight(root->left),getHeight(root->right));
	//root->count = 1+getCount(root->right)+getCount(root->left);
}

void inorder(Node* root){
	if(root==NULL) return;
	inorder(root->left);
	if(!root->par) cout << root->par->data << " ";
	inorder(root->right);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif
    Node *root=NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorder(root);
}
