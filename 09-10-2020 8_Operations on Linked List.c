#include<stdio.h>
#include<stdlib.h>

// Structure 
typedef struct Node{
	int data;
	struct Node *next;	
}Node;

//Function Prototype
Node* getNode(int data);
Node* CreateLinkedList(Node *head); // Create Linked List via input 
void Display(Node *ptr); // Display Linked List 
Node* Insert(Node *head); // Insert Begining,Middle,Last
void Search(Node *head); // Search the Linked List
int Get(Node *head,int loc);  // Get node by position 
void Min(Node *head); // Minimum node
void Max(Node *head); // Maximum node 
Node* Reverse(Node *head); // Reverse of Linked List
Node* Rotate(Node *head); // Rotate Linked List
int lengthRecursive(Node *head); // Return size of Linked List
Node* RotateRight(Node *head,int k); // Rotate Right by k nodes 
Node* DeleteNode(Node* head); // Delete Begining,Middle,Last

// Main Program
void main(){
	
	int loc,get_node,get_size;
	int choice = 1;
	Node *head = NULL;
	
	while(choice!=0){
		
		printf("\n\n-----Menu Selection-----\n");
        printf("0. Quit\n");
        printf("1. Create LinkedList\n");
        printf("2. Display Linked List\n");
        printf("3. Insert Node\n");
        printf("4. Search Node\n");
        printf("5. Get Node\n");
        printf("6. Min Node\n");
        printf("7. Max Node\n");
        printf("8. Reverse Linked List\n");
        printf("9. Rotate Linked List\n");
        printf("10. Size of Linked List\n");
        printf("11. Delete node\n");
        printf("-------------------------\n");
		printf("Enter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {

            case 0: 
				choice = 0;
            	break;       
            case 1:
				head = CreateLinkedList(head);
				printf("\nSuccessfully created Linked List!!!!\n");
            	break;
			case 2:
				Display(head);
				break;
			case 3:
				head = Insert(head);
				break;
			case 4:
				Search(head);
				break;
			case 5: 
					printf("\nEnter position:");
					scanf("%d",&loc);
					get_node = Get(head,loc);
					printf("Value Returned = %d",get_node);
				break;
			case 6: Min(head);
				break;
			case 7: Max(head);
				break;
			case 8: head = Reverse(head);
				break;
			case 9: head = Rotate(head);
				break;
			case 10: get_size = lengthRecursive(head);
					 printf("\nLinked List have %d nodes",get_size);
				break;
			case 11: head = DeleteNode(head);
				break;
			default:
                printf("Choice you entered is not available [TRY AGAIN]!\n");
				
		}	
	}
}

//-----> getNode Function Definition
Node* getNode(int data){
	Node *newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = data;
	newNode->next = NULL;
	return newNode;	
}


//-----> CreateLinkedList Function Definition
Node* CreateLinkedList(Node *head){
	int i,n,data;
	
	Node *tail;
	Node *temp;
	printf("\nEnter number of nodes:");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{	
		printf("Enter node %d: ",i);
		scanf("%d",&data);
		temp = getNode(data);
		if(head==NULL)
		{
			head = temp;
		}
		else
		{
			tail->next = temp;	
		}
		tail = temp;
		Display(head);
		printf("\n");
	}
	
	return head;	
}

//-----> Display Function Definition
void Display(Node *ptr)
{	
	if(ptr == NULL)
	{	
		printf("Empty linked List!\n");
	}
	else
	{
		printf("\nLinked List : ");

		while(ptr->next != NULL) { //iterating over linked list
		printf("%d->",ptr->data);
	    ptr = ptr->next;
	     
		 }
	 	 printf("%d->",ptr->data);
	  	printf("NULL");
	}
}

// -----> Insert Function Definition
Node* Insert(Node *head){
	
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
	
	switch(choice){
		case 1: temp->next = head;
				head = temp;
			break;
		case 2: printf("Enter position: ");
				scanf("%d",&loc);
				for(i=1;i<loc-1;i++){
				curr = curr->next;	
				}
				temp->next = curr->next;
				curr->next = temp;
			break;
		case 3: while(curr->next!=NULL){
				curr = curr->next;
				}
				curr->next = temp;	
			break;	
		default:
			printf("Invalid input!");
			
	}
	printf("Successfully Inserted %d in Linked List :)\n",val);
	printf("New! ");
	Display(head); 
	return head;
}

// -----> Search Function Definition
void Search(Node *head){
	Node *curr = head;
	int val,index=0;
	int flag = 0;
		
	printf("Enter node:");
	scanf("%d",&val);

	printf("Finding node %d.....\n",val);
	while(curr!=NULL){
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
	
	if(flag==1){
		printf("\nNode %d is present at %dth position!\n",val,index);
	}else{
		printf("\nOps! Node not found.\n");
	}		
}

// -----> Get Function Definition
int Get(Node *head,int loc){
	
	Node *curr = head;
	int i,len;
	int flag = 0;

	printf("Finding node at %dth position.....\n",loc);
	len = lengthRecursive(head);
	if(loc<=len)
	{		
		for(i=0;i<loc-1;i++)
		{	
		curr = curr->next;	
		}
		return(curr->data);
	}
	else
	{
		printf("\nPosition greater than Linked List size!\n");
		printf("No value returned!\n");
	}
}

// -----> Min Function Definition
void Min(Node *head){
	
	Node *curr = head;
	int min = curr->data;
	curr = curr->next;
	
	printf("\nFinding minimum node.....\n");
	while(curr!=NULL){
		if(curr->data < min){
			min = curr->data;
			curr = curr->next;
		}
		else{
			curr = curr->next;
		}
	}
	printf("Minimum Node: %d",min);
}

// -----> Max Function Definition
void Max(Node *head){
	
	Node *curr = head;
	int max = curr->data;
	curr = curr->next;
	
	printf("\nFinding maximum node.....\n");
	while(curr!=NULL){
		if(curr->data > max){
			max = curr->data;
			curr = curr->next;
		}
		else{
			curr = curr->next;
		}
	}
	printf("Maximum Node: %d",max);
}

// -----> Reverse Function Definition
Node* Reverse(Node *head){
	
	Node *curr = head;
    Node *prev = NULL;
    Node *next;
    while(curr!=NULL){
    	next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
	}
    head = prev;
    return(prev);
	
}

// -----> Rotate Function Definition
Node* Rotate(Node *head){
	
	Node *curr = head;
	int choice,k,count =1;
	int i,j;
	
	printf("\nEnter number of nodes to rotate: ");
	scanf("%d",&k);
	if(k==0){
		return head;
	}
	
	printf("\n1.Clockwise\n");
	printf("2.Counter-Clockwise\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:	
				head = RotateRight(head,k);
				Display(head);
				return head;
		case 2:
			while(count<k && curr!=NULL)
				{
					curr = curr->next;
					count = count + 1; 	
				}
				if(curr==NULL){
					return head;
				}
				
				Node *KthNode = curr;
				
				while(curr->next !=NULL){
					curr = curr->next;
				}
				
				curr->next = head;
				head = KthNode->next;
				KthNode->next = NULL;
				Display(head);
				return head; 
			
	}
}

Node* RotateRight(Node *head,int k){

  
    // len is used to store length of the linked list 
    // tmp will point to the last node after this loop 
    Node* tmp = head; 
    int len = 1; 
    while(tmp->next != NULL) 
	{ 
        tmp = tmp->next; 
        len++; 
    } 
  
    // If k is greater than the size of the linked list 
    if(k > len){
    	printf("Rotation greater than size");
    	return head;
	}  
  
    // If no rotation needed then return the head node 
    if (k == 0 || k == len) 
        return head; 
  
    // current will either point to 
    // kth or NULL after this loop 
    Node *current = head; 
    int cnt = 1; 
    while (cnt < k && current != NULL) { 
        current = current->next; 
        cnt++; 
    } 
  
    // If current is NULL then k is equal to the 
    // count of nodes in the list 
    // Don't change the list in this case 
    if (current == NULL) 
        return head; 
  
    // current points to the kth node 
    Node *kthnode = current; 
    
    tmp->next = head; // Change next of last node to previous head
    head = kthnode->next; // Change head to (k+1)th node 
    kthnode->next = NULL; // Change next of kth node to NULL 
    return head; // Return the updated head pointer 
}

int lengthRecursive(Node *head){
    if(head->next == NULL)
		{
    	return 1; 	
		}
    return 1 + lengthRecursive(head->next);
}

Node* DeleteNode(Node* head){	

	int choice,i,ele;
	Node *curr = head;
	
	printf("1.Delete from the Begining\n");
	printf("2.Delete from the Middle\n");
	printf("3.Delete from the last\n");
	printf("Enter Choice: ");
	scanf("%d",&choice);
	
	switch(choice){
		case 1: head = head->next;
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
		case 3: while(curr->next->next!=NULL)
				{
				  curr = curr->next;
				}
				curr->next = NULL;	
			break;	
		default:
			printf("Invalid input!");
			
	}
	printf("Successfully Deleted %d in Linked List :)\n",ele);
	printf("New!");
	Display(head); 
	return head;
}
