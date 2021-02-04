// Closed Hashing --> Open Addressing
//1. Linear Probing
//2. Quadratic Probing
#include<stdio.h>
#include<stdlib.h>

//preprocessor 
#define tablesize 10

//Function Prototypes
void init(); // Initialize Hash Table
void InputKeySpace(); // User Input multiple keys to Hash Table
void DisplayHashTable();  

// Quadratic Probing
void QuadraticProbing(int key);
void QuadraticRemoveKey(int key);
void QuadraticProbSearch(int key);

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
					QuadraticProbing(key);
					printf("\nSuccessfully Inserted %d into the Hash Table!\n",key);
					break;
			case 4: printf("\nEnter key:");
					scanf("%d",&key);
					QuadraticRemoveKey(key);
					break;
			case 5: printf("\nEnter key:");
					scanf("%d",&key);
					QuadraticProbSearch(key);
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
		QuadraticProbing(input[i]);
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

// Hash Function
int HashFunction(int key)
{
	int hx;
	
	hx = key%tablesize;
	
	return(hx);
}

//-----> QuadraticProbing Function Definition
void QuadraticProbing(int key)
{
	int i,hashfun,hx;
	
	for(i=0;i<tablesize;i++)
	{	 
		hx = HashFunction(key);
		hashfun = ((hx+(i*i)) % tablesize);
		if(arr[hashfun]==-1)
		{
			arr[hashfun] = key;
			break;
		}
	}
	printf("\n%d added to the Index %d!\n",key,hashfun);
}

void QuadraticRemoveKey(int key)
{
	int i,hashfun,hx;
	
	for(i=0;i<tablesize;i++)
	{	 
		hx = HashFunction(key);
		hashfun = ((hx+(i*i)) % tablesize);
		
		if(arr[hashfun]==-1)
		{	
			printf("Key doesn't' exist!\n");
			return;
		}
		else if(arr[hashfun]==key)
		{	
			printf("Key found at index %d",hashfun);
			arr[hashfun] = -1;
			int j;
			
			for(j=i+1;j<tablesize;j++)
			{
				hx = HashFunction(key);
				hashfun = ((hx+(j*j)) % tablesize);
				if(arr[hashfun]==-1)
				{
					break;
				}
				else
				{
					int val;
					val = arr[hashfun];
					arr[hashfun]=-1;
					QuadraticProbing(val);
				}
				
			}
			printf("\nSuccessfully Deleted %d Key!\n",key);
			break;
			
		}
	}
	
}


void QuadraticProbSearch(int key)
{
	int i,hashfun,hx;
	
	for(i=0;i<tablesize;i++)
	{	 
		hx = HashFunction(key);
		hashfun = ((hx+(i*i)) % tablesize);
		
		if(arr[hashfun]==-1)
		{	
			printf("Key doesn't' exist!\n");
			return;
		}
		else if(arr[hashfun]==key)
		{
			printf("Key found at index %d",hashfun);
			break;			
			
		}
	}
}
