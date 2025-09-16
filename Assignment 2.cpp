//Q1a

#include<cstdio>
using namespace std;
//Q1a)
void SumArray(){
	int a[10]={12,14,13,15,45,56,43,35,34};
	int sum=0;
	int n=9;
	for(int i=0;i<9;i++){
		sum=sum+ a[i];
	}
	printf("%d",sum);
}


int main(){
//Q1a)
SumArray();



return 0;
}



//Q1b
#include<cstdio>
using namespace std;
int sumarrrec(int a[9],int n=9){
	if(n<=0)
	return 0;
	else
	return sumarrrec(a,n-1)+a[n-1];
}
int main(){
int a[10]={12,14,13,15,45,56,43,35,34};
	
	int n=9;
int z=sumarrrec(a,n);
printf("%d",z);

return 0;
}


//Q2a
#include<cstdio>
using namespace std;
int main(){
int a[10]={12,14,13,15,45,26,43,35,34};
int max=a[0];
int n=9;
for(int i=0;i<n;i++){
	if(max<=a[i])
	max=a[i];
}
printf("%d",max);


return 0;
}




//Q2b
#include<cstdio>
using namespace std;
int main(){

    int a[10] = {12, 14, 13, 15, 45, 26, 43, 35, 34};
    int n = 9;
    int i, j, temp,max;    
    printf("Original array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
            temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
            }
        }
        max=a[i+1];
    }   
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("%d",max);
    return 0;
}


//Q3a
#include<cstdio>
#include <string.h>
using namespace std;
int main(){

    char s[]="Data Structures Lab";   
    int right = strlen(s) - 1;
    int left = 0;
    char temp;
    char rs[40];
    strcpy(rs,s);


    while (left < right) {

    temp = s[left];
    s[left] = s[right];
    s[right] = temp;
    left++;
    right--;
    }
    printf("Original string: %s\n", rs);
    printf("Reversed string: %s\n", s);

    return 0;
}


//Q3b
#include<cstdio>
#include <string.h>
using namespace std;

int main() {
    char original[] = "Data Structures Lab";
    int len = strlen(original);
    char reversed[len + 1]; 
    int i, j = 0; 
    for (i = len - 1; i >= 0; i--) {
    reversed[j] = original[i];
	j++;
    }
	reversed[j] = '\0';
    printf("Original string: %s\n", original);
    printf("Reversed string: %s\n", reversed);

    return 0;
}


//Q4a
#include <cstdio>
using namespace std;
int main() {
    int t;
    printf("Enter number: ");
    scanf("%d",&t);
    if (t % 2 == 0)
    	printf("%d is even\n", t);
    else
    	printf("%d is odd\n", t);
    return 0;
}



//Q4b
#include<cstdio>
using namespace std;
int main(){
int t;
    printf("Enter number: ");
    scanf("%d",&t);
    if (t & 0 == 0)
    	printf("%d is even\n", t);
    else
    	printf("%d is odd\n", t);
    return 0;


return 0;
}



//Q5a
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


//Q5b
#include<cstdio>
int factorial(int n)
{
	if(n>=1)
	return (n* factorial(n-1));
	else
	return 1;
}
int main()
{
int n;
printf("Enter a positive number to find its factorial: ");
scanf("%d", &n);
printf("\nThe factorial of the entered number is: %d", factorial(n));
return 0;	
}



//Q6a
#include<cstdio>
using namespace std;
int main(){
int a[10]={12,14,13,15,45,56,43,35,34};
	int ls;
	int n=9;
	printf("Enter element to be found: ");
	scanf("%d",&ls);
	for(int i=0;i<9;i++){
    if(ls!=a[i])
    if(i<9)
    continue;
    else
    printf("Element not found");
    else{
    printf("%d found at %d",ls,i+1);
    break;
}}return 0;
}



//Q6b
#include<cstdio>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;
    int last = arr[n - 1];
    arr[n - 1] = key;
    int i = 0;
    while (arr[i] != key) {
        i++;
    }
   arr[n - 1] = last;
    if (i < n - 1 || last == key) {
        printf("Element %d found at index %d.\n", key, i);
    } else {
        printf("Element %d not found in the array.\n", key);
    }
    return 0;
}



//Q7a
#include<cstdio>
using namespace std;
int main(){
int n;
printf("Enter number: ");
scanf("%d",&n);
for(int i=1;i<=n;i++){
	printf("%d ",i);
}


return 0;
}


//Q7b
#include<cstdio>
using namespace std;
int natural(int n,int i)
{
	if(i>n)
	return 0;
	printf("%d ",i);
	return natural(n,i+1);
	
}
int main(){
int n=12;
int i=1;
natural(n,i);

return 0;
}



//Q8a
#include<cstdio>
#include<string.h>
using namespace std;

int main(){
	int count;
	char s[]="Data Structures LAB";
	for(int i=0;i<strlen(s);i++){
	
	if (s[i]=='A' || s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U' ||s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u'){
		count++;
		
	}}
printf("No of vowels %d",count);

return 0;
}



//Q8b
#include<cstdio>
int main() {
    int is_vowel_lookup[256] = {0};
    is_vowel_lookup['a'] = 1;
    is_vowel_lookup['e'] = 1;
    is_vowel_lookup['i'] = 1;
    is_vowel_lookup['o'] = 1;
    is_vowel_lookup['u'] = 1;
    is_vowel_lookup['A'] = 1;
    is_vowel_lookup['E'] = 1;
    is_vowel_lookup['I'] = 1;
    is_vowel_lookup['O'] = 1;
    is_vowel_lookup['U'] = 1;
    char str[] = "Data Structures Lab";
    int vowel_count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (is_vowel_lookup[(unsigned char)str[i]]) {
            vowel_count++;
        }
        i++;
    }

    printf("The string is: \"%s\"\n", str);
    printf("Number of vowels: %d\n", vowel_count);

    return 0;
}



//Q9a
#include<cstdio>
using namespace std;
int main(){
	int a=10,b=20;
	printf("Original no %d %d",a,b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("\nReversed no %d %d",a,b);
return 0;
}



//Q9b
#include<cstdio>
using namespace std;
int main(){
	int a=10,b=20;
	printf("Original no %d %d",a,b);
	a=a^b;
	b=a^b;
	a=a^b;
	printf("\nReversed no %d %d",a,b);
return 0;
}



//Q10a
#include <cstdio>
#include <cstring>
int main() {
    int num = 12321;
    char str[20];
    sprintf(str, "%d", num);
    int palindrome = 1;
    int length = strlen(str);
    
    int left = 0;
    int right = length - 1;
    
    while (left < right) {
        if (str[left] != str[right]) {
            palindrome = 0;
            break;
        }
        
        left++;
        right--;
    }
    
    if (palindrome) {
        printf("%d is a palindrome.\n", num);
    } else {
        printf("%d is not a palindrome.\n", num);
    }

    return 0;
}



//Q10b
#include<cstdio>
int main(){
int n=123;
int r,c,m;
c=n;
while(n!=0){
	r=n%10;
	m=m*10+r;
	n=n/10;
	
}
printf("Entered number: %d",c);
	printf("\nReversed number: %d",m);
	if(m==c)
	printf("\nEntered no is palindrome");
	else
	printf("\nEntered no is not a palindrome");
	return 0;
}



