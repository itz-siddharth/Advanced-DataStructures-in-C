#include <stdio.h>

struct Complex
{
    float real;
    float imag;
};

void add_byreference(struct Complex c1,struct Complex c2,struct Complex*result) 
{
     result->real = c1.real + c2.real;
     result->imag = c1.imag + c2.imag; 

}

void add_byvalue(struct Complex c1,struct Complex c2) 
{	
     float sum_real,sum_img;
	 sum_real = c1.real + c2.real;
     sum_img = c1.imag + c2.imag; 
     
    printf("\nresult.real = %.1f\n",sum_real);
    printf("result.imag = %.1f\n",sum_img);

}


void main()
{
    struct Complex c1, c2, result;

    printf("For first number,\n");
    printf("Enter real part: ");
    scanf("%f", &c1.real);
    printf("Enter imaginary part: ");
    scanf("%f", &c1.imag);

    printf("For second number, \n");
    printf("Enter real part: ");
    scanf("%f", &c2.real);
    printf("Enter imaginary part: ");
    scanf("%f", &c2.imag);
    
    
	printf("\nAdd By Reference :");
    add_byreference(c1, c2, &result); 
    printf("\nresult.real = %.1f\n", result.real);
    printf("result.imag = %.1f \n", result.imag);
    
    printf("\nAdd By Value :");
    add_byvalue(c1,c2);    
    
}
	
	


