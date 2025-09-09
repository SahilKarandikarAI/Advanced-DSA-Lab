#include<cstdio>
int main()
{
	int n, m=0, r;
	printf("Enter your ATM pin: ");
	scanf("%d", &n);
	int temp=n;
	while(n!=0)
	{
		r= n % 10;
		m= m * 10 + r;
		n/= 10;
	}
	printf("\nEntered number: %d",temp);
	printf("\nReversed number: %d",m);
	if(m==temp)
	printf("\nThe ATM pin entered is palindrome");
	else
	printf("\nThe ATM pin entered is not a palindrome");
	
	return 0;
}


