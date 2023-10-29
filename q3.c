#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int color;
    struct Node *next;
} Node;

typedef Node *LinkedList;

LinkedList append(LinkedList l, int n)
{
    Node *x = (Node *)malloc(sizeof(Node));
    x->color = n;
    x->next = NULL;
    if (l == NULL)
        return x;
    else
    {
        LinkedList temp = l;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = x;
        return l;
    }
}

LinkedList modified_list(LinkedList l)
{
    LinkedList temp = l;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->color == (temp->next)->color)
        {
            LinkedList duplicate = temp->next;
            temp->next = duplicate->next;
            free(duplicate);
        }
        else
        {
            temp = temp->next;
        }
    }
    return l;
}

int main()
{
    LinkedList l = NULL;

    int n, color;
    printf("Enter the number of colors in the list: ");
    scanf("%d", &n);
    printf("Enter the colors: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &color);
        l = append(l, color);
    }

    l = modified_list(l);

    LinkedList temp = l;
    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            printf("%d\n", temp->color);
            break;
        }
        printf("%d->", temp->color);
        temp = temp->next;
    }

    while (l != NULL)
    {
        LinkedList temp = l;
        l = l->next;
        free(temp);
    }

    return 0;
}
