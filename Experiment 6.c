#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	node *left, *right;
	bool isThreaded;
};
struct node *root=NULL;
struct node *createThreaded(node *root) 
{ 
    // Base cases : Tree is empty or has single 
    //              node 
    if (root == NULL) 
        return NULL; 
    if (root->left == NULL && 
        root->right == NULL) 
        return root; 
  
    // Find predecessor if it exists 
    if (root->left != NULL) 
    { 
        // Find predecessor of root (Rightmost 
        // child in left subtree) 
        node* l = createThreaded(root->left); 
  
        // Link a thread from predecessor to 
        // root. 
        l->right = root; 
        l->isThreaded = true; 
    } 
  
    // If current node is rightmost child 
    if (root->right == NULL) 
        return root; 
        // Recur for right subtree. 
    return createThreaded(root->right); 
}
struct node *leftMost(node *root) 
{ 
    while (root != NULL && root->left != NULL) 
        root = root->left; 
    return root; 
} 
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
void inOrder(node *root) 
{ 
    if (root == NULL) return; 
  
    // Find the leftmost node in Binary Tree 
    node *cur = leftMost(root); 
  
    while (cur != NULL) 
    { 
        printf("\n",cur->data); 
  
        // If this Node is a thread Node, then go to 
        // inorder successor 
        if (cur->isThreaded) 
            cur = cur->right; 
  
        else // Else go to the leftmost child in right subtree 
            cur = leftMost(cur->right); 
    } 
} 
int main()
{
	root=insert();	
	insert();
	createThreaded(root); 
    printf("Inorder traversal of created threaded tree is\n"); 
    inOrder(root); 
    return 0; 
} 
