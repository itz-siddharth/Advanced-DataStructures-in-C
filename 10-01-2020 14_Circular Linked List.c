#include<stdio.h>
#include<stdlib.h>

// Structure 
typedef struct Node{
	int data;
	struct Node *next;	
}Node;

void createList(int n);
void Display();
void Insert();
void Search();
void DeleteNode();
Node* getNode(int data);

Node *head;
Node *tail;

void main()
{	int choice = 1,n ;
	
	head = NULL;
	tail = NULL;
	
	while(choice!=0){
		
		printf("\n\n-----Circular LinkedList Menu Selection-----\n");
        printf("0. Quit\n");
        printf("1. Create Circular LinkedList\n");
        printf("2. Display Circular Linked List\n");
        printf("3. Insert Node\n");
        printf("4. Delete Node\n");
        printf("5. Search Node\n");
        printf("--------------------------------------------------\n");
		printf("Enter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {

            case 0: 
				choice = 0;
            	break;       
            case 1: printf("Enter number of nodes:");
					scanf("%d",&n);
					createList(n);
            	break;
            case 2: Display();
            	break;
            case 3: Insert();
            	break;
            case 4: DeleteNode();
            	break;
            case 5: Search();
            	break;
				
			default:
                printf("Choice you entered is not available [TRY AGAIN]!\n");
				
		}	
	}
}


void createList(int n)
{
    int i, data;
    Node *prevNode, *newNode;

    if(n >= 1)
    {
        head = (Node *)malloc(sizeof(Node));

        printf("Enter data of 1 node: ");
        scanf("%d", &data);

        head->data = data;
        head->next = NULL;

        prevNode = head;

    
        for(i=2; i<=n; i++)
        {
            newNode = (Node *)malloc(sizeof(Node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->next = NULL;

            // Link the previous node with newly created node
            prevNode->next = newNode;

            // Move the previous node ahead
            prevNode = newNode;
        }

        // Link the last node with first node
        prevNode->next = head;
        tail = prevNode;

        printf("\nCIRCULAR LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

void Display() 
{ 
    Node *temp = head;  
      
  	
    // If linked list is not empty 
    if (temp != NULL)  
    { 
        // Keep printing nodes till we reach the first node again 
        do
        { 
            printf("%d ", temp->data); 
            temp = temp->next; 
        } 
        while (temp != head); 
        
    printf("\nHead : %d\n", head->data);
	printf("Tail : %d\n", tail->data);
    } 
    else
    {
    	printf("Empty Linked List!");
	}
}

//-----> getNode Function Definition
Node* getNode(int data){
	Node *newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = data;
	newNode->next = NULL;
	return newNode;	
}

// -----> Insert Function Definition
void Insert(){
	
	int choice,i,loc,val;
	Node *curr = head;
	printf("Enter value: ");
	scanf("%d",&val);
	Node *temp = getNode(val);
	
	printf("1.Insert in the Begining\n");
	printf("2.Insert in the Middle\n");
	printf("3.Insert at the last\n");
	printf("Enter Choice: ");
	scanf("%d",&choice);
	
	if (tail==0)
	{   printf("Enter value: ");
		tail = temp;
		tail->next=temp;		
	}
	
	switch(choice){
		case 1: 	
				temp->next = tail->next;
				tail->next = temp;
				head = temp;
				printf("%d Inserted!\n",tail->next->data);
			break;
		case 2: printf("Enter position: ");
				scanf("%d",&loc);
				for(i=1;i<loc-1;i++){
				curr = curr->next;	
				}
				temp->next = curr->next;
				curr->next = temp;
			break;
		case 3: tail->next = temp;
				tail = temp;
				tail->next = head;	
			break;	
		default:
			printf("Invalid input!");
			
	}
	printf("Successfully Inserted %d in Linked List :)\n",val);
	printf("New! ");
	Display(); 
}
 

// -----> Search Function Definition
void Search(){
	Node *curr = head;
	int val,index=0;
	int flag = 0;
		
	printf("Enter node:");
	scanf("%d",&val);

	printf("Finding node %d.....\n",val);
	while(curr->next!=head){
		if(curr->data == val){
			printf("[%d] == [%d]\n",curr->data,val);
			flag = 1;
			index = index + 1;  
			break;
		}
		else{
			printf("[%d] != [%d]\n",curr->data,val);
			curr = curr->next;
			index = index + 1; 
		}
	}
	if(curr->data == val)
	{
		printf("[%d] == [%d]\n",curr->data,val);
			flag = 1;
	}
	else
	{
		printf("[%d] != [%d]\n",curr->data,val);
	}
	
	if(flag==1){
		printf("\nNode %d is present at %dth position!\n",val,index);
	}else{
		printf("\nOps! Node not found.\n");
	}		
}


void DeleteNode(){	

	int choice,i,ele;
	Node *curr = head;
	
	printf("1.Delete from the Begining\n");
	printf("2.Delete from the Middle\n");
	printf("3.Delete from the last\n");
	printf("Enter Choice: ");
	scanf("%d",&choice);
	
	switch(choice){
		case 1: head = head->next;
				tail->next = head;
				break;
		case 2: printf("Enter node to delete: ");
				scanf("%d",&ele);
				
				Node *prev = curr;
				while(curr!=NULL)
				{	
					if(curr->data == ele)
					{	
						prev->next = curr->next;
						break;		
					}
					else
					{	
						prev=curr;
						curr=curr->next;
						
					}
				}
				
				break;
		case 3: while(curr->next->next!=head)
				{
				  curr = curr->next;
				}
				curr->next = head;	
				tail = curr;
			break;	
		default:
			printf("Invalid input!");
			
	}
	printf("Successfully Deleted %d in Linked List :)\n",ele);
	printf("New!");
	Display(); 
}
