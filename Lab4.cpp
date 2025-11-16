//Q1
#include <stdio.h>
struct Complex {
    float real, imag;
};
int main() {
    struct Complex c1, c2, temp;
    printf("Enter first complex number real,imag: ");
    scanf("%f %f", &c1.real, &c1.imag);
    printf("Enter second complex number real,imag: ");
    scanf("%f %f", &c2.real, &c2.imag);
    temp = c1;
    c1 = c2;
    c2 = temp;

    printf("After swapping:\n");
    printf("c1 = %.2f + %.2fi\n", c1.real, c1.imag);
    printf("c2 = %.2f + %.2fi\n", c2.real, c2.imag);
    return 0;
}

//Q2
#include <stdio.h>
struct Employee {
    int id;
    char name[50];
    float salary;
};
int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    struct Employee emp[n];

    for(int i=0; i<n; i++) {
        printf("Enter id, name, salary: ");
        scanf("%d %s %f", &emp[i].id, emp[i].name, &emp[i].salary);
    }

    printf("\nEmployee details:\n");
    for(int i=0; i<n; i++) {
        printf("%d %s %.2f\n", emp[i].id, emp[i].name, emp[i].salary);
    }
    return 0;
}

//Q3
#include <stdio.h>
struct Date {
    int day, month, year;
};
struct Student {
    int roll;
    char name[50];
    struct Date dob;
};
int main() {
    struct Student s;
    printf("Enter roll, name, DOB (dd mm yyyy): ");
    scanf("%d %s %d %d %d", &s.roll, s.name, &s.dob.day, &s.dob.month, &s.dob.year);

    printf("\nStudent details:\n");
    printf("Roll: %d\nName: %s\nDOB: %02d-%02d-%d\n",
           s.roll, s.name, s.dob.day, s.dob.month, s.dob.year);
    return 0;
}


//Q4
#include <stdio.h>
struct Node {
    int data;
    struct Node *next;  
};
int main() {
    struct Node n1, n2;
    n1.data = 10;
    n2.data = 20;
    n1.next = &n2;
    n2.next = NULL;

    printf("First node data = %d\n", n1.data);
    printf("Next node data = %d\n", n1.next->data);
    return 0;
}

//Q5
#include <stdio.h>
struct Student {
    char name[50];
    int marks;
};
int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct Student s[n];
    int maxMarks = -1, index = -1;

    for(int i=0; i<n; i++) {
        printf("Enter name and marks: ");
        scanf("%s %d", s[i].name, &s[i].marks);
        if(s[i].marks > maxMarks) {
            maxMarks = s[i].marks;
            index = i;
        }
    }

    printf("Topper: %s with %d marks\n", s[index].name, s[index].marks);
    return 0;
}


//Q6
#include <stdio.h>
#include <string.h>
struct Student {
    int roll;
    char name[50];
};
int main() {
    struct Student s1 = {1, "Amit"};
    struct Student s2 = {1, "Amit"};

    if(s1.roll == s2.roll && strcmp(s1.name, s2.name) == 0) {
        printf("Both students are same.\n");
    } else {
        printf("Students are different.\n");
    }
    return 0;
}

//Q7
/********** 7. Cricket team highest runs **********/
#include <stdio.h>
struct Player {
    char name[50];
    int runs, wickets;
};
int main() {
    int n;
    printf("Enter number of players: ");
    scanf("%d", &n);
    struct Player p[n];
    int maxRuns = -1, id = -1;

    for(int i=0; i<n; i++) {
        printf("Enter name, runs, wickets: ");
        scanf("%s %d %d", p[i].name, &p[i].runs, &p[i].wickets);
        if(p[i].runs > maxRuns) {
            maxRuns = p[i].runs;
            id = i;
        }
    }

    printf("Player with highest runs: %s (%d runs)\n", p[id].name, p[id].runs);
    return 0;
}

//Q8
#include <stdio.h>
#include <stdlib.h>

struct student
{
    int id;
    char name[20];
};

int main()
{
    int n = 3;
    struct student *arr1 = (struct student *)malloc(n * sizeof(struct student));
    struct student *arr2 = (struct student *)calloc(n, sizeof(struct student));

    printf("Using malloc: id[0] = %d\n", arr1[0].id); 
    printf("Using calloc: id[0] = %d\n", arr2[0].id); 

    free(arr1);
    free(arr2);
    return 0;
}

//Q10


#include <stdio.h>
#include <stdlib.h>

struct student
{
    int roll;
    char name[20];
};

int main()
{
    int n, extra;
    printf("Enter initial number of students: ");
    scanf("%d", &n);

    struct student *S = (struct student *)malloc(n * sizeof(struct student));

    for (int i = 0; i < n; i++)
    {
        printf("Enter Roll and Name of student %d: ", i + 1);
        scanf("%d %s", &S[i].roll, S[i].name);
    }

    printf("\nEnter number of extra students: ");
    scanf("%d", &extra);

    S = (struct student *)realloc(S, (n + extra) * sizeof(struct student));

    for (int i = n; i < n + extra; i++)
    {
        printf("Enter Roll and Name of student %d: ", i + 1);
        scanf("%d %s", &S[i].roll, S[i].name);
    }

    printf("\n--- All Students ---\n");
    for (int i = 0; i < n + extra; i++)
    {
        printf("Roll: %d, Name: %s\n", S[i].roll, S[i].name);
    }

    free(S);
    return 0;
}

