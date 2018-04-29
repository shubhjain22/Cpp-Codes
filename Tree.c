#include<stdio.h>
struct Tree{
	int data;
	struct Tree *left;
	struct Tree *right;
};
struct Tree *p;
struct Tree insert(int x, struct Tree *p){

	if(p==NULL){
		p = (struct Tree *)malloc(sizeof(struct Tree));
		p->data =x;
		p->left = NULL;
		p->right = NULL;
		return p;
	}
	if(x<p->data){
		p->left = insert(p->left,x);
	}
	else{
		p->right = insert(p->right, x);
	}
}
void prn(struct Tree *x,int level){

	int i;
	if(x){
		prn(x->right,level+1);
		printf("\n");
		for(i=0;i<level;i++){
			printf(" ");
			printf("%d",x->data);
			prn(x->left,level+1);
		}
	}
}
int main(void){

	
	struct Tree *t=insert(t,10);
	struct Tree *t=insert(t,21);
	struct Tree *t=insert(t,4);
	struct Tree *t=insert(t,8);
	struct Tree *t=insert(t,5);
	
	prn(t,1);

}	