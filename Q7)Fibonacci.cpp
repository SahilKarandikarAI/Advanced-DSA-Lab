#include<cstdio>
using namespace std;
int main(void) {
    int n,c;
    printf("Enter term upto which fibonacci series needed: ");
    scanf("%d", &n);
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        printf("%d ", c);
        c = a + b;
        a = b;
        b = c;
    }
    return 0;
}
