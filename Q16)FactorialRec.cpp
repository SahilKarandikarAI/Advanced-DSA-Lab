#include<cstdio>
int factorial(int n)
{
	if(n>=1)
	return (n* factorial(n-1));
	else
	return 1;
}
int main()
{
int n;
printf("Enter a positive number to find its factorial: ");
scanf("%d", &n);
printf("\nThe factorial of the entered number is: %d", factorial(n));
return 0;	
}
//Q16
