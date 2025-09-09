#include<cstdio>
using namespace std;
int factorial(){
	printf("Enter a number: ");
	int n;
	scanf("%d",&n);
	int f=1;
	for(int i=1;i<=n;i++){
		f=f*i;
	}
	printf("%d",f);

}
int main(){
factorial();




return 0;
}

