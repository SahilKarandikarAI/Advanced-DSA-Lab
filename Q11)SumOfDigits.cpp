#include<cstdio>
using namespace::std;
int main()
{
   long int n,r,sum=0;
	
	printf("Enter number: ");
	scanf("%d",&n);
	while(n!=0)
	{
		r=n%10;
		sum=sum+r;
		n=n/10;
	}
	printf("\nThe sum of the digits of the entered number is: %d",sum);
	return(0);
}
//Q11
