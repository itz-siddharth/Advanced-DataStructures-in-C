// Double Hashing
#include<stdio.h>
#include <stdlib.h> // just for exit(0)

//preprocessor 
#define tablesize 11

//Function Prototypes
void init(); // Initialize Hash Table
void InputKeySpace(); // Input multiple keys to Hash Table
void DisplayHashTable();  // Display 
void DoubleHashing(int key); // Double Hashing
int Prime(int value);

void DoubleHashRemoveKey(int key);
void DoubleHashSearch(int key);

// Hash Function
int HashFunction(int key);

int arr[tablesize];

void main()
{	int choice,key;

	init();//initialize array 
	
	while(1)
	{	
		printf("\n\n-----Implementation of Double Hashing-----\n");
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
			case 3:	printf("\nEnter Key:");
					scanf("%d",&key);
					DoubleHashing(key);
					break;
			case 4: printf("\nEnter key:");
					scanf("%d",&key);
					DoubleHashRemoveKey(key);
					break;
			case 5: printf("\nEnter key:");
					scanf("%d",&key);
					DoubleHashSearch(key);
					break;
			default:
                printf("Choice you entered is not available [TRY AGAIN]!\n");
					
		}		
	}
	
}

//-----> init Function Definition
void init()
{	int i,BigPrime;
	for(i=0;i<tablesize;i++)
	{	
		arr[i] = -1;
	}
	printf("HashTable Size: %d\n",tablesize);	
	BigPrime = Prime(tablesize);
	printf("Biggest prime smaller than tablesize %d\n",BigPrime);
}

//-----> InputKeys Function Definition
void InputKeySpace()
{
//	int input[10] = {23,34,27,43,44,78,0,45,65,75}; 
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
		DoubleHashing(input[i]);
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

// Hash Function
int HashFunction(int key)
{
	int hx;
	
	hx = key%tablesize;
	
	return(hx);
}

// Double Hashing
void DoubleHashing(int key){
	
	int i,hashfun;
	int BigPrime;
	
	BigPrime = Prime(tablesize);
    //printf("Biggest prime smaller than tablesize %d\n",BigPrime);
	for(i=0;i<tablesize;i++)
	{	
		int hx_1 = HashFunction(key);
		int hx_2 = BigPrime-(key%BigPrime);
		hashfun = ((hx_1+(i*hx_2)) % tablesize);
		if(arr[hashfun]==-1)
		{
			arr[hashfun] = key;
			printf("Saved at %d position\n",hashfun);
			break;
		}
	
	}
}

int Prime(int value)
{
	int BigPrime,i,j;
	//// Biggest Prime smaller than tablesize
    for(i=2;i<tablesize;i++)
    {
        int c=0;
        for(j=1;j<=i;j++)
        {
            if(i%j==0)
            {
                c++;
            }
        }
         
       if(c==2)
        {
            BigPrime = i;

        }
    }
    //printf("Biggest prime smaller than tablesize %d\n",BigPrime);
    return(BigPrime);
}



void DoubleHashRemoveKey(int key)
{
	int i,hashfun;
	int BigPrime;
	
	BigPrime = Prime(tablesize);
	
	for(i=0;i<tablesize;i++)
	{	 
		
		int hx_1 = HashFunction(key);
		int hx_2 = BigPrime-(key%BigPrime);
		hashfun = ((hx_1+(i*hx_2)) % tablesize);
				
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
				int hx_1 = HashFunction(key);
				int hx_2 = BigPrime-(key%BigPrime);
				hashfun = ((hx_1+(i*hx_2)) % tablesize);
				if(arr[hashfun]==-1)
				{
					break;
				}
				else
				{
					int val;
					val = arr[hashfun];
					arr[hashfun]=-1;
					DoubleHashing(val);
				}
				
			}
			printf("\nSuccessfully Deleted %d Key!\n",key);
			break;
			
		}
	}
	
}


void DoubleHashSearch(int key)
{
	int i,hashfun;
	int BigPrime;
	
	BigPrime = Prime(tablesize);
	
	for(i=0;i<tablesize;i++)
	{	 
		int hx_1 = HashFunction(key);
		int hx_2 = BigPrime-(key%BigPrime);
		hashfun = ((hx_1+(i*hx_2)) % tablesize);
		
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

