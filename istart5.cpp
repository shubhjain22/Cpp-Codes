#include<bits/stdc++.h>
using namespace std;
#define null NULL
struct node{
	int data,height,sum;
	node *left,*right,*par;
};
node* insert(node* root,int data){
	node *n = new node();
	n->left = null;
	n->right = null;
	n->data = data;
	n->sum=data;
	n->height = 1;
	if(root==null){
		n->par = null;
		return n;
	}
	node *curr=root,*prev=null;
	while(curr!=null){
		prev=curr;
		curr = (data<curr->data)?curr->left:curr->right;
	}
	if(data<=prev->data){
		prev->left = n;
		n->par = prev;
		n->height = 1;
		n->sum = data+prev->sum;
		curr = prev;
		while(curr!=root)
		{
			curr->height+=1;
			curr = curr->par;
		}
		curr->height+=1;
	}
	else{
		prev->right = n;
		n->par = prev;
		n->sum = data+prev->sum;
		n->height = 1;
	}
	return root;
}
void inorder(node* root){
	if(root==null){return ;}
	inorder(root->left);
	cout << root->sum << " ";
	inorder(root->right);
}

int checkBST(node* root){
	if(root==null){
		return 1;
	}
	if(root->right && root->left && abs(root->left->height-root->right->height)>1){
		return 0;
	}
	if(root->right && !root->left && root->right->height>1){
		return 0;
	}
	if(!root->right && root->left && root->left->height>1){
		return 0;
	}
	if(root->right && root->left && abs(root->left->height-root->right->height)<1){
		return checkBST(root->left);
	}
	return checkBST(root->right);
}
int main(){
	int t;
	cin >> t;
	while(t--){
		node* root = null;
		int n;
		cin >> n;
		while(n--){
			int temp;
			cin >> temp;
			root = insert(root,temp);
		}
		inorder(root);cout  << " \n";
	}
}