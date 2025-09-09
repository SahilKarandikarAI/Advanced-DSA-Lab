#include <stdio.h>
int main() {
    int t;
    printf("Enter token number: ");
    scanf("%d", &t);
    if (t != 1) {
        printf("Invalid input\n");
        return 0;
    }
    if (t % 2 == 0)
        printf("%d is even\n", t);
    else
        printf("%d is odd\n", t);
    return 0;
}

