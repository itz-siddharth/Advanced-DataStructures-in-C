// Program to calculate the sum of n numbers entered by the user

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, i, *ptr, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = (int*) malloc(n * sizeof(int));
 
    // if memory cannot be allocated
    if(ptr == NULL)                     
    {
        printf("No memory allocated.");
        exit(0);
    }

    printf("Enter elements: ");
    for(i = 0; i < n; ++i)
    {
	
        scanf("%d", ptr + i);
        sum += *(ptr + i); 
    }

    printf("Sum = %d",sum);
  
    // deallocating the memory
    free(ptr);

    
}
