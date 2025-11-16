//Q1
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};


struct Node* recursiveReverse(struct Node* head) {
    
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct Node* rest = recursiveReverse(head->next);      
    head->next->next = head;
    head->next = NULL;   
    
    return rest;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {    
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->data = 4;
    head->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->next->data = 5;
    head->next->next->next->next->next = NULL;

    printf("Original List: ");
    printList(head);
    printf("\n");

    
    printf("--- Reversing Iteratively ---\n");
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next; 
        current->next = prev;     
        prev = current;           
        current = nextNode;       
    }
    head = prev; 

    printf("List after iterative reverse: ");
    printList(head);
    printf("\n");
    
    
    printf("--- Reversing Recursively ---\n");
    head = recursiveReverse(head);
    
    printf("List after recursive reverse (back to original): ");
    printList(head);

    return 0;
}


//Q2
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 11;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 22;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 33;
    head->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->data = 44;
    head->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->next->data = 55;
    head->next->next->next->next->next = NULL;
    
    struct Node* p = head;
    int search_value;
    int position = 1;
    int found = 0; 

    printf("List: 11 -> 22 -> 33 -> 44 -> 55 -> NULL\n");
    printf("Enter an element to search for: ");
    scanf("%d", &search_value);

    
    while (p != NULL) {
        if (p->data == search_value) {
            found = 1;
            break; 
        }
        p = p->next;
        position++;
    }

    if (found == 1) {
        printf("Element %d found at position: %d\n", search_value, position);
    } else {
        printf("Element %d not found in the list.\n", search_value);
    }

    return 0;
}

//Q3
#include <stdio.h>
#include <stdlib.h> 
struct Node {
    int data;           
    struct Node* next;  
};

int main() {
    struct Node* head = NULL;    
    struct Node* temp = NULL;    
    struct Node* p = NULL;       
    int n, i, item;

    printf("Create and Display a Singly Linked List\n");
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("List cannot be created with 0 or negative nodes.\n");
        return 0;
    }

    printf("Enter the data for node 1: ");
    scanf("%d", &item);
    
    head = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    head->data = item;
    head->next = NULL;
    temp = head;

    for (i = 2; i <= n; i++) {
        printf("Enter the data for node %d: ", i);
        scanf("%d", &item);        
        p = (struct Node*)malloc(sizeof(struct Node));
        if (p == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        p->data = item;
        p->next = NULL;        
        temp->next = p;       
        temp = p;
    }

    printf("\nDisplaying the Linked List\n");
    if (head == NULL) {
        printf("The list is empty.\n");
    } else {
        p = head; 
        while (p != NULL) {
            printf("%d -> ", p->data);
            p = p->next; 
        }
        printf("NULL\n");
    }

    return 0;
}

//Q4
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->data = 4;
    head->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->next->data = 5;
    
    head->next->next->next->next->next = head->next->next; 

    printf("Detecting Loop using Floyd's Cycle Detection Algorithm\n");

    struct Node* slow_p = head;
    struct Node* fast_p = head;
    int loop_found = 0;

    
    while (slow_p != NULL && fast_p != NULL && fast_p->next != NULL) {
        slow_p = slow_p->next;      
        fast_p = fast_p->next->next; 

        
        if (slow_p == fast_p) {
            loop_found = 1;
            break;
        }
    }

    if (loop_found) {
        printf("Loop detected in the linked list.\n");
    } else {
        printf("No loop detected in the linked list.\n");
    }

    return 0;
}

//Q5
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* newNode = NULL;
    struct Node* p = NULL;
    int data, position;

   
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 20;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 30;
    head->next->next->next = NULL;
    
    printf("Original List: ");
    printList(head);
    printf("\n");

    
    printf("Insert at Beginning\n");
    printf("Enter data to insert at the beginning: ");
    scanf("%d", &data);
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head; 
    head = newNode;       
    printf("List after inserting at beginning: ");
    printList(head);
    printf("\n");

    printf("Insert at End\n");
    printf("Enter data to insert at the end: ");
    scanf("%d", &data);
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newNode; 
    printf("List after inserting at end: ");
    printList(head);
    printf("\n");

    
    printf("Insert at a Specific Position\n");
    printf("Enter a position to insert the node: ");
    scanf("%d", &position);
    printf("Enter data for that node: ");
    scanf("%d", &data);
    
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    
    p = head;
    int i = 1;
    
    while (i < position - 1 && p != NULL) {
        p = p->next;
        i++;
    }

    if (p == NULL) {
        printf("Position out of bounds.\n");
    } else {
        newNode->next = p->next; 
        p->next = newNode;       
    }
    printf("List after inserting at position %d: ", position);
    printList(head);
    
    return 0; 
}

//Q6
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* p = NULL;
    int n, i, item;
    int count = 0;  

    printf("Create a list to count its nodes\n");
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Enter data for node 1: ");
        scanf("%d", &item);
        head = (struct Node*)malloc(sizeof(struct Node));
        head->data = item;
        head->next = NULL;
        temp = head;

        for (i = 2; i <= n; i++) {
            printf("Enter data for node %d: ", i);
            scanf("%d", &item);
            p = (struct Node*)malloc(sizeof(struct Node));
            p->data = item;
            p->next = NULL;
            temp->next = p;
            temp = temp->next;
        }
    }
    
    printf("\nCounting the nodes\n");
    if (head == NULL) {
        count = 0;
    } else {
        p = head; 
        while (p != NULL) {
            count++;    
            p = p->next; 
    }

    printf("Total number of nodes in the linked list is: %d\n", count);
} return 0;
}

//Q7
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *merge(struct Node *l1, struct Node *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    if (l1->data < l2->data)
    {
        l1->next = merge(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

struct Node *append(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
        return newNode;
    struct Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *list1 = NULL, *list2 = NULL;
    list1 = append(list1, 1);
    list1 = append(list1, 3);
    list1 = append(list1, 5);
    printf("Display Sorted List 1:\n");
    display(list1);

    list2 = append(list2, 2);
    list2 = append(list2, 4);
    list2 = append(list2, 6);
    printf("Display Sorted List 2:\n");
    display(list2);

    struct Node *merged = merge(list1, list2);
    printf("Merged Sorted List:\n");
    display(merged);
    return 0;
}
//Q8
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 20;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 30;
    head->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->data = 40;
    head->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->next->data = 50;
    head->next->next->next->next->next = NULL;

    struct Node* temp = NULL;
    struct Node* prev = NULL;
    int position;
    
    printf("Original List: ");
    printList(head);
    printf("\n");

    
    printf("Deleting from Beginning\n");
    if (head != NULL) {
        temp = head;     
        head = head->next; 
        free(temp);       
    }
    printf("List after deleting from beginning: ");
    printList(head);
    printf("\n");

    printf("Deleting from End\n");
    if (head != NULL) {
        temp = head;
        prev = NULL;
        
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL) { 
            free(head);
            head = NULL;
        } else {
            prev->next = NULL; 
            free(temp);        
        }
    }
    printf("List after deleting from end: ");
    printList(head);
    printf("\n");

    
    printf("Deleting from a Specific Position\n");
    printf("Enter a position to delete: ");
    scanf("%d", &position);
    
    temp = head;
    prev = NULL;
    int i = 1;
    while (temp != NULL && i < position) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
    } else {
        prev->next = temp->next; 
        free(temp);              
    }
    printf("List after deleting from position %d: ", position);
    printList(head);
    
    return 0; 
}

//Q9
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void append(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void findMiddle()
{
    struct Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow)
        printf("Middle element: %d\n", slow->data);
}

int main()
{
    append(10);
    append(20);
    append(30);
    append(40);
    append(50);
    findMiddle();
    return 0;
}

//Q10
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void append(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void display()
{
    struct Node *temp = head;
    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void removeDuplicates()
{
    struct Node *current = head;
    while (current && current->next)
    {
        if (current->data == current->next->data)
        {
            struct Node *dup = current->next;
            current->next = dup->next;
            free(dup);
        }
        else
        {
            current = current->next;
        }
    }
}

int main()
{
    append(1);
    append(1);
    append(2);
    append(3);
    append(3);
    append(4);

    printf("Original list:\n");
    display();

    removeDuplicates();
    printf("After removing duplicates:\n");
    display();

    return 0;
}


