#include <stdio.h>

int sum_of_digits(int n) {
    if (n < 0) 
	n = -n;                 
    if (n == 0) 
	return 0;              
    return (n % 10) + sum_of_digits(n / 10);
}

int main(void) {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    printf("The sum of the digits of the number is: ");
    int ans;
    ans=sum_of_digits(n) ;
    printf("%d\n",ans);
    return 0;
}

