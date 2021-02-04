// Closed Hashing --> Open Addressing
//1. Linear Probing
//2. Quadratic Probing

#include<stdio.h>
#include<stdlib.h>

//preprocessor 
#define tablesize 20

//Function Prototypes
void init(); // Initialize Hash Table
void InputKeySpace(); // User Input multiple keys to Hash Table
void DisplayHashTable();  
// Linear Probing
void LinearProbing(int key);
void LinearRemoveKey(int key);
void LinearProbSearch(int key);


// Hash Function
int HashFunction(int key);

int arr[tablesize];

void main()
{	int choice,key;

	init();//initialize array 
	
	while(1)
	{	
		printf("\n\n-----Implementation of Closed Hashing-----\n");
		printf("0. Exit\n");
		printf("1. Input Key Space\n");	
		printf("2. Display Hash Table\n");	
		printf("3. Insert a key to Hash Table\n");
		printf("4. Delete a key from Hash Table\n");
		printf("5. Search a Key\n");			
		printf("-----------------------------------------\n");
		printf("Enter choice:");
		scanf("%d", &choice);
		printf("\n");
        
		switch(choice)
		{	case 0: exit(0);
		
			case 1: InputKeySpace();
					break;	
			case 2:	DisplayHashTable();
					break;
			case 3: printf("\nEnter Key:");
					scanf("%d",&key);
					LinearProbing(key);
					break;
			case 4: printf("\nEnter key:");
					scanf("%d",&key);
					LinearRemoveKey(key);
					break;
			case 5: printf("\nEnter key:");
					scanf("%d",&key);
					LinearProbSearch(key);
					break;
			default:
                printf("Choice you entered is not available [TRY AGAIN]!\n");
					
		}		
	}
	
}

//-----> init Function Definition
void init()
{	int i;
	for(i=0;i<tablesize;i++)
	{	
		arr[i] = -1;
	}	
	printf("HashTable Size: %d\n",tablesize);
}

//-----> InputKeys Function Definition
void InputKeySpace()
{ 
	int i,n,choice;
	printf("Table size is %d\n",tablesize);
	printf("Enter number of keys to map:");
	scanf("%d",&n);
	
	// Input Keys
	int input[n];
	for(i=0;i<n;i++)
	{
		printf("Enter key %d:",i+1);
		scanf("%d",&input[i]);
	}  
	
	
	for(i=0;i<n;i++)
	{
		LinearProbing(input[i]);
		printf("\n%d added to the Hash Table!\n",input[i]);
	}
		
}

//-----> DisplayHashTable Function Definition
void DisplayHashTable()
{
	int i;
	printf("\n-----Hash Table-----\n");
	for(i=0;i<tablesize;i++)
	{	
		printf("arr[%d] = %d\n",i,arr[i]);	
	}	
	printf("\n");
}

// Linear Hash Function
int HashFunction(int key)
{
	int hx;
	
	hx = key%tablesize;
	
	return(hx);
}
//-----> LinearProbing Function Definition
void LinearProbing(int key)
{
	int i,hashfun,hx;
	
	for(i=0;i<tablesize;i++)
	{	
		hx = HashFunction(key);
		hashfun = ((hx+i) % tablesize);
		if(arr[hashfun]==-1)
		{
			arr[hashfun] = key;
			break;
		}
	}
}



void LinearRemoveKey(int key)
{
	int i,hashfun;
	
	hashfun = HashFunction(key);

	if(arr[hashfun]==-1)
	{	
		printf("Key doesn't' exist!\n");
		return;
	}
	else
	{	int j = hashfun;
		int k;
		for(i=0;i<tablesize;i++)
		{	
			
			if(arr[j]==-1)
			{	
				printf("Key doesn't' exist!\n");
				return;
			}
			
			if(arr[j]==key)
			{
				
				arr[j] = -1;
				printf("Key Deleted Successfully!\n");
				
		//		 Remove farward elements and rehash them
				for(k=j+1;k<tablesize;k++)
				{
					if(arr[k]==-1)
					{
						break;
					}
					else
					{	
						int val;
						val = arr[k];
						arr[k]=-1;
						LinearProbing(val);
						
					}
				}
				break;
			}
			
			j=j+1;
			
   		}
		
   }

}


void LinearProbSearch(int key)
{
	int i,hashfun;
	
	hashfun = HashFunction(key);

	if(arr[hashfun]==-1)
	{	
		printf("Key doesn't' exist!\n");
		return;
	}
	else
	{
		int j = hashfun;
		int k;
		for(i=0;i<tablesize;i++)
		{	
			
			if(arr[j]==-1)
			{	
				printf("Key doesn't' exist!\n");
				break;
			}
			
			if(arr[j]==key)
			{
				
				printf("Key Found at position %d\n",j);
				break;
			}
		}
	}
}
