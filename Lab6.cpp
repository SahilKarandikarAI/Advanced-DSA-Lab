//Q1
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

void insertAtBeginning(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head)
        head->prev = newNode;
    head = newNode;
}

void insertAtEnd(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (!head)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(int data)
{
    struct Node *temp = head;
    while (temp && temp->data != data)
        temp = temp->next;
    if (!temp)
        return;

    if (temp->prev)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;

    free(temp);
}

void display()
{
    struct Node *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    display();
    deleteNode(20);
    display();
    return 0;
}

//Q2
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

void insertAtPos(int data, int pos)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    if (pos == 1)
    {
        newNode->next = head;
        if (head)
            head->prev = newNode;
        head = newNode;
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp; i++)
        temp = temp->next;
    if (!temp)
        return;

    newNode->next = temp->next;
    if (temp->next)
        temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void display()
{
    struct Node *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    insertAtPos(10, 1);
    insertAtPos(20, 2);
    insertAtPos(15, 2);
    printf("Old List Nodes: ");
    display();
    insertAtPos(15, 1);
    printf("New List Nodes: ");
    display();
    return 0;
}

//Q3
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

void insert(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;
    if (head)
        head->prev = newNode;
    head = newNode;
}

void deleteValue(int value)
{
    struct Node *temp = head;
    while (temp && temp->data != value)
        temp = temp->next;
    if (!temp)
        return;

    if (temp->prev)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    free(temp);
}

void display()
{
    struct Node *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    insert(30);
    insert(20);
    insert(10);
    printf("Orignal Linked List: ");
    display();
    deleteValue(20);
    printf("After deleting the first occured target element, Linked List: ");
    display();
    return 0;
}
//Q4
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

void insert(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;
    if (head)
        head->prev = newNode;
    head = newNode;
}

void reverse()
{
    struct Node *temp = NULL, *current = head;
    while (current)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp)
        head = temp->prev;
}

void display()
{
    struct Node *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    printf("Orignal Linked List: ");
    display();
    reverse();
    printf("Reversed Linked List: ");
    display();
    return 0;
}

//Q5
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};
struct Node *head = NULL;

void insert(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;
    if (head)
        head->prev = newNode;
    head = newNode;
}

void findLengthAndMiddle()
{
    int length = 0;
    struct Node *temp = head;
    while (temp)
    {
        length++;
        temp = temp->next;
    }

    int mid = length / 2 + 1;
    temp = head;
    for (int i = 1; i < mid; i++)
        temp = temp->next;
    printf("Linked List Length: %d, Middle Node Value is : %d\n", length, temp->data);
}

int main()
{
    insert(50);
    insert(40);
    insert(30);
    insert(20);
    insert(10);
    findLengthAndMiddle();
    return 0;
}

//Q6

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *last = NULL;

void insertAtBeginning(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (!last)
    {
        last = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
    }
}

void insertAtEnd(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (!last)
    {
        last = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void display()
{
    if (!last)
        return;
    struct Node *temp = last->next;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

int main()
{
    printf("Inserting node(10) at End:");
    insertAtEnd(10);
    display();

    printf("Inserting node(11) at End:");
    insertAtEnd(11);
    display();

    printf("Inserting node(5) at beginning:");
    insertAtBeginning(5);
    display();

    printf("Inserting node(20) at end");
    insertAtEnd(20);
    display();
    return 0;
}

//Q7
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *last = NULL;

void insertEnd(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (!last)
    {
        last = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void insertAfter(int value, int data)
{
    if (!last)
        return;
    struct Node *temp = last->next;
    do
    {
        if (temp->data == value)
        {
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
            if (temp == last)
                last = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != last->next);
}

void display()
{
    if (!last)
        return;
    struct Node *temp = last->next;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

int main()
{
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    printf("Original List Node value : ");
    display();
    printf("After insertiona List Node value : ");
    insertAfter(20, 25);
    display();
    return 0;
}

//Q8
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *last = NULL;

void insertEnd(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (!last)
    {
        last = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void deleteValue(int value)
{
    if (!last)
        return;
    struct Node *temp = last->next, *prev = last;
    do
    {
        if (temp->data == value)
        {
            if (temp == last && temp->next == last)
            {
                free(temp);
                last = NULL;
                return;
            }
            if (temp == last)
                last = prev;
            prev->next = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != last->next);
}

void display()
{
    if (!last)
        return;
    struct Node *temp = last->next;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

int main()
{
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    printf("Original List Node value : ");
    display();
    printf("After deletion List Node value : ");
    deleteValue(20);
    display();
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

int isCircular(struct Node *head)
{
    if (!head)
        return 1;
    struct Node *temp = head->next;
    while (temp && temp != head)
        temp = temp->next;
    return (temp == head);
}

void display(struct Node *head)
{
    if (!head)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("List elements: ");

    if (isCircular(head))
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    else
    {
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = head; // circular list

    display(head);

    if (isCircular(head))
        printf("List is circular\n");
    else
        printf("List is not circular\n");

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

struct Node *last = NULL;

void insertEnd(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (!last)
    {
        last = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void splitList(struct Node *last, struct Node **firstHalf, struct Node **secondHalf)
{
    if (!last)
        return;
    struct Node *slow = last->next, *fast = last->next;
    while (fast->next != last->next && fast->next->next != last->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    *firstHalf = last->next;
    *secondHalf = slow->next;
    slow->next = *firstHalf;

    struct Node *temp = *secondHalf;
    while (temp->next != last->next)
        temp = temp->next;
    temp->next = *secondHalf;
}

void display(struct Node *last)
{
    if (!last)
        return;
    struct Node *temp = last->next;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}
void displayFromHead(struct Node *head)
{
    if (!head)
        return;
    struct Node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main()
{
    for (int i = 10; i <= 60; i += 10)
        insertEnd(i);

    printf("Original: ");
    display(last);

    struct Node *head1 = NULL, *head2 = NULL;
    splitList(last, &head1, &head2);

    printf("First half: ");
    displayFromHead(head1);
    printf("Second half: ");
    displayFromHead(head2);
    return 0;
}
