#include<bits/stdc++.h>
using namespace std;
struct node
{
	int64_t data;
	node* left;
	node* right;
	int64_t height,count;
};

int64_t height(node* t)
{
	return (t == NULL ? -1 : t->height);
}

int64_t getCount(node* root){
	if(root == NULL){
		return 0;
	}
	return root->count;
}
void makeEmpty(node* t)
{
	if(t == NULL)
		return;
	makeEmpty(t->left);
	makeEmpty(t->right);
	delete t;
}

node* singleRightRotate(node* &t)
{
	node* u = t->left;
	t->left = u->right;
	u->right = t;
	t->height = max(height(t->left), height(t->right))+1;
	u->height = max(height(u->left), t->height)+1;
	t->count = 1 + getCount(t->left) + getCount(t->right);
	u->count = 1 + getCount(u->left) + getCount(u->right);
	return u;
}

node* singleLeftRotate(node* &t)
{
	node* u = t->right;
	t->right = u->left;
	u->left = t;
	t->height = max(height(t->left), height(t->right))+1;
	u->height = max(height(t->right), t->height)+1 ;
	t->count = 1 + getCount(t->left) + getCount(t->right);
	u->count = 1 + getCount(u->left) + getCount(u->right);
	return u;
}

node* doubleLeftRotate(node* &t)
{
	t->right = singleRightRotate(t->right);
	return singleLeftRotate(t);
}

node* doubleRightRotate(node* &t)
{
	t->left = singleLeftRotate(t->left);
	return singleRightRotate(t);
}

node* insert(node* t,int64_t x)
{
	if(t == NULL)
	{
		t = new node;
		t->data = x;
		t->height = 0;
		t->left = t->right = NULL;
	}
	else if(x < t->data)
	{
		t->left = insert(t->left,x);
		if(height(t->left) - height(t->right) == 2)
		{
			if(x < t->left->data)
				t = singleRightRotate(t);
			else
				t = doubleRightRotate(t);
		}
	}
	else if(x > t->data)
	{
		t->right = insert(t->right,x);
		
		if(height(t->right) - height(t->left) == 2)
		{
			if(x > t->right->data)
				t = singleLeftRotate(t);
			else
				t = doubleLeftRotate(t);
		}
	}

	t->height = 1+max(height(t->left), height(t->right));
	t->count = 1 + getCount(t->left) + getCount(t->right);
	return t;
}



node* findMin(node* t)
{
	if(t == NULL)
		return NULL;
	else if(t->left == NULL)
		return t;
	else
		return findMin(t->left);
}

node* findMax(node* t)
{
	if(t == NULL)
		return NULL;
	else if(t->right == NULL)
		return t;
	else
		return findMax(t->right);
}

node* remove(node* t,int64_t x)
{
	node* temp;
	if(t == NULL)
		return NULL;
	else if(x < t->data)
		t->left = remove( t->left,x);
	else if(x > t->data)
		t->right = remove(t->right,x);

        // Element found
        // With 2 children
	else if(t->left && t->right)
	{
		temp = findMin(t->right);
		t->data = temp->data;
		t->right = remove( t->right,t->data);
	}
        // With one or zero child
	else
	{
		temp = t;
		if(t->left == NULL)
			t = t->right;
		else if(t->right == NULL)
			t = t->left;
		delete temp;
	}
	if(t == NULL)
		return t;

	t->height = max(height(t->left), height(t->right))+1;
	t->count = 1 + getCount(t->left) + getCount(t->right);

        // If node is unbalanced
        // If left node is deleted, right case
	if(height(t->left) - height(t->right) == 2)
	{
            // right right case
		if(height(t->left->left) - height(t->left->right) == 1)
			return singleLeftRotate(t);
            // right left case
		else
			return doubleLeftRotate(t);
	}
        // If right node is deleted, left case
	else if(height(t->right) - height(t->left) == 2)
	{
            // left left case
		if(height(t->right->right) - height(t->right->left) == 1)
			return singleRightRotate(t);
            // left right case
		else
			return doubleRightRotate(t);
	}
	t->count = 1 + getCount(t->left) + getCount(t->right);
	return t;
}

int64_t getBalance(node* t)
{
	if(t == NULL)
		return 0;
	else
		return height(t->left) - height(t->right);
}

void inorder(node* t)
{
	if(t == NULL)
		return;
	inorder(t->left);
	cout << t->height << " ";
	inorder(t->right);
}
int64_t count1;
void display(node* root)
{
	inorder(root);
	cout << endl;
}

bool index(node *root,int64_t data){
	if(root==NULL){
		return false;
	}
	if(root->data == data){
		count1+=getCount(root->left);
		return true;
	}
	else if(data < root->data){
		return index(root->left,data);
	}
	else{
		count1+=(1+getCount(root->left));
		return index(root->right,data);
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif
	int64_t q,a;
	cin >> q;
	node *root=NULL;
	int count=0;
	while(q--){
		cin >> a;
		if(a==1){
			int64_t temp;
			cin >> temp;
			root = insert(root,temp);
			count++;
		}
		else{
			count1=1;
			int64_t temp;
			cin >> temp;
			bool ans = index(root,temp);
			if(!ans){
				cout << "Data tidak ada" << "\n";
			}
			else{
				cout << count1 << "\n";
			}
		}
	}
}