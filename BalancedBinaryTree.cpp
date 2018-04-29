//trees implemenatation
#include <bits/stdc++.h>

using namespace std;

struct Node{
	Node *right;
	Node *left;
	int data;
};

Node* insert(Node* root, int data){
	Node *n = new Node();
	n->data = data;
	n->right = NULL;
	n->left = NULL;
	if(root == NULL){
		root = n;
		return root;
	}
	else if(data<=root->data){
		root->left = insert(root->left,data);
	}
	else if(data>root->data){
		root->right = insert(root->right,data);
	}
	return root;
}

bool ifLeftSubTreeSmaller(Node* root, int value){
	if(root == NULL) return true;
	if(root->data <= value && ifLeftSubTreeSmaller(root->left, value) && ifLeftSubTreeSmaller(root->right,value)){
		return true;
	}
	else{
		return false;
	}
}

bool ifRightSubTreeLarger(Node* root, int value){
	if(root == NULL) return true;
	if(root->data > value && ifRightSubTreeLarger(root->right, value) && ifRightSubTreeLarger(root->left,value)){
		return true;
	}
	else{
		return false;
	}
}

bool isBalancedBinaryTree(Node* root){
	if(root == NULL) return true;
	if(ifLeftSubTreeSmaller(root->left,root->data) && ifRightSubTreeLarger(root->right,root->data) && isBalancedBinaryTree(root->left) && isBalancedBinaryTree(root->right)){
		return true;
	}
	else{
		return false;
	}
}

bool search(Node* root, int data){
	if(root->data == data){
		return true;
	}
	else if(data <= root->data){
		search(root->left,data);
	}
	else if(data > root->data){
		search(root->right,data);
	}
}

void PreOrder(Node* root){
	if(root == NULL) return;
	cout << root->data << endl;
	PreOrder(root->left);
	PreOrder(root->right);
}

int main(void){
	std::ios::sync_with_stdio(false);
	Node* root = NULL;
	root = insert(root,10);
	root = insert(root,20);
	root = insert(root,30);
	// cout << "Ente rthe value that is to be found" << endl;
	// int temp;
	// cin >> temp;
	// bool b = search(root,temp);
	// if(b==true){
	// 	cout << "Value has been found in the tree" << endl;
	// }
	// else{
	// 	cout << "Not Found" << endl;
	// }
	PreOrder(root);

	
}