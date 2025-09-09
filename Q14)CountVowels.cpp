#include <cstdio>
#include<cstring>
int main(void) {
    char s[200];  
    int count = 0;

    printf("Enter a string: ");
    scanf("%s", s);   

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
            c=='A'||c=='E'||c=='I'||c=='O'||c=='U') {
            count++;
        }
    }

    printf("No of vowels = %d\n", count);
    return 0;
}

