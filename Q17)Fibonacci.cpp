#include <cstdio>

int fib(int n) {
    if (n <= 1) 
	return n;           
    else
	return fib(n-1) + fib(n-2);    
}

int main() {
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    printf("\nFibonacci Series");
    for (int i = 0; i < n; i++) {
    printf("%d ", fib(i)); 
	}
    printf("\n");
    return 0;
}

