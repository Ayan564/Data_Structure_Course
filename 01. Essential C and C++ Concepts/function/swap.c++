// #include <stdio.h>
// using namespace std;
// void swap(int &a, int &b)
// {
//     int temp;
//     temp = a;
//     a = b;
//     b = temp;
// }
// int main()
// {
//     int x, y;
//     printf("Enter Value of x ");
//     scanf("%d", &x);
//     printf("\nEnter Value of y ");
//     scanf("%d", &y);
//     swap(x, y);
//     printf("\nAfter Swapping: x = %d, y = %d", x, y);
//     return 0;
// }
// #include<stdio.h>

// void swap(int *,int *);
// int main()
// {

//     int n1,n2;
// 	printf("\n\n Function : swap two numbers using function :\n");
// 	printf("------------------------------------------------\n");	   
//     printf("Input 1st number : ");
//     scanf("%d",&n1);
//     printf("Input 2nd number : ");
//     scanf("%d",&n2);	

//     printf("Before swapping: n1 = %d, n2 = %d ",n1,n2);
// 	//pass the address of both variables to the function.
//     swap(&n1,&n2);

//     printf("\nAfter swapping: n1 = %d, n2 = %d \n\n",n1,n2);
//     return 0;
// }

// void swap(int *p,int *q)
// {
// 	//p=&n1 so p store the address of n1, so *p store the value of n1
// 	//q=&n2 so q store the address of n2, so *q store the value of n2

//     int tmp;
//     tmp = *p; // tmp store the value of n1
//     *p=*q;    // *p store the value of *q that is value of n2
//     *q=tmp;   // *q store the value of tmp that is the value of n1
// }
#include <stdio.h>
 
 
void swap(int, int);
 
int main()
{
   int x, y;
 
   printf("Enter the value of x and y\n");
   scanf("%d%d",&x,&y);
 
   printf("Before Swapping\nx = %d\ny = %d\n", x, y);
 
   swap(x, y); 
 
   return 0;
}
 
void swap(int a, int b)
{
   int temp;
 
   temp = b;
   b = a;
   a = temp;
    printf("Values of a and b is %d  %d\n",a,b);
}