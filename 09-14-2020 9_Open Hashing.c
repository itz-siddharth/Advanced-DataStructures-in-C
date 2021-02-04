// Open Hashing --> Chaining  
#include<stdio.h>
#include<stdlib.h>

//preprocessor 
#define tablesize 20

// Structure 
typedef struct Node{
	int data;
	struct Node *next;	
}Node;

//Function Prototypes
void init(); //initialize chain with NULL Heads
Node* getNode(int data); // Returns node with data in it 
void DisplayChain(); // Display Chain
void InputKeys(); // Input example keys to Hash Table
void InsertToHashTable(int value);  // Insert key to Hash Table
void SearchKey(int value); // Search Key
void DeleteKey(int value); // Delete Key
int HashFunction(int key);

Node *chain[tablesize]; // Array of linked list,size of hashtable

//Main Function
void main()
{	int choice,key,n;
	
	init();
	
	while(1)
	{	
		printf("\n\n-----Implementation of Chain Hashing-----\n");
		printf("0. Exit\n");
		printf("1. Input Example Key Space {23,34,27,43,44,78,0,45,65,75}\n");	
		printf("2. Display Chain\n");	
		printf("3. Insert multiple keys to Hash Table (User Input)\n");	
		printf("4. Search Key\n");
		printf("5. Delete Key\n");
		printf("-----------------------------------------\n");
		printf("Enter choice:");
		scanf("%d", &choice);
		printf("\n");
        
		switch(choice)
		{	case 0: exit(0);
		
			case 1: InputKeys();
					break;	
			case 2:	DisplayChain();
					break;
			case 3: printf("Enter number of keys:");
					scanf("%d",&n);
					int i;
					for(i=0;i<n;i++)
					{
						printf("\nEnter Key %d:",i+1);
						scanf("%d",&key);
						InsertToHashTable(key);
					}
					break;
			case 4: printf("\nEnter Key:");
					scanf("%d",&key);
					SearchKey(key);
					break;
			case 5 :printf("\nEnter Key:");
					scanf("%d",&key);
					DeleteKey(key);
					break;
			default:
                printf("Choice you entered is not available [TRY AGAIN]!\n");
					
		}		
	}
			
}

//-----> init Function Definition
void init(){
	
	int i;
	for(i = 0;i<tablesize;i++)
	{		
		chain[i] = NULL;	
	}	
	printf("HashTable Size: %d\n",tablesize);
}


//-----> getNode Function Definition
Node* getNode(int data){
	Node *newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = data;
	newNode->next = NULL;
	return newNode;	
}

//-----> DisplayChain Function Definition
void DisplayChain()
{
	int i;
		
	for(i=0;i<tablesize;i++)
	{
		Node *temp = chain[i];
		printf("chain[%d]-->",i);
		while(temp)
		{
			printf("%d-->",temp->data);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

//-----> InputKeys Function Definition // Example Keys
void InputKeys()
{
	int arr[10] = {23,34,27,43,44,78,0,45,65,75};
	int i;
	
	for(i=0;i<10;i++)
	{
		InsertToHashTable(arr[i]);
		printf("\n%d added to the Hash Table!\n",arr[i]);
	 } 
}

//-----> Insert Function Definition
int HashFunction(int key)
{
	return(key % tablesize);
}

//-----> Insert Function Definition
void InsertToHashTable(int value)
{	
	//create newNode with value
	Node *newNode = getNode(value);
	int i;
	
	//calculate hash key
	int key = HashFunction(value);
	
	//check if chain[key] is empty or not
	if(chain[key]==NULL || chain[key]->data>=newNode->data)
	{
		newNode->next = chain[key];
		chain[key] = newNode;
		
	} 
	else
	{	
		Node *current = chain[key]; 
        while (current->next != NULL && current->next->data < newNode->data) { 
            current = current->next; 
        } 
        newNode->next = current->next; 
        current->next = newNode;
	}
}

void SearchKey(int value)
{
	int key = value % tablesize;
	
	Node *temp = chain[key];
	
	while(temp!=NULL)
	{
		if(value<=temp->data || temp->next!=NULL)
		{
			if(value==temp->data)
			{
				printf("Key is present at %d index!",key);
				break;
			}
		}
		else
		{
			printf("Key is not present!\n");
			break;
		}
		temp=temp->next;
	}
	if(temp==NULL)
	{
		printf("Key not present!\n");
	}
	
}

void DeleteKey(int value)
{
	int key = value % tablesize;
	
	Node *temp = chain[key];
	
	if(temp->data == value)
	{
		chain[key] = temp->next;
		printf("Deleted %d Successfully!",value);
		return;
	}
	Node *prev = temp;
	while(temp!=NULL)
	{	
		if(temp->data == value)
		{	
			prev->next = temp->next;
			printf("Deleted %d Successfully!",value);
			break;		
		}
		else
		{	
			prev=temp;
			temp=temp->next;
			
		}
	}
	
}
