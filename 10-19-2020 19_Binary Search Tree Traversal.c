#include<stdio.h> 
#include<stdlib.h> 
   
typedef struct node 
{ 
    int data; 
    struct node *left;
	struct node *right; 
}Node; 
   
// Create New BST node 
Node* newNode(int value) 
{ 
    Node *temp =  (Node *)malloc(sizeof(Node)); 
    temp->data = value; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
// Inorder Traversal of BST 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); 
    } 
} 

// Preorder traversal
void preorderTraversal(Node* node) 
{
    if(node == NULL)
	{
	  return;
	} 
     /* first print data of node */
    printf("%d ", node->data);   
  
     /* then recur on left sutree */
    preorderTraversal(node->left);   
  
     /* now recur on right subtree */
    preorderTraversal(node->right);
}

// Preorder traversal
void postorderTraversal(Node* node) 
{
    if(node == NULL)
	{
	  return;
	}   
  
    postorderTraversal(node->left);   
  
    postorderTraversal(node->right);
    
    printf("%d ", node->data);
}
   
// Insert a new node with given data in BST
Node* insert(Node* node, int data) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL)
	{
	  return(newNode(data));	
	}
  
    /* Otherwise, recur down the tree */
    if (data < node->data) 
        node->left  = insert(node->left, data); 
    else if (data > node->data) 
        node->right = insert(node->right, data);    
  
    /* return the (unchanged) node pointer */
    return(node); 
} 
   
// Driver Program to test above functions 
void main() 
{ 
    
    Node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
   
    
    printf("Pre Order : \n");
    preorderTraversal(root);
    printf("\n");
    
    printf("Inorder : \n");
	inorder(root); 
    printf("\n");
    
    printf("Post Order : \n");
    postorderTraversal(root);
    
} 
