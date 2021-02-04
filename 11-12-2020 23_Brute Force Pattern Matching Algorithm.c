//Naive Pattern Searching algorithm 
#include <stdio.h> 
#include <string.h> 
  
void search(char* pattern, char* text) 
{ 
    int patLen = strlen(pattern); 
    int strLen = strlen(text); 
  	int i;
    /* A loop to slide pat[] one by one */
    for(i = 0; i <= strLen - patLen; i++) { 
        int j; 
  
        
        for (j = 0; j < patLen; j++) 
            if (text[i + j] != pattern[j]) 
                break; 
  
        if (j == patLen) 
            printf("Pattern found at index %d \n", i); 
    } 
} 

void main() 
{ 
    char text[] = "AAAABAAAAABBBAAAAB"; 
    char pattern[] = "AAAB"; 
    search(pattern, text); 
} 
