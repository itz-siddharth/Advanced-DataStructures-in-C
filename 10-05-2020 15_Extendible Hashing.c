#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct bucket{
	int keys[3];
	int local_depth;
};
typedef struct bucket bucket;

struct tableElement{	
	struct tableElement* next;
	bucket* buck;
	int name[];
};
typedef struct tableElement tE;

int global_depth;

tE* manageViolation(bucket* buck, tE* first,int num,int size,int bsize);

int* decToBin(int num,int size){
	int i,temp;
	int* bin=(int*)calloc(size,sizeof(int));
	for(i=size-1;i>=0;i--){
		bin[i]=num%2;
		num=num/2;
	}
	return bin;
}

void displn(){
	printf("\n-------------------------\n");
}

void display(tE* first,int bsize,int size){
	int i;
	int gdepth = global_depth; //legacy code optimization
	tE* temp=first;
	displn();
	printf("Global depth = %d\n",gdepth);
	while(temp->next!=NULL){
		for(i=0;i<size;i++){
			printf("%d",temp->name[i]);
		}
		printf("-->");
		if(temp->buck!=NULL){
			for(i=0;i<bsize;i++){
				printf("[ %d ]",temp->buck->keys[i]);
			}
			printf("[local depth = %d]",temp->buck->local_depth);
		}else if(temp->buck==NULL){
			printf("NULL");
		}
		printf("\n");
		temp=first->next;
		first=temp;
	}
	for(i=0;i<size;i++){
			printf("%d",temp->name[i]);
		}
		printf("-->");
		if(temp->buck!=NULL){
			for(i=0;i<bsize;i++){
				printf("[ %d ]",temp->buck->keys[i]);
			}
			printf("[local depth = %d]",temp->buck->local_depth);
		}else if(temp->buck==NULL){
			printf("NULL");
		}
		printf("\n");
	displn();
}

tE* createNewTableElement(tE* next,bucket* b,int* name, int name_size){
	int i;
	tE *newtE=(tE*)malloc(sizeof(tE)+(sizeof(int)*name_size));
	newtE->next=next;
	newtE->buck=b;
	for(i=0;i<name_size;i++){
		newtE->name[i]=name[i];
	}
	return newtE;
}

bucket* createNewBucket(int bucket_size,int depth){
	int i;
	bucket *newBucket=(bucket*)malloc(sizeof(bucket));
	for(i=0;i<bucket_size;i++){
		newBucket->keys[i]=0;
	}
	newBucket->local_depth=depth;
}

tE* addNewKey(tE* first, int num, int size,int bsize){
	tE* temp=first;
	tE* temp2=first;
	int flag,i,isBucketFull;
	int *bin=(int*)calloc(size,sizeof(int));
	bin=decToBin(num,size);
	
	while(temp->next!=NULL){
		flag=1;	
		for(i=size-1;i>=size-temp->buck->local_depth;i--){
				if(temp->name[i]!=bin[i]){
					flag=0;
					break;
				}	
		}
		if(flag==1){
			isBucketFull=1;
			for(i=0;i<bsize;i++){
				if(temp->buck->keys[i]==0){
					temp->buck->keys[i]=num;
					isBucketFull=0;
					break;
				}
			}
			if(isBucketFull==1){
				printf("BUCKET FULL");
				manageViolation(temp->buck,first,num,size,bsize);
			}
			break;
		}else{
			temp=temp2->next;
			temp2=temp;
		}
	}
	if(temp->next==NULL){
		flag=1;	
		for(i=size-1;i>=size-temp->buck->local_depth;i--){
			if(temp->name[i]!=bin[i]){
					flag=0;
					break;
				}	
		}
		if(flag==1){
			for(i=0;i<bsize;i++){
					if(temp->buck->keys[i]==0){
					temp->buck->keys[i]=num;
					break;
				}
			}
		}
	}
	return first;
	
}

int binToDec(tE* table, int size){
	int i;
	int ret=0;
	for(i=0;i<size;i++){
		ret=ret+((2^i)*table->name[i]);
	}
	return ret;
}

void dispName(tE* table, int size){
	int i;
	printf("\n");
	for(i=0;i<size;i++){
		printf("%d",table->name[i]);
	}
	printf("\n");
}

int compareLSB(tE* one, tE* two, int size,int depth){ //compare lsb of two nodes names (binary rep.) 
	int i;
	int ret=1;
	for(i=size-1;i>=size-depth;i--){
		if(one->name[i]!=two->name[i]){
			ret=0;
			break;
		}
	}
	if(ret==1){
	}
	return ret;
}

tE* manageViolation(bucket* buck, tE* first,int num,int size,int bsize){
	//printf("\nMANAGING VIOLATION");
	buck->local_depth=buck->local_depth+1;
	int tableSize,i,j,k,l,isPresent,flag;
	int globalDepthIncreased=0;
	int *bin;
	tE* temp=first; 
	tE* temp2;
	tE* temp3;
	bucket* b;
	int *tempArray=(int*)calloc(bsize,sizeof(int));
	
	if(global_depth<buck->local_depth){//code below manages violation if global depth < local depth, meaning we need to double the table
		global_depth=global_depth+1;
		tableSize=1;//bcoz there is no 2^power function in c, and pow function uses double and not int, might cause problem
		globalDepthIncreased=1;//to classify if the violation was because small table size or small bucket size
	}
		for(j=0;j<global_depth;j++){
			tableSize=tableSize*2; //now calculate table size using loops
		}
		
		if(globalDepthIncreased==1){
			while(temp->next!=NULL){
				temp=temp->next;
			}
			for(i=(tableSize/2);i<tableSize;i++){
				temp->next=createNewTableElement(NULL,NULL,decToBin(i,size),size);
				temp=temp->next;		
			}
			//link the newly created elements with respective buckets
		temp = first;
		temp2= first;
		for(i=0;i<tableSize/2;i++){
			temp=temp->next;
		}
		for(i=0;(i<tableSize/2);i++){
			
			temp = first;
			for(l=0;l<tableSize/2;l++){
				temp=temp->next;
			}
			for(j=tableSize/2;j<tableSize;j++){
				
				if(compareLSB(temp,temp2,size,temp2->buck->local_depth)==1){
					temp->buck=temp2->buck;
				}
				
				if(temp->next!=NULL){
					temp=temp->next;
				}
			}
			if(temp2->next!=NULL){
				temp2=temp2->next;
			}
		}
		//now make a new bucket and link it with the splitted node
		temp=first;
		for(i=0;i<tableSize;i++){
			if(temp->buck==NULL){
				temp->buck=createNewBucket(bsize,buck->local_depth);
				break;
			}
			temp=temp->next;
		}
		
		//now store values of this splitted nodes bucket somewhere and rehash those keys!!
		
		for(i=0;i<bsize;i++){
			tempArray[i]=buck->keys[i];
			buck->keys[i]=0;
		}
		}else{//code below manages violation if global depth >= local depth
			b=createNewBucket(bsize,buck->local_depth);
			for(i=0;i<bsize;i++){
				tempArray[i]=buck->keys[i];
				buck->keys[i]=0;
			}
			while(1){
				temp=temp->next;
				if(temp->buck==buck){
					temp3=temp;// we will compare other splitted elements against temp3
					break;
				}
				if(temp->next==NULL){
					break;
				}
			}
			while(1){
				temp=temp->next;
				if(temp->buck==buck){
					if(compareLSB(temp,temp3,size,temp3->buck->local_depth)!=1){//if not equal to temp3 then it means it is the splitted node and should have new bucket
						temp->buck=b;		
					}
				}
				if(temp->next==NULL){
					break;
				}
			}
		}
		display(first,bsize,size);
		
		//now use the stored keys to rehash!! by using the same addnewkey function again
		
		for(i=0;i<bsize;i++){
			addNewKey(first,tempArray[i],size,bsize);
		}
		addNewKey(first,num,size,bsize);
}

int main(){
	//highly modular code, we can change bucket size and number of bits (size) as per our will
	int size=16;
	global_depth=1;
	int bucket_size=3;
	int length_of_table=2^global_depth;
	int num,i;

	tE *first=createNewTableElement(NULL,NULL,decToBin(0,size),size);
	first->buck=createNewBucket(bucket_size,1);
	first->next=NULL;
	
	tE *second=createNewTableElement(NULL,NULL,decToBin(1,size),size);
	second->buck=createNewBucket(bucket_size,1);
	second->next=NULL;
	first->next=second;
	
	display(first,bucket_size,size);
	
	while(1){
		printf("\nEnter a number you want to insert in the table: ");
		scanf("%d",&num);
		first=addNewKey(first,num,size,bucket_size);
		display(first,bucket_size,size);
	}
	return 0;
}



















