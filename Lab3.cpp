//Q1)
#include<cstdio>
int main() {
    int arr[] = {10, 5, 20, 8, 15};
    int n = 5; 
    int firstlargest;
    int secondlargest;
    if (arr[0] > arr[1]) {
        firstlargest = arr[0];
        secondlargest = arr[1];
    } else {
        firstlargest = arr[1];
        secondlargest = arr[0];
    }
    for (int i = 2; i < n; i++) {
        if (arr[i] > firstlargest) {
            secondlargest = firstlargest;
            firstlargest = arr[i];
        } else if (arr[i] > secondlargest) {
            secondlargest = arr[i];
        }    }
    printf("The array is: ");
    for(int i=0;i<5;i++){
    	printf("%d ",arr[i]);
	}
    printf("\nThe second largest element is: %d\n", secondlargest);
    return 0; }

//Q2
#include <stdio.h>
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    int i, j;
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);    }
    int sum;
    printf("Enter the target sum: ");
    scanf("%d", &sum);

    for (i = 0; i < n; i++) {
        int curr = 0;
        for (j = i; j < n; j++) {
            curr += arr[j];
            if (curr == sum) {
                printf("Subarray found from index %d to %d\n", i, j);
                return 0;            }        }    }
    printf("No contiguous subarray with the given sum was found.\n");
    return 0;}

//Q3
#include <stdio.h>
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    int i, j;
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);    }
    int sum;
    printf("Enter the target sum: ");
    scanf("%d", &sum);

    for (i = 0; i < n; i++) {
        int curr = 0;
        for (j = i; j < n; j++) {
            curr += arr[j];
            if (curr == sum) {
                printf("Subarray found from index %d to %d\n", i, j);
                return 0;            }        }    }
    printf("No contiguous subarray with the given sum was found.\n");
    return 0;}

//Q4
#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;
    char department[50];
};

int main() {
int n, i;
printf("Enter the number of employees: ");
scanf("%d", &n);

struct Employee employees[n];

for (i = 0; i < n; i++) {
    printf("\nEnter details for employee %d:\n", i + 1);
    printf("Enter ID: ");
    scanf("%d", &employees[i].id);
    printf("Enter name: ");
    scanf(" %s", employees[i].name);
    printf("Enter salary: ");
    scanf("%f", &employees[i].salary);
    printf("Enter department: ");
    scanf(" %s", employees[i].department);
    }

    for (i = 0; i < n; i++) {
        if (strcmp(employees[i].department, "IT") == 0) {
            employees[i].salary *= 1.10;
        }
    }

    printf("\nUpdated Employee Details:\n");
    for (i = 0; i < n; i++) {
    printf("\nEmployee %d:\n", i + 1);
    printf("ID: %d\n", employees[i].id);
    printf("Name: %s\n", employees[i].name);
    printf("Salary: %.2f\n", employees[i].salary);
    printf("Department: %s\n", employees[i].department);
}

return 0;
}


//Q5
#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;
    char department[20];
};

int main() {
    struct Employee employees[] = {
        {101, "Nikhil", 50000, "HR"},
        {102, "Paras", 60000, "IT"},
        {103, "Sahil", 55000, "Finance"},
        {104, "Manish", 65000, "IT"},
        {105, "Arjun", 52000, "Marketing"}
    };

    int n = sizeof(employees) / sizeof(employees[0]);
    for (int i = 0; i < n; i++) {
        if (strcmp(employees[i].department, "IT") == 0) {
            employees[i].salary *= 1.10; 
        }
    }
    printf("Updated Employee Details:\n");
    printf("ID\tName\t\tSalary\t\tDepartment\n");
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%-10s\t%.2f\t%s\n",
              employees[i].id,
              employees[i].name,
              employees[i].salary,
              employees[i].department);
    }

    return 0;
}

//Q6
#include <stdio.h>
#include <string.h>

struct Book {
    char title[100];
    char author[50];
    float price;
};

int main() {
int n, i;

printf("Enter the number of books: ");
scanf("%d", &n);

struct Book books[n];

for (i = 0; i < n; i++) {
    printf("\nEnter details for book %d:\n", i + 1);
    printf("Enter title: ");
    scanf(" %s", books[i].title);
	printf("Enter author: ");
    scanf(" %s", books[i].author);
    printf("Enter price: ");
    scanf("%f", &books[i].price);
}

float Price;
    printf("\nEnter the price to compare with: ");
    scanf("%f", &Price);

printf("\nBooks with price above %.2f:\n", targetPrice);
for (i = 0; i < n; i++) {
    if (books[i].price > targetPrice) {
        printf("\nTitle: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Price: %.2f\n", books[i].price);
    }
}

    return 0;
}

//Q7
#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

int main() {
    struct Date date1, date2;
    printf("Enter the first date (day month year): ");
    scanf("%d %d %d", &date1.day, &date1.month, &date1.year);
    printf("Enter the second date (day month year): ");
    scanf("%d %d %d", &date2.day, &date2.month, &date2.year);
    if (date1.year < date2.year) {
        printf("The first date is earlier.\n");
    } else if (date1.year > date2.year) {
        printf("The second date is earlier.\n");
    } else {
        if (date1.month < date2.month) {
            printf("The first date is earlier.\n");
        } else if (date1.month > date2.month) {
            printf("The second date is earlier.\n");
        } else {
            if (date1.day < date2.day) {
                printf("The first date is earlier.\n");
            } else if (date1.day > date2.day) {
                printf("The second date is earlier.\n");
            } else {
                printf("The two dates are the same.\n");
            }
        }
    }
    return 0;
}

//Q8
#include <stdio.h>

struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

int main() {
    int n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Enter name: ");
        scanf(" %s", students[i].name);
        printf("Enter roll number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Enter marks: ");
        scanf("%f", &students[i].marks);
    }

    int high = 0;
    for (i = 1; i < n; i++) {
        if (students[i].marks > students[high].marks) {
            high = i;
        }
    }

    printf("\nStudent with the highest marks:\n");
    printf("Name: %s\n", students[high].name);
    printf("Roll Number: %d\n", students[high].rollNumber);
    printf("Marks: %.2f\n", students[high].marks);

    return 0;
}

//Q9
#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    printf("Enter number of strings: ");
    scanf("%d", &n);
    char s[200][201]; // up to 200 strings of length 200
    for (int i = 0; i < n; ++i)
    {
        scanf(" ");
        fgets(s[i], sizeof(s[i]), stdin);
        size_t len = strlen(s[i]);
        if (len && s[i][len - 1] == '\n')
            s[i][len - 1] = 0;
    }
    if (n == 0)
    {
        printf("\n");
        return 0;
    }

    // Use first string as reference
    int L = strlen(s[0]);
    int prefixLen = L;
    for (int i = 1; i < n; ++i)
    {
        int j = 0;
        while (j < prefixLen && j < (int)strlen(s[i]) && s[0][j] == s[i][j])
            j++;
        prefixLen = j;
        if (prefixLen == 0)
            break;
    }

    if (prefixLen == 0)
        printf("\"\n"); // empty
    else
    {
        char prefix[201];
        strncpy(prefix, s[0], prefixLen);
        prefix[prefixLen] = '\0';
        printf("Longest common prefix: %s\n", prefix);
    }
    return 0;
}
