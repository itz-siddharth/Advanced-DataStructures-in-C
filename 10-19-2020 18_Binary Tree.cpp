#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	node *left, *right;
};
struct node *root=NULL;
struct node* insert()
{
	int x;
	struct node *p;
	printf("Enter data(-1 for no data):");
	scanf("%d",&x);
	
	if(x==-1)
		return NULL;
	
	p=(struct node*)malloc(sizeof(struct node));
	p->data=x;
	
	printf("Enter left child of %d:\n",x);
	p->left=insert();
 
	printf("Enter right child of %d:\n",x);
	p->right=insert();
	
	return p;
}
void preorder(node *t)		//address of root node is passed in t
{
	if(t!=NULL)
	{
		printf("\n%d",t->data);		//visit the root
		preorder(t->left);		//preorder traversal on left subtree
		preorder(t->right);		//preorder traversal om right subtree
	}
}
int main()
{
	root=insert();	
	preorder(root);
}
