#include <bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;i++)
#define eb emplace_back
#define MOD 1000000007
using namespace std;
struct Node{
	Node *left,*right,*par;
	int data,weight;
};

Node* add(Node* root,int data){
	Node *n = new Node;
	n->data = data;n->weight=data;
	n->left=NULL;n->right=NULL;
	if(root==NULL) {
		root = n;
		root->par=NULL;
	}
	else{
		if(data <= root->data){
			Node* lchild = add(root->left,data);
			root->left = lchild;
			lchild->par = root;
			lchild->weight+=lchild->par->weight;
			while(lchild->par->data < data){
				lchild->par->weight+=data;
				lchild=lchild->par;
			}
		}
		else{
			Node *rchild = add(root->right,data);
			root->right = rchild;
			rchild->par = root;
			for(Node* temp = rchild->par;temp!=root;temp=temp->par){
				temp->weight+=data;
			}
			root->weight+=data;
		}
	}
	return root;
}
void preorder(Node* root){
	if(!root) return ;
	cout << root->weight << " ";
	preorder(root->left);
	preorder(root->right);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;cin >> t;
    while(t--){
    	Node *root=NULL;
    	int n,temp;
    	cin >> n;
    	int arr[n];
    	loop(i,n){
    		cin >> temp;
    		root = add(root,temp);
    	}
    	preorder(root);
    }
}    