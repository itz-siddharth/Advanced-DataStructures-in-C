//15.	Implement all the functions of a dictionary (ADT) using hashing.  
//Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys must be unique  
//Standard Operations: Insert (key, value), Find (key), Delete (key) 

#include<stdio.h>
#include<stdlib.h>

//preprocessor 
#define SIZE 10

int hashArray[SIZE];

struct DataItem {
   char data[10];   
   int key;
};

int hashCode(int key){
   return(key%SIZE);
}

//-----> init Function Definition
void init()
{	int i;
	for(i=0;i<SIZE;i++)
	{	
		hashArray[i] = -1;
	}	
	printf("HashTable Size: %d\n",SIZE);
}

//-----> DisplayHashTable Function Definition
void DisplayHashTable()
{
	int i;
	printf("\n-----Hash Table-----\n");
	for(i=0;i<SIZE;i++)
	{	
		printf("hashArray[%d] = %d\n",i,hashArray[i]);	
	}	
	printf("\n");
}

void insert(int key,char data[]) {
   struct DataItem *item = (struct DataItem*)malloc(sizeof(struct DataItem));
   strcpy(item->data, data); 
   item->key = key;     

   
   //get the hash 
   int hashIndex = hashCode(key); 
  	
	int i;
   //move in array until an empty or deleted cell
   for(i=0;i<SIZE;i++)
	{	
		if(hashArray[hashIndex]==-1)
		{
			hashArray[hashIndex] = item;
			break;
		}
		else{
			 ++hashIndex;
			  continue;
		}
	}
   
   struct DataItem *temp = (struct DataItem*)malloc(sizeof(struct DataItem));
   temp = hashArray[hashIndex];
   printf("Stored Successfully Key: %d Data: %s\n",temp->key,temp->data);     
}

struct DataItem* Delete(int key) {

   //get the hash 
   int hashIndex = hashCode(key);
   struct DataItem *item = (struct DataItem*)malloc(sizeof(struct DataItem));
   
   printf("\nDeletion in progress! Key: %d",key);
	int flag=0;
   //move in array until an empty 
   while(hashArray[hashIndex] !=NULL) {
   		
   		item = hashArray[hashIndex];
	
      if(item->key == key) {	
         //assign a dummy item at deleted position
         hashArray[hashIndex] = -1; 
         printf("\n|Deletion Sucessful !|\n");	
         int j = hashIndex;
		 while(hashArray[j+1] != -1){
         		
      		hashArray[j] = hashArray[j+1];
      		hashArray[j+1]=-1;
      		++j;
		 }
         
         return ;
      }
      else{
      	//go to next cell
      ++hashIndex;
      continue;
	  }
   }  
	if(flag==0)
	{
		printf("\nKey %d not found!\n",key);
	}
		
}

void search(int key) {
   //get the hash 
   int hashIndex = hashCode(key);
   int flag=0;
   
   struct DataItem *item = (struct DataItem*)malloc(sizeof(struct DataItem));
   
   //move in array until an empty 
   while(hashArray[hashIndex] != -1) {
	
	item = hashArray[hashIndex];
	if(item->key == -1){
		printf("Key not found!");
	}
    else if(item->key == key)
         {
         	printf("Data for Key : %d is : %s\n",item->key,item->data);
         	flag = 1;
         	break;
		 }
			
      else{
      	//go to next cell
      ++hashIndex;
      continue;
	  }
	}
	if(flag==0){
		printf("\nKey %d not found!\n",key);
	}
	
}

void main(){
	init();
	DisplayHashTable();
	
	insert(123,"Ram");
	insert(100,"Lakshmana");
	insert(250,"Bharata ");
	
	DisplayHashTable();
	
	search(100);
	search(550);
	
	Delete(100);
	DisplayHashTable();
	
	search(123);
	search(100);
	search(250);
}
