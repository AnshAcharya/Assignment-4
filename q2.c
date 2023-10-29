#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum operation
{
    ADD = 1,
    SUB = 2,
    COSINE = 3,
    DOT = 4
} oper;

typedef struct num
{
    float x;
    struct num *next;
} num;

typedef num *LinkedList;

LinkedList add(int n, LinkedList num1, LinkedList num2)
{
    LinkedList head = NULL;
    LinkedList temp = NULL;

    for (int i = 0; i < n; i++)
    {
        LinkedList newNode = (LinkedList)malloc(sizeof(struct num));
        newNode->x = num1->x + num2->x;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }

        num1 = num1->next;
        num2 = num2->next;
    }
    return head;
}

LinkedList sub(int n, LinkedList num1, LinkedList num2)
{
    LinkedList head = NULL;
    LinkedList temp = NULL;

    for (int i = 0; i < n; i++)
    {
        LinkedList newNode = (LinkedList)malloc(sizeof(struct num));
        newNode->x = num1->x - num2->x;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }

        num1 = num1->next;
        num2 = num2->next;
    }
    return head;
}

void freeLinkedList(LinkedList list)
{
    while (list != NULL)
    {
        LinkedList temp = list;
        list = list->next;
        free(temp);
    }
}

float dot(int n, LinkedList num1, LinkedList num2)
{
    float dot = 0.0;
    for (int i = 0; i < n; i++)
    {
        dot += (num1->x) * (num2->x);
        num1 = num1->next;
        num2 = num2->next;
    }
    return dot;
}

float magnitude(int n, LinkedList num)
{
    return sqrt(dot(n, num, num));
}

float cosineSimilarity(int n, LinkedList num1, LinkedList num2)
{
    return (dot(n, num1, num2) / (magnitude(n, num1) * magnitude(n, num2)));
}

LinkedList reverseLinkedList(LinkedList head) {
    LinkedList prev = NULL;
    LinkedList current = head;
    LinkedList next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;  // New head of the reversed list
}

int main()
{
    for (;;)
    {
        int n;
        char operation[10];
        oper choice;
        scanf("%s %d", operation, &n);

        if (strcmp(operation, "ADD") == 0)
        {
            choice = ADD;
        }
        else if (strcmp(operation, "SUB") == 0)
        {
            choice = SUB;
        }
        else if (strcmp(operation, "COSINE") == 0)
        {
            choice = COSINE;
        }
        else if (strcmp(operation, "DOT") == 0)
        {
            choice = DOT;
        }
        else
        {
            return 0;
        }

        LinkedList num1 = NULL;
        LinkedList num2 = NULL;

       
        for (int i = 0; i < n; i++)
        {
            float value;
            scanf("%f", &value);

            LinkedList newNode = (LinkedList)malloc(sizeof(struct num));
            newNode->x = value;
            newNode->next = num1;
            num1 = newNode;
        }
       
        for (int i = 0; i < n; i++)
        {
            float value;
            scanf("%f", &value);

            LinkedList newNode = (LinkedList)malloc(sizeof(struct num));
            newNode->x = value;
            newNode->next = num2;
            num2 = newNode;
        }

        printf("> Result: ");

        if (choice == ADD)
        {
            LinkedList result = reverseLinkedList(add(n, num1, num2));
            while (result != NULL)
            {
                printf("%.2f ", result->x);
                result = result->next;
            }
            freeLinkedList(result);
            printf("\n");
        }
        else if (choice == SUB)
        {
            LinkedList result = reverseLinkedList(sub(n, num1, num2));
            while (result != NULL)
            {
                printf("%.2f ", result->x);
                result = result->next;
            }
            freeLinkedList(result);
            printf("\n");
        }
        else if (choice == COSINE)
        {
            printf("%.2f\n", cosineSimilarity(n, num1, num2));
        }
        else if (choice == DOT)
        {
            printf("%.2f\n", dot(n, num1, num2));
        }

        freeLinkedList(num1);
        freeLinkedList(num2);
    }

    return 0;
}
