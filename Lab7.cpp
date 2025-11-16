#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow! Cannot push %d\n", value);
    }
    else
    {
        stack[++top] = value;
        printf("%d pushed to stack.\n", value);
    }
}


void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! No elements to pop.\n");
    }
    else
    {
        printf("%d popped from stack.\n", stack[top--]);
    }
}
void display()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

//Q2
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;

void push(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed\n", value);
}

void pop()
{
    if (top == NULL)
        printf("Stack Underflow!\n");
    else
    {
        printf("%d popped\n", top->data);
        struct Node *temp = top;
        top = top->next;
        free(temp);
    }
}

void peek()
{
    if (top == NULL)
        printf("Stack is empty\n");
    else
        printf("Top element: %d\n", top->data);
}

void display()
{
    struct Node *temp = top;
    if (!temp)
        printf("Stack empty\n");
    else
    {
        printf("Stack: ");
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid\n");
        }
    }
}

//Q3
#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }

int main()
{
    char str[MAX];
    printf("Enter a string: ");
    gets(str);

    for (int i = 0; i < strlen(str); i++)
        push(str[i]);
    printf("Reversed string: ");
    while (top != -1)
        printf("%c", pop());
    printf("\n");
    return 0;
}


//Q4
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
};
struct Node *top = NULL;

void push(char c)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = c;
    newNode->next = top;
    top = newNode;
}

char pop()
{
    if (top == NULL)
        return '\0';
    char c = top->data;
    struct Node *temp = top;
    top = top->next;
    free(temp);
    return c;
}

int isBalanced(char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (top == NULL)
                return 0;
            char c = pop();
            if ((exp[i] == ')' && c != '(') ||
                (exp[i] == '}' && c != '{') ||
                (exp[i] == ']' && c != '['))
                return 0;
        }
    }
    return top == NULL;
}

int main()
{
    char exp[100];
    printf("Enter expression: ");
    gets(exp);
    if (isBalanced(exp))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}


//Q5
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enqueue(int val)
{
    if (rear == MAX - 1)
        printf("Queue Overflow!\n");
    else
    {
        if (front == -1)
            front = 0;
        queue[++rear] = val;
        printf("%d enqueued\n", val);
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
        printf("Queue Underflow!\n");
    else
        printf("%d dequeued\n", queue[front++]);
}

void display()
{
    if (front == -1 || front > rear)
        printf("Queue empty\n");
    else
    {
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid\n");
        }
    }
}


//Q6
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL, *rear = NULL;

void enqueue(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (rear == NULL)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued\n", val);
}

void dequeue()
{
    if (front == NULL)
        printf("Queue Underflow!\n");
    else
    {
        printf("%d dequeued\n", front->data);
        struct Node *temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        free(temp);
    }
}

void display()
{
    if (front == NULL)
        printf("Queue empty\n");
    else
    {
        struct Node *temp = front;
        printf("Queue: ");
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid\n");
        }
    }
}


//Q7
#include <stdio.h>
#define SIZE 5 // Define maximum size of the circular queue

int queue[SIZE];
int front = -1, rear = -1;

int isFull()
{
    return ((rear + 1) % SIZE == front);
}

int isEmpty()
{
    return (front == -1);
}

void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue is FULL! Cannot insert %d\n", value);
    }
    else
    {
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % SIZE;
        }
        queue[rear] = value;
        printf("%d enqueued to queue.\n", value);
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is EMPTY! Cannot dequeue.\n");
    }
    else
    {
        printf("%d dequeued from queue.\n", queue[front]);
        if (front == rear)
        {
            // Queue becomes empty
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is EMPTY!\n");
    }
    else
    {
        printf("Queue elements: ");
        int i = front;
        while (1)
        {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

void next(int c)
{
    if (isEmpty())
    {
        printf("Queue is EMPTY! No next element.\n");
    }
    else
    {
        printf("Next element (front): %d\n", queue[(front + c) % SIZE]);
    }
}

int main()
{
    int choice, value;
    int count;

    printf("Circular Queue Implementation (Array)\n");
    printf("---------------GAME ON---------------------\n");

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Next Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        count++;

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            next(count);
            break;
        case 5:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}

//Q8
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct item
{
    int data;
    int priority;
};

struct PriorityQueue
{
    struct item arr[MAX];
    int size;
};

void enqueue(struct PriorityQueue *pq, int data, int priority)
{
    if (pq->size == MAX)
    {
        printf("Queue is full\n");
        return;
    }
    pq->arr[pq->size].data = data;
    pq->arr[pq->size].priority = priority;
    pq->size++;
}

void dequeue(struct PriorityQueue *pq)
{
    if (pq->size == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    int highestPriorityIndex = 0;
    for (int i = 1; i < pq->size; i++)
    {
        if (pq->arr[i].priority > pq->arr[highestPriorityIndex].priority)
            highestPriorityIndex = i;
    }

    printf("Dequeued element: %d (Priority %d)\n",
           pq->arr[highestPriorityIndex].data,
           pq->arr[highestPriorityIndex].priority);

    
    for (int i = highestPriorityIndex; i < pq->size - 1; i++)
    {
        pq->arr[i] = pq->arr[i + 1];
    }
    pq->size--;
}

void display(struct PriorityQueue *pq)
{
    if (pq->size == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Priority Queue Elements:\n");
    for (int i = 0; i < pq->size; i++)
    {
        printf("Data: %d, Priority: %d\n", pq->arr[i].data, pq->arr[i].priority);
    }
}

int main()
{
    struct PriorityQueue pq;
    pq.size = 0;

    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 5);
    enqueue(&pq, 30, 1);
    display(&pq);

    dequeue(&pq);
    display(&pq);

    return 0;
}

//Q8
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct item
{
    int data;
    int priority;
};

struct PriorityQueue
{
    struct item arr[MAX];
    int size;
};

void enqueue(struct PriorityQueue *pq, int data, int priority)
{
    if (pq->size == MAX)
    {
        printf("Queue is full\n");
        return;
    }
    pq->arr[pq->size].data = data;
    pq->arr[pq->size].priority = priority;
    pq->size++;
}

void dequeue(struct PriorityQueue *pq)
{
    if (pq->size == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    int highestPriorityIndex = 0;
    for (int i = 1; i < pq->size; i++)
    {
        if (pq->arr[i].priority > pq->arr[highestPriorityIndex].priority)
            highestPriorityIndex = i;
    }

    printf("Dequeued element: %d (Priority %d)\n",
           pq->arr[highestPriorityIndex].data,
           pq->arr[highestPriorityIndex].priority);

    
    for (int i = highestPriorityIndex; i < pq->size - 1; i++)
    {
        pq->arr[i] = pq->arr[i + 1];
    }
    pq->size--;
}


void display(struct PriorityQueue *pq)
{
    if (pq->size == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Priority Queue Elements:\n");
    for (int i = 0; i < pq->size; i++)
    {
        printf("Data: %d, Priority: %d\n", pq->arr[i].data, pq->arr[i].priority);
    }
}

int main()
{
    struct PriorityQueue pq;
    pq.size = 0;

    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 5);
    enqueue(&pq, 30, 1);
    display(&pq);

    dequeue(&pq);
    display(&pq);

    return 0;
}

//Q9
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct Deque
{
    int arr[SIZE];
    int front, rear;
};

void initDeque(struct Deque *dq)
{
    dq->front = -1;
    dq->rear = -1;
}

int isFull(struct Deque *dq)
{
    return ((dq->front == 0 && dq->rear == SIZE - 1) || (dq->front == dq->rear + 1));
}

int isEmpty(struct Deque *dq)
{
    return (dq->front == -1);
}

void insertFront(struct Deque *dq, int item)
{
    if (isFull(dq))
    {
        printf("Deque is full\n");
        return;
    }
    if (dq->front == -1)
    {
        dq->front = dq->rear = 0;
    }
    else if (dq->front == 0)
    {
        dq->front = SIZE - 1;
    }
    else
    {
        dq->front--;
    }
    dq->arr[dq->front] = item;
}

void insertRear(struct Deque *dq, int item)
{
    if (isFull(dq))
    {
        printf("Deque is full\n");
        return;
    }
    if (dq->front == -1)
    {
        dq->front = dq->rear = 0;
    }
    else if (dq->rear == SIZE - 1)
    {
        dq->rear = 0;
    }
    else
    {
        dq->rear++;
    }
    dq->arr[dq->rear] = item;
}

void deleteFront(struct Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted from front: %d\n", dq->arr[dq->front]);
    if (dq->front == dq->rear)
    {
        dq->front = dq->rear = -1;
    }
    else if (dq->front == SIZE - 1)
    {
        dq->front = 0;
    }
    else
    {
        dq->front++;
    }
}

void deleteRear(struct Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted from rear: %d\n", dq->arr[dq->rear]);
    if (dq->front == dq->rear)
    {
        dq->front = dq->rear = -1;
    }
    else if (dq->rear == 0)
    {
        dq->rear = SIZE - 1;
    }
    else
    {
        dq->rear--;
    }
}

void display(struct Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    int i = dq->front;
    while (1)
    {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main()
{
    struct Deque dq;
    initDeque(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    display(&dq);

    deleteRear(&dq);
    deleteFront(&dq);
    display(&dq);

    return 0;
}

//Q10
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
char stack[MAX];
char queue[MAX];
int top = -1, front = 0, rear = -1;
void push(char c)
{
    stack[++top] = c;
}
void enqueue(char c)
{
    queue[++rear] = c;
}
int isPalindrome(char str[])
{
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        if (isalnum(str[i]))
        {
            char c = tolower(str[i]);
            push(c);
            enqueue(c);
        }
    }

    for (int i = 0; i <= rear; i++)
    {
        if (stack[top--] != queue[i])
            return 0;
    }
    return 1;
}

int main()
{
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0'; 

    if (isPalindrome(str))
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    return 0;
}


