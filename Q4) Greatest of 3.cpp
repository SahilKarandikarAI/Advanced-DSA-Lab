#include<cstdio>
using namespace std;
int main()
{
	int x, y,z;
	printf("Enter three numbers: \n");
	scanf("%d%d%d", &x,&y,&z);
	printf("x=%d \t y=%d \t z=%d",x,y,z);
	if(x==y && y==z)
		printf("\nAll three are same");
	else{
	
	if(x>y){
	if(x>z)
	printf("\nx is the greatest number: ");
	if(y>z)
	printf("\ny is the greatest number: ");
	}
	else
	printf("\nz is the greatest number: ");
    }
	return 0;
}
