#include<cstdio>
using namespace std;
int main(){
int a,b,c;
printf("Enter two numbers: ");
scanf("%d %d",&a,&b);
printf("Numbers before swapping\n");
printf("%d %d",a,b);
c=a;
a=b;
b=c;
printf("\nThe numbers after swap are\n");
printf("%d %d",a,b);


return 0;
}

