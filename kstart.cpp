#include <bits/stdc++.h>

using namespace std;

struct Node{
	Node* left;
	Node* right;
	int data;
};

Node* insert(Node *root, int data){
	Node* n = new Node();
	n->data = data;
	n->right = NULL;
	n->left = NULL;
	if(root == NULL){
		root = n;
	}
	else if(root->data < data){
		root->right = insert(root->right,data);
	}
	else if(data <= root->data){
		root->left = insert(root->left,data);
	}
	return root;
}

bool search(Node *root, int data){
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

void inorder(Node* root){
	if(root == NULL) return ;
	
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

bool leftsmaller(Node* root, int value){
	if(root == NULL) return true;
	if(root->data <= value && leftsmaller(root->left,  value) && leftsmaller(root->right,  value)){
		return true;
	}
	else{
		return false;
	}
}

bool rightlarger(Node* root, int value){
	if(root == NULL) return true;
	if(root->data > value && rightlarger(root->right,value) && rightlarger(root->left, value)){
		return true;
	}
	else{
		return false;
	}
}

bool balanced(Node* root){
	if(leftsmaller(root->left,root->data) && rightlarger(root->right,root->data) && balanced(root->left) && balanced(root->right)){
		return true;
	}
	else{
		return false;
	}
}

int height(Node* root){
	int h1=0,h2=0;
	if(root==NULL) return 0;
	if(root->left){
		h1 = height(root->left);
	}
	if(root->right){
		h2 = height(root->right);
	}
	return (max(h1,h2)+1);
}

int elements(Node* root){
	int n1=0,n2=0;
	if(root==NULL) return 1;
	if(root->left){
		n1+=elements(root->left);
	}
	if(root->right){
		n2+=elements(root->right);
	}
	return (n1+n2+1);
}

bool identical(Node* root1, Node* root2){
	if(root1==NULL && root2==NULL) return true;
	else if(root1!=NULL && root2!=NULL){
		return (root1->data == root2->data) && identical(root1->left, root2->left) && identical(root1->right, root2->right);
	}
}

int minimum(Node* root){
	if(root == NULL) return INT_MIN;
	while(root->left!=NULL){
		root = root->left;
	}
	return root->data;
}

int maxDepth(Node* root){
	if(root == NULL) return 0;
	int h1 = maxDepth(root->left);
	int h2 = maxDepth(root->right);
	if(h1>h2){
		return h1+1;
	}
	else return h2+1;
}

Node* mirrorCopy(Node* root){
	if(root==NULL) return root;
	Node* temp = new Node();
	temp->data = root->data;
	temp->left = mirrorCopy(root->right);
	temp->right = mirrorCopy(root->left);
	return temp;
}

int countLeaf(Node* root){
	if(root == NULL) return -1;
	int count = 0,p=0;
	countLeaf(root->left);
	if(root->left==NULL && root->right==NULL){
		count++;
	}
	p+=count;
	countLeaf(root->right);
	return p;
}

int main(void){
	std::ios::sync_with_stdio(false);
	Node* root = NULL;
	root = insert(root,8);
	root = insert(root,5);
	root = insert(root,4);
	root = insert(root,9);
	root = insert(root,7);
	root = insert(root,11);
	root = insert(root,1);
	root = insert(root,12);
	root = insert(root,3);
	root = insert(root,2);
	int a = countLeaf(root);
	cout << a << endl;
	return 0;
}