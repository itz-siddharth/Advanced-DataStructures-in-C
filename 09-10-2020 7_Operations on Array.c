#include<stdio.h>
#include<stdlib.h>

//Function Prototype
void Display(int arr[],int n);  // To Display the array elements
int Append(int arr[],int n);  // To insert the elememt at the end!
int Insert(int arr[],int n); // Insert at index
void Search(int arr[],int n); // Search the array
int Get(int arr[],int n);  // Get by index or by value
void Min(int arr[],int n); //  Minimum number
void Max(int arr[],int n); // Maximum number
void Reverse(int arr[],int n); // Reverse of array
void Rotate(int arr[],int n); // Rotate array

// Main Function
void main(){
	
	int i,n,choice;
		
	printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n];

    printf("Enter elements: ");
    for(i = 0; i < n; ++i)
    {
        scanf("%d",&arr[i]);
    }
    
    while(1){
    	
    	printf("\n------------------------\n\t0.Exit \n\t1.Display \n\t2.Append \n\t3.Insert \n\t4.Search \n\t5.Get \n\t6.Max \n\t7.Min \n\t8.Reverse Array \n\t9.Rotate Array \n------------------------\n");
    	printf("Enter choice:");
    	scanf("%d",&choice);
    
   		switch(choice){
     		case 0: exit(0);
			
     		case 1: Display(arr,n); // Display
     				break;
     		case 2: n = Append(arr,n); // Append
     				break;
     		case 3: n = Insert(arr,n); // Insert
     				break;
     		case 4: Search(arr,n); // Search
     				break;
     		case 5: // Get element by value or element using index 
			 		printf("%d",Get(arr,n));
     				break;
     		case 6: Max(arr,n);  // Maximum number
     				break;
     		case 7: Min(arr,n);  // Minimum number
     				break;
     		case 8: Reverse(arr,n);  // Reverse array
     				break;
     		case 9: Rotate(arr,n);  // Rotate Array
     				break;
     		default:
     				printf("Choice you entered is not available [TRY AGAIN]!");
            
	 	}
    	
	}
    
}	

//-----> Display Function Definition
void Display(int arr[], int n){
	int i;
	printf("\nElements in the array :");
	
	printf(" [");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("]\n");
}

//-----> Append Function Definition
int Append(int arr[],int n){
	
	int i,ele;
	
	printf("Enter the number to append: ");
	scanf("%d",&ele);
	
	arr[n] = ele;
	Display(arr,n+1);
	return n+1;
}

//-----> Insert Function Definition
int Insert(int arr[],int n){
	
	int pos, ele, j;
	printf("Enter the position and the element respectively : ");
	scanf("%d %d",&pos,&ele);
	
	n = n+1;
	j = n;
	
	while( j >= pos) {
      arr[j+1] = arr[j];
      j = j - 1;
   }
   arr[pos] = ele;
   
   Display(arr,n);
   return n;
}

//-----> Search Function Definition
void Search(int arr[],int n){
	
	int i,index,ele;
	int flag = 0;
	
	printf("Enter number to search in the array : ");
	scanf("%d",&ele);
	 
    for(i=0;i<n;i++){
    	if(arr[i]==ele){
    		
    		flag = 1;
    		index = i;
    		break;
		
		}
	} 
    
    if(flag == 1){
    	printf("Number %d is present at %d position!",ele,index);	
	}
	else{
		printf("Number %d is not present in the array!",ele);
	}  
	
}

//-----> Get Function Definition
int Get(int arr[],int n){
	
	int c;
	printf("1.Get element by value\n2.Get element by index\n Enter Choice:  ");
	scanf("%d",c);
	
	if(c==1){
		int val,i;
		printf("Enter value: ");
		scanf("%d",&val);
		
		for(i=0;i<n;i++){
			if(arr[i] == val){
				return arr[i];
			}
		}
		
	}
	else if(c==2){
		int pos,i; 
		printf("Enter position: ");
		scanf("%d",&pos);
		
		for(i=0;i<n;i++){
			if(i==pos){
				return arr[i];
			}
		}

	}

}

//-----> Max Function Definition
void Min(int arr[],int n){
	int i,min;
	
	min = arr[0];
	for(i=1;i<n;i++){
		if(arr[i]<min){
			min = arr[i];
		}
	}
	
	printf("Minimum number in the array is %d",min);
}

//-----> Max Function Definition
void Max(int arr[],int n){
	int i,max;
	
	max = arr[0];
	for(i=1;i<n;i++){
		if(arr[i]>max){
			max = arr[i];
		}
	}
	
	printf("Maximum number in the array is %d",max);
}

//-----> Reverse Function Definition
void Reverse(int arr[],int n){
	
	int temp, start, end;
	start = 0;
	end = n-1;

    while (start < end)
    {
        temp = arr[start];   
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }  
	
}

//-----> Rotate Function Definition
void Rotate(int arr[], int n){
	
	int i,j,d,c,first;
	printf("1.Rotate Left \n2.Rotate Right \nEnter Choice: ");
	scanf("%d",&c);
	printf("Rotate elements by how much elements?? ");
	scanf("%d",&d);
	
	if(c==1){
		// Rotate Left !
		for(i=0;i<d;i++){
			int j,first;
			first = arr[0];
			
			for(j = 0; j < n-1; j++){    
            //Shift element of array by one to the left   
            arr[j] = arr[j+1];    
        	}    
        
			//First element of array will be added to the end    
        	arr[j] = first;   
		}
		
		Display(arr,n);
	}
	else if(c==2){
		//Rotate Right !
		for(i=0;i<d;i++){
			
			int j,last;
			last = arr[n-1];
			
			for(j=n-1;j>0;j--){
				//Shift element of array by one to the right
				arr[j] = arr[j-1];	
			}
			arr[0] = last;   
		}
	}
	
	
}





