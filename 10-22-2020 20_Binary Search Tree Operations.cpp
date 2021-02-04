#include<stdio.h>
#include<stdlib.h>

void data();
void add();
int search(struct node);
struct node del_node(struct node);
void dis_inorder(struct node);
void dis_postorder(struct node);
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
struct node * minValueNode(struct node* node)
{
	struct node* current = node;
	while(current->left != NULL)
	{
		current = current->left;	
	}
	return current;
}
struct node* del_node(struct node *t,int key)
{
	if(t==NULL)
	{
		return t;
	}
	else if(key<t->data)
	{
		t->left=del_node(t->left,key);
	}
	else if(key>t->data)
	{
		t->right=del_node(t->right,key);
	}
	else 
	{
		if(t->left==NULL)
		{
			struct node *cur=t->right;
			free(t);
			return cur;
		}
		else if(t->right==NULL)
		{
			struct node *cur=t->left;
			free(t);
			return cur;
		}
		struct node* temp = minValueNode(t->right);
		t->data = temp->data;
		t->right = del_node(t->right,temp->data);
	}
	return t;
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
void dis_preorder(struct node *t)
{
	printf("Value of node is:- %d\n",t->data);
	if(t->left)
	{
		dis_preorder(t->left);
	}
	if(t->right)
	{
		dis_preorder(t->right);
	}
}
void dis_postorder(struct node *t)
{
	if(t->left)
	{
		dis_postorder(t->left);
	}
	if(t->right)
	{
		dis_postorder(t->right);	
	}
	printf("Value of node is %d.\n",t->data);
}
int main()
{
	int a,k,m,s;
	while(1)
	{
		printf("1: Choose 1 to enter nodes of BST.\n");
		printf("2: Choose 2 to insert a node in BST.\n");
		printf("3: Choose 3 to display the BST in pre-order.\n");
		printf("4: Choose 4 to display the BST in post-order.\n");
		printf("5: Choose 5 to search a node.\n");
		printf("6: Choose 6 to delete a node.\n");
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
				dis_preorder(root);
				break;
			case 4:
				dis_postorder(root);
				break;
			case 5:
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
			case 6:
				printf("Enter the value you wanna delete.\n");
				scanf("%d",&key);
				s=search(root);
				if(s==0)
				{
					printf("Entered key is not present in the tree.\n");
				}
				else
				{
					del_node(root,key);
					dis_inorder(root);
				}
				break;
			case 7:
				exit(1);
			default:
				printf("Invalid choice.\n");
		}		
	}
}
