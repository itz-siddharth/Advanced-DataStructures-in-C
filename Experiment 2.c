#include<stdio.h>
#include<stdlib.h>
void data();
void add();
int search(struct node);
void min_val(struct node);
void dis_inorder(struct node);
int maxDepth(struct node);
void mirror(struct node);
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;
int n,key;
void data()
{
	printf("Enter the number of nodes present in BST.\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		struct node *temp,*parent;
		printf("Enter the value of node.\n");
		scanf("%d",&key);
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=key;
		temp->left=temp->right=NULL;
		parent=root;
		if(root==NULL)
		{
			root=temp;
		}
		else
		{
			struct node *cur=root;
			while(cur)
			{
				parent=cur;
				if(temp->data>cur->data)
				{
					cur=cur->right;
				}
				else
				{
					cur=cur->left;
				}
			}
			if(temp->data>parent->data)
			{
				parent->right=temp;
			}
			else
			{
				parent->left=temp;
			}
		}
	}
}
int search(struct node *t)
{
	if(t==NULL)
	{
		return 0;
	}
	else if(t->data==key)
	{
		return 1;
	}
	else if(t->data>key)
	{
		return search(t->left);
	}
	else
	{
		return search(t->right);
	}
}
void min_val(struct node *t)
{
	struct node *cur=t;
	while(cur->left!=NULL)
	{
		cur=cur->left;
	}
	printf("The minimum value present in the tree is %d.\n",cur->data);
}
void add()
{
	int s,k;
	printf("Enter the value of new node.\n");
	scanf("%d",&key);
	s=search(root);
	if(s==1)
	{
		printf("Item can't be inserted as BST can't have duplicate elements.\n");
	}
	else
	{
		struct node *temp,*parent,*cur;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=key;
		temp->left=temp->right=NULL;
		parent=cur=root;
		while(cur)
		{
			parent=cur;
			if(temp->data>cur->data)
			{
				cur=cur->right;
			}
			else
			{
				cur=cur->left;
			}
		}
		if(temp->data>parent->data)
		{
			parent->right=temp;
		}
		else
		{
			parent->left=temp;
		}	
	}
}
void dis_inorder(struct node *t)
{
	if(t->left)
	{
		dis_inorder(t->left);
	}
	printf("Value of node is:- %d\n",t->data);
	if(t->right)
	{
		dis_inorder(t->right);
	}
}
void mirror(struct node *temp)
{
	if(temp == NULL)
	  {
	   	return;
	  }
	  else
	  {
		   node *ptr;
		   mirror(temp->left);
		   mirror(temp->right);
		   ptr = temp->left;
		   temp->left = temp->right;
		   temp->right = ptr; 
	  }
 }
int maxDepth(struct node *temp) 
{
  if (temp==NULL) 
  {
    return(0);
  }
  else 
  {
    // compute the depth of each subtree
    int lDepth = maxDepth(temp->left);
    int rDepth = maxDepth(temp->right);
    // use the larger one
    if (lDepth > rDepth) 
		return (lDepth+1);
    else 
		return (rDepth+1);
  }
}
int main()
{
	int a,k,m,s,d;
	while(1)
	{
		printf("1: Choose 1 to enter nodes of BST.\n");
		printf("2: Choose 2 to insert a node in BST.\n");
		printf("3: Choose 3 to search a node.\n");
		printf("4: Choose 4 to find the min value present in the tree.\n");
		printf("5: Choose 5 to swap the left and right pointer.\n");
		printf("6: Choose 6 to calculate the number of nodes in longest path.\n");
		printf("7: Quit.\n");
		printf("Enter your choice.\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				data();
				dis_inorder(root);
				break;
			case 2:
				add();
				dis_inorder(root);
				break;
			case 3:
				printf("Enter the key to be searched.\n");
				scanf("%d",&key);
				s=search(root);
				if(s==1)
				{
					printf("Item is present.\n");
				}
				else
				{
					printf("Item not present.\n");
				}
				break;
			case 4:
				min_val(root);
				break;
			case 5:
				mirror(root);
				dis_inorder(root);
				break;
			case 6:
				d=maxDepth(root);
				printf("Number of nodes in the longest path is: %d\n",d);
				break;
			case 7:
				exit(1);
			default:
				printf("Invalid choice.\n");
		}		
	}
}
