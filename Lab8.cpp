//Q1
#include <stdio.h>
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;

        printf("After iteration %d: ", i + 1);
        printArray(arr, n);
    }}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("\nSorted array: ");
    printArray(arr, n);

    return 0;
}

//Q2
#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;

        printf("After iteration %d: ", i + 1);
        printArray(arr, n);
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("\nSorted array: ");
    printArray(arr, n);
    return 0;
}

//Q3
#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void partialSelectionSort(int arr[], int n, int k)
{
    int i, j, min_idx, temp;

    if (k > n)
        k = n;

    for (i = 0; i < k; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;

        // printf("After iteration %d: ", i + 1);
        // printArray(arr, n);
    }
}

int main()
{
    int arr[] = {29, 10, 14, 37, 14, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    printf("Original array: ");
    printArray(arr, n);

    partialSelectionSort(arr, n, k);

    printf("Arr after partial selection sort (first %d elements sorted): ", k);
    printArray(arr, n);

    return 0;
}


//Q4
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void swapNodes(struct Node **head_ref, struct Node *prevX, struct Node *currX,
               struct Node *prevY, struct Node *currY)
{
    if (currX == currY)
        return;

    if (prevX != NULL)
        prevX->next = currY;
    else
        *head_ref = currY;

    if (prevY != NULL)
        prevY->next = currX;
    else
        *head_ref = currX;

    struct Node *temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

void selectionSortList(struct Node **head_ref)
{
    struct Node *i, *j, *min;
    struct Node *prev_i = NULL;
    struct Node *prev_j;
    struct Node *prev_min;

    for (i = *head_ref; i != NULL && i->next != NULL; prev_i = i, i = i->next)
    {
        min = i;
        prev_min = prev_i;

        for (prev_j = i, j = i->next; j != NULL; prev_j = j, j = j->next)
        {
            if (j->data < min->data)
            {
                min = j;
                prev_min = prev_j;
            }
        }

        if (min != i)
            swapNodes(head_ref, prev_i, i, prev_min, min);

        printf("List after iteration: ");
        printList(*head_ref);
    }
}

int main()
{
    struct Node *head = createNode(64);
    head->next = createNode(25);
    head->next->next = createNode(12);
    head->next->next->next = createNode(22);
    head->next->next->next->next = createNode(11);

    printf("Original list: ");
    printList(head);

    selectionSortList(&head);

    printf("\nSorted list: ");
    printList(head);

    return 0;
}


//Q5

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node *mergeSortedLists(struct Node *list1, struct Node *list2)
{
    struct Node dummy;
    struct Node *tail = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data <= list2->data)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1 != NULL)
        tail->next = list1;
    if (list2 != NULL)
        tail->next = list2;

    return dummy.next;
}

int main()
{
    struct Node *list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);

    struct Node *list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    struct Node *merged = mergeSortedLists(list1, list2);

    printf("\nMerged Sorted List: ");
    printList(merged);

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

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue *q, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(struct Queue *q)
{
    if (q->front == NULL)
        return -1; // empty

    struct Node *temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return value;
}

int isEmpty(struct Queue *q)
{
    return (q->front == NULL);
}

int front(struct Queue *q)
{
    if (q->front == NULL)
        return -1;
    return q->front->data;
}

void printQueue(struct Queue *q)
{
    struct Node *temp = q->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Queue *mergeSortedQueues(struct Queue *q1, struct Queue *q2)
{
    struct Queue *merged = createQueue();

    while (!isEmpty(q1) && !isEmpty(q2))
    {
        if (front(q1) <= front(q2))
            enqueue(merged, dequeue(q1));
        else
            enqueue(merged, dequeue(q2));
    }

    while (!isEmpty(q1))
        enqueue(merged, dequeue(q1));

    while (!isEmpty(q2))
        enqueue(merged, dequeue(q2));

    return merged;
}

int main()
{
    struct Queue *q1 = createQueue();
    struct Queue *q2 = createQueue();

    enqueue(q1, 1);
    enqueue(q1, 4);
    enqueue(q1, 7);

    enqueue(q2, 2);
    enqueue(q2, 3);
    enqueue(q2, 8);

    printf("Queue 1: ");
    printQueue(q1);
    printf("Queue 2: ");
    printQueue(q2);

    struct Queue *merged = mergeSortedQueues(q1, q2);

    printf("\nMerged Sorted Queue: ");
    printQueue(merged);

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

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue *q, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(struct Queue *q)
{
    if (q->front == NULL)
        return -1;

    struct Node *temp = q->front;
    int val = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return val;
}

int isEmpty(struct Queue *q)
{
    return (q->front == NULL);
}

int front(struct Queue *q)
{
    return q->front ? q->front->data : -1;
}

void printQueue(struct Queue *q)
{
    struct Node *t = q->front;
    while (t)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

struct Queue *mergeSortedQueues(struct Queue *q1, struct Queue *q2)
{
    struct Queue *merged = createQueue();
    while (!isEmpty(q1) && !isEmpty(q2))
    {
        if (front(q1) <= front(q2))
            enqueue(merged, dequeue(q1));
        else
            enqueue(merged, dequeue(q2));
    }
    while (!isEmpty(q1))
        enqueue(merged, dequeue(q1));
    while (!isEmpty(q2))
        enqueue(merged, dequeue(q2));
    return merged;
}

void selectionSort(int arr[], int start, int end)
{
    for (int i = start; i < end - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < end; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

struct Queue *hybridSortAndMerge(int arr[], int n, int chunkSize)
{
    int numChunks = (n + chunkSize - 1) / chunkSize;

    printf("Sorting chunks:\n");
    struct Queue **chunkQueues = (struct Queue **)malloc(numChunks * sizeof(struct Queue *));

    for (int i = 0; i < numChunks; i++)
    {
        int start = i * chunkSize;
        int end = (start + chunkSize < n) ? start + chunkSize : n;
        selectionSort(arr, start, end);

        printf("Chunk %d sorted: ", i + 1);
        for (int j = start; j < end; j++)
            printf("%d ", arr[j]);
        printf("\n");

        chunkQueues[i] = createQueue();
        for (int j = start; j < end; j++)
            enqueue(chunkQueues[i], arr[j]);
    }

    while (numChunks > 1)
    {
        int newCount = 0;
        for (int i = 0; i < numChunks; i += 2)
        {
            if (i + 1 < numChunks)
                chunkQueues[newCount++] = mergeSortedQueues(chunkQueues[i], chunkQueues[i + 1]);
            else
                chunkQueues[newCount++] = chunkQueues[i];
        }
        numChunks = newCount;
    }

    struct Queue *finalQueue = chunkQueues[0];
    free(chunkQueues);

    return finalQueue;
}

int main()
{
    int arr[] = {42, 15, 23, 4, 16, 8, 9, 55, 0, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    int chunkSize = 3;

    printf("Original array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    struct Queue *sortedQueue = hybridSortAndMerge(arr, n, chunkSize);

    printf("\nFinal Merged Sorted Queue:\n");
    printQueue(sortedQueue);

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

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue *q, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(struct Queue *q)
{
    if (!q->front)
        return -1;
    struct Node *temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (!q->front)
        q->rear = NULL;
    free(temp);
    return val;
}

int front(struct Queue *q)
{
    if (!q->front)
        return -1;
    return q->front->data;
}

int isEmptyQueue(struct Queue *q)
{
    return (q->front == NULL);
}

void printQueue(struct Queue *q)
{
    struct Node *temp = q->front;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Queue *mergeSortedQueues(struct Queue *q1, struct Queue *q2)
{
    struct Queue *merged = createQueue();
    while (!isEmptyQueue(q1) && !isEmptyQueue(q2))
    {
        if (front(q1) <= front(q2))
            enqueue(merged, dequeue(q1));
        else
            enqueue(merged, dequeue(q2));
    }
    while (!isEmptyQueue(q1))
        enqueue(merged, dequeue(q1));
    while (!isEmptyQueue(q2))
        enqueue(merged, dequeue(q2));
    return merged;
}

struct StackNode
{
    struct Queue *q;
    struct StackNode *next;
};

struct Stack
{
    struct StackNode *top;
};

struct Stack *createStack()
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->top = NULL;
    return s;
}

void push(struct Stack *s, struct Queue *q)
{
    struct StackNode *node = (struct StackNode *)malloc(sizeof(struct StackNode));
    node->q = q;
    node->next = s->top;
    s->top = node;
}

struct Queue *pop(struct Stack *s)
{
    if (!s->top)
        return NULL;
    struct StackNode *temp = s->top;
    struct Queue *q = temp->q;
    s->top = temp->next;
    free(temp);
    return q;
}

int isEmptyStack(struct Stack *s)
{
    return s->top == NULL;
}

void selectionSort(int arr[], int start, int end)
{
    for (int i = start; i < end - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < end; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

struct Queue *stackBasedMerge(int arr[], int n, int chunkSize)
{
    int numChunks = (n + chunkSize - 1) / chunkSize;
    struct Stack *s = createStack();

    printf("Sorting and pushing chunks to stack:\n");

    for (int i = 0; i < numChunks; i++)
    {
        int start = i * chunkSize;
        int end = (start + chunkSize < n) ? start + chunkSize : n;

        selectionSort(arr, start, end);
        struct Queue *q = createQueue();
        for (int j = start; j < end; j++)
            enqueue(q, arr[j]);

        printf("Chunk %d sorted: ", i + 1);
        printQueue(q);

        push(s, q);
    }

    printf("\nMerging using stack:\n");
    while (!isEmptyStack(s) && s->top->next != NULL)
    {
        struct Queue *q1 = pop(s);
        struct Queue *q2 = pop(s);

        struct Queue *merged = mergeSortedQueues(q1, q2);
        printf("Merged two queues: ");
        printQueue(merged);

        push(s, merged);
    }

    return pop(s);
}

int main()
{
    int arr[] = {42, 15, 23, 4, 16, 8, 9, 55, 0, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    int chunkSize = 3;

    printf("Original array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    struct Queue *result = stackBasedMerge(arr, n, chunkSize);

    printf("\nFinal merged sorted queue:\n");
    printQueue(result);

    return 0;
}

