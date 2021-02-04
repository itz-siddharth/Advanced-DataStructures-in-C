//21.	Read the marks obtained by students of second year in an online examination of particular subject. 
//      Find out maximum and minimum marks obtained in that subject. Use heap data structure. Analyze the algorithm. 
#include<stdio.h>

void maxHeapify(int heap[],int i,int n)
{
    int left=2*i;
    int right=(2*i)+1;
    int largest=i;
     
    if((left<=n)&&(heap[i]<heap[left]))
    {
    	largest=left;
	}
    if(right<=n && heap[largest]<heap[right])
        largest=right;
         
        if(largest !=i)
        {
            int temp=heap[largest];
            heap[largest]=heap[i];
            heap[i]=temp;
            maxHeapify(heap,largest,n);
        }
}

void buildHeap(int heap[],int n)
{
    int i;
	for(i=n/2;i>=1;i--)
	{
		maxHeapify(heap,i,n);
	}         
}

void main()
{
    int i,n;
    printf("\nEnter No Of Elements : ");
    scanf("%d",&n);
    
	int heap[n+1];
    printf("\nEnter Element ");
    for(i=1;i<=n;i++)
    {
    	scanf("%d",&heap[i]);
	}
    buildHeap(heap,n);
    int heapSize=n;
    for(i=n;i>=2;i--)
    {  
        int temp=heap[1];
        heap[1]=heap[i];
        heap[i]=temp;
        --heapSize;
        maxHeapify(heap,1,heapSize);
    }
    printf("\nAfter Sorting\n");
    for(i=1;i<=n;i++)
    printf("%d ",heap[i]);
    printf("\n\n-----------RESULT-----------");
    printf("\nMAXIMUM MARKS = %d",heap[n]);
    printf("\nMINIMUM MARKS = %d",heap[1]);
   
}
