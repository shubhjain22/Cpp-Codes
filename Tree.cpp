#include<stdio.h>
struct Tree{
	int data;
	struct Tree *left;
	struct Tree *right;
};
struct Tree *p;
Tree insert(int x, struct Tree *p){

	if(p==null){
		p = (struct Tree *)malloc(sizeof(struct Tree));
		p->data =x;
		p->left = null;
		p->right = null;
		return p;
	}
	if(x<p->data){
		p->left = insert(p->left,x);
	}
	else{
		p->right = insert(p->right, x);
	}
}
void prn(Struct Tree *x,int level){

	int i;
	if(x){
		prn(x->right,level+1);
		printf("\n");
		for(i=0;i<level;i++){
			printf(" ");
			printf("%d",x->a);
			prn(x->left,level+1);
		}
	}
}
int main(void){

	Struct Tree *t = null;
	t=insert(t,10);
	t=insert(t,21);
	t=insert(t,4);
	t=insert(t,8);
	t=insert(t,5);
	
	prn(t,1)

}	