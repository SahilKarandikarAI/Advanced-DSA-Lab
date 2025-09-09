#include<cstdio>
int main()
{
	int n, m=0, r,count=0;
	printf("Enter an integer: ");
	scanf("%d", &n);
	while(n!=0)
	{
		r= n % 10;
		m= m * 10 + r;
		n/= 10;
		count++;
	}
	
	printf("Number of digits in the number are: %d", count);
	return 0;
}

