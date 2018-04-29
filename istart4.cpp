#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
struct node{
	int data,depth,sum;
	node *left,*right,*par;
	node (int data,node* par,int depth,int sum){
		this->data = data;
		this->par=par;
		this->depth = depth;
		this->right=NULL;
		this->left=NULL;
		this->sum=sum;
	}
};
// node* binaryinsert(int levelorder[],int n){
// 	if(n==0){
// 		return NULL;
// 	}
// 	node *root = new node(levelorder[0],NULL,0,levelorder[0]);
// 	int index = 1;
// 	while(index<n){
// 			node *prev=NULL,*curr=root;
// 			while(curr!=NULL){
// 				prev=curr;
// 				curr=(levelorder[index]<curr->data)?curr->left:curr->right;
// 			}
// 			if(levelorder[index]<prev->data){
// 				prev->left = new node(levelorder[index],prev,prev->depth+1,prev->sum+levelorder[index]);
// 			}
// 			else{
// 				prev->right = new node(levelorder[index],prev,prev->depth+1,prev->sum+levelorder[index]);
// 			}
// 		index++;
// 	}
// 	return root;
// }
node* levelOrderinsert(int levelorder[],int n){
	if(n==0){
		return NULL;
	}
	node *root = new node(levelorder[0],NULL,0,levelorder[0]);
	queue<node* > q;
	q.push(root);
	int index=1;
	while(!q.empty()){
		node* p = q.front();
		q.pop();
		if(index<n){
			int h = levelorder[index++];
			p->left = new node(h,p,p->depth+1,(p->sum)+h);
			q.push(p->left);
		}
		else{
			break;
		}
		if(index<n){
			int h = levelorder[index++];
			p->right = new node(h,p,p->depth+1,(p->sum)+h);
			q.push(p->right);
		}
		else{
			break;
		}
	}
	return root;
}
void inorder(node* root){
	if(root==NULL){
		return ;
	}
	inorder(root->left);
	inorder(root->right);
	if(root->par!=NULL){
		cout << root->par->data << " ";
	}
}

void levelordertraverse(node* root){
	if(root==NULL){
		return ;
	}
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* temp = q.front();
		q.pop();
		cout << temp->data << " ";
		if(temp->left) q.push(temp->left);
		if(temp->right) q.push(temp->right);
	}
}
node* lca(node* a,node* b){
	if(a->par==NULL ){
		return a;
	}
	if(b->par==NULL){
		return b;
	}
	if(a->par==b->par){
		return a->par;
	}
	if(a->par==b){
		return b;
	}
	if(b->par==a){
		return a;
	}
	if(a->par!=NULL){
		return lca(a->par,b);
	}
	if(b->par!=NULL){
		return lca(a,b->par);
	}
}



int main(){
	node* root=NULL;	
	int arr[7]={2,4,1,6,9,2,3};
	levelOrderinsert(arr,7);
	levelordertraverse (root);
}