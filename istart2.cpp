#include <bits/stdc++.h>
#define eb emplace_back
#define pf push_front
#define loop(i,n) for(int64_t i=0;i<n;i++)
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
}; // C++ does away with typedef. Don't have to type struct node* everywhere.

int search(node* root, int target){
    //Base Case: Empty tree. Target not found
    if (!root){ //equivalent to root == NULL
        return 0;
    }

    if (root->data == target){
        return 1;
    }
    else{
        if(target < root->data) // BST Property
            return search(root->left,target);
        else
            return search(root->right,target);
    }
}
void topView(node* root){
    if(root==NULL){
        return ;
    }
    else{
        deque<int64_t> q;
        node *temp = root;
        while(1){
            if(temp==NULL){
                break;
            }
            q.push_front(temp->data);
            temp=temp->left;
        }
        node* flag = root->right;
        while(1){
            if(flag==NULL){
                break;
            }
            q.push_back(flag->data);
            flag = flag->right;
        }
        for(int64_t i=0;i<q.size();i++){
            cout << q[i] << " ";
        }
    }
}
node* newNode(int data){
    node* ret = new(node); //equivalent to malloc(sizeof(node))
    ret->data = data;
    ret->left = NULL;
    ret->right = NULL;

    return ret;
}

node* insert(node* root, int data){
    if(!root)
        return newNode(data);

    if (data <= root->data){
        root->left = insert(root->left,data);
}
    else
        root->right = insert(root->right,data);

    return root;
}

void display(node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level+1);
        cout<<endl;
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
        }
        cout<<ptr->data;
        display(ptr->left, level+1);
    }
}
void inorder(node *ptr ){
    if (ptr != NULL)
        {
         inorder(ptr->left);
         cout<<ptr->data<< " " ;
         inorder(ptr->right);

    }
}
int64_t count(node* root){
    if(root==NULL){
        return 0;
    }
    else{
        return count(root->left)+count(root->right)+1;
    }
}
node* sumNode(node* root){
    if(root==NULL){
        return root;
    }
    if(root->left && root->right){
        root->data += root->left->data + root->right->data;
    }
    if(root->left && !root->right){
        root->data +=root->left->data;
        return sumNode(root->left);
    }
    if(root->right && !root->left){
        root->data += root->right->data;
        return sumNode(root->right);
    }
}
void levelOrder(node *root){
    if(root==NULL){
        return ;
    }
    queue<node *> q;
    q.push(root);
    while(1){
        int64_t nodeCount = q.size();
        if(nodeCount==0){
            break;
        }
        while(nodeCount > 0){
            node *n = q.front();
            cout << n->data << " ";
            q.pop();
            if(n->left!=NULL){
                q.push(n->left);
            }
            if(n->right!=NULL){
                q.push(n->right);
            }
            nodeCount--;
        }
    }
}
int main(){
    node *root = NULL;
    int64_t n;
    cin >> n;
    queue<node*> q;
    int64_t level=1;
    if(n>0){
        root = newNode(1);
        q.push(root);
        q.push(NULL);
    }
    while(n>0 && (!q.empty())){
        node *temp=q.front();
        q.pop();
        if(temp==NULL){
            if(!q.empty()){
                q.push(NULL);
            }
            level++;
        }
        else{
            int64_t a,b;
            cin >> a >> b;
            if(a!=-1){
                temp->left = newNode(a);
                q.push(temp->left);
            }
            if(b!=-1){
                temp->right = newNode(b);
                q.push(temp->right);
            }
            n--;
        }
    }
    inorder(root);
    return 0;
}


/*
void maxDepth(node *ptr){
    while(ptr->left != NULL){
        hieghtLe++;
    }
    while(ptr->right != NULL){
        hieght++;
    }
}
*/
/*
Implement
0) main() to create BSTs manually (called the driver function)
1) traversals: inorder, preorder, postorder, level order
2) function to check if given BST is root node. Hint: I can create an invalid BST just by using newNode function.
3) maxDepth, minDepth
4) minElement, maxElement of subtree
5) inorder successor, predecessor (look at cormen for edge cases)
6) LCA of two nodes
7) Delete BST (every node should be removed without dangling references). Use the delete keyword.
*/
