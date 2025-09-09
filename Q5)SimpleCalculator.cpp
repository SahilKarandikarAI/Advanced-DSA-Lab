#include <stdio.h>
int main() {
  int dummy;
  char c,ch;
  int a, b;
  printf("Enter an operator (+, -, *, /): ");
  scanf("%c", &c);
  printf("Enter first number: ");
  scanf("%d", &a);
  printf("Enter second number: ");
  scanf("%d", &b);

  switch (c) {
    case '+':
      printf("%d + %d = %d", a, b, a + b);
      break;
    case '-':
      printf("%d - %d = %d", a, b, a - b);
      break;
    case '*':
      printf("%d * %d = %d", a, b, a * b);
      break;
    case '/':
      printf("%d / %d = %d", a, b, a / b);
      break;
    default:
      printf("Wrong Input!");
  }
   return 0;
}

