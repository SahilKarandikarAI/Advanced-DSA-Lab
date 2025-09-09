#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
//ELECTRICITY BILL CONSUMPTION
float units,a,bill;
printf("Enter the units consumed: ");
scanf("%f",&units);

if(units<0)
printf("Wrong input\n");
else if(units<=100){
bill=5*units;
printf("The bill is: %0.1f",bill);
}
else if(units>100 && units<=200){
	a=units-100;
	bill=(a*7)+ 500;
	printf("The bill is: %0.1f",bill);
}
else{

a=units-200;
bill=a*10+500+700;
printf("The bill is: %0.1f",bill);
}return 0;
}

