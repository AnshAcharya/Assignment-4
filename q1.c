#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int last = 100;

typedef enum AccountType
{
    savings = 0,
    current = 1
} AccountType;

const char type[2][8] = {"savings", "current"};

typedef struct AccountInfo
{
    int num;
    AccountType AcountType;
    char name[50];
    float balance;

} AccountInfo;

typedef struct Node
{
    AccountInfo A;
    struct Node *next;
} Node;

typedef Node *LinkedList;

int compareAccountNumbers(const void *a, const void *b)
{
    return ((AccountInfo *)a)->num - ((AccountInfo *)b)->num;
}

// PART (a)
void display(LinkedList l)
{
    if (l == NULL)
    {
        printf("No Accounts to display\n");
        return;
    }

    int numAccounts = 0;
    LinkedList temp = l;

    while (temp != NULL)
    {
        numAccounts++;
        temp = temp->next;
    }

    AccountInfo *accountArray = (AccountInfo *)malloc(numAccounts * sizeof(AccountInfo));

    temp = l;
    int i = 0;
    while (temp != NULL)
    {
        accountArray[i] = temp->A;
        temp = temp->next;
        i++;
    }

    qsort(accountArray, numAccounts, sizeof(AccountInfo), compareAccountNumbers);

    printf("AccountNumber           AccountType          name            balance\n");
    printf("------------------------------------------------------------------------\n");
    for (i = 0; i < numAccounts; i++)
    {
        printf("%d\t\t\t%s\t\t\t%s\t\t\t%0.2f\n", accountArray[i].num, type[accountArray[i].AcountType], accountArray[i].name, accountArray[i].balance);
    }

    free(accountArray);
}

// PART (c)
void lowBalanceAccounts(LinkedList l)
{
    while (l != NULL)
    {
        if (l->A.balance < 100.0)
        {
            printf("Account Number: %d, Name : %s\n", l->A.num, l->A.name);
        }
        l = l->next;
    }
}

// PART (d)
LinkedList transaction(int accountNumber, float amount, int code, LinkedList l)
{
    LinkedList current = l;
    while (current != NULL)
    {
        if (current->A.num == accountNumber)
        {
            break;
        }
        else
        {
            current = current->next;
        }
    }
    if (current == NULL)
    {
        printf("Invalid: User does not exist\n");
        return l;
    }
    if (code == 1)
    {
        current->A.balance += amount;
        printf("Updated balance is Rs %.2f\n", current->A.balance);
        return l;
    }
    if (code == 0)
    {
        if ((current->A.balance - amount) < 100)
        {
            printf("The balance is insufficient for the specified withdrawal\n");
        }
        else
        {
            current->A.balance -= amount;
            printf("Updated balance is Rs %.2f\n", current->A.balance);
        }
        return l;
    }
}

//  PART(b.1)

LinkedList createAccount(AccountType A, char name[], float amount, LinkedList l)
{
    LinkedList temp0 = l;
    while (temp0 != NULL)
    {
        if (temp0->A.AcountType == A && strcmp(temp0->A.name, name) == 0)
        {
            printf("Invalid: User already exists!\n");
            return l;
        }
        temp0 = temp0->next;
    }
    LinkedList temp = l;
    Node *D = (Node *)malloc(sizeof(Node));
    D->next = NULL;
    D->A.num = last; // Assign the next available account number
    last++;          // Increment the last assigned account number
    strcpy(D->A.name, name);
    D->A.AcountType = A;
    D->A.balance = amount;
    if (temp == NULL)
    {
        return D;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = D;
        return l;
    }
}

// I used this so that condition so that Account numbers are proper
void handleAccountNumberDeletion(int accountNumber)
{
    if (accountNumber < last)
    {
        last = accountNumber;
    }
}

// PART (b.2)

LinkedList deleteAccount(AccountType A, char name[], LinkedList l)
{
    LinkedList current = l, prev = l;
    while (current != NULL)
    {
        if (current->A.AcountType == A && strcmp(name, current->A.name) == 0)
        {
            break;
        }
        else
        {
            current = current->next;
        }
    }
    if (current == NULL)
    {
        printf("Invalid: User does not exist\n");
        return l;
    }
    else
    {
        while (prev->next != current)
        {
            prev = prev->next;
        }
        prev->next = current->next;
        handleAccountNumberDeletion(current->A.num);
        free(current);
        return l;
    }
}

int main()
{
    LinkedList accounts = NULL;

    while (1)
    {
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "CREATE") == 0)
        {
            int type;
            char name[50];
            float amount;

            scanf("%d %s %f", &type, name, &amount);
            accounts = createAccount((AccountType)type, name, amount, accounts);
        }
        else if (strcmp(command, "DELETE") == 0)
        {
            int type;
            char name[50];

            scanf("%d %s", &type, name);
            accounts = deleteAccount((AccountType)type, name, accounts);
        }
        else if (strcmp(command, "TRANSACTION") == 0)
        {
            int accountNumber, code;
            float amount;

            
            scanf("%d", &accountNumber);
           
            scanf("%f", &amount);
            
            
            scanf("%d", &code);

            accounts = transaction(accountNumber, amount, code, accounts);
        }
        else if (strcmp(command, "LOWBALANCE") == 0)
        {
            lowBalanceAccounts(accounts);
        }
        else if (strcmp(command, "DISPLAY") == 0)
        {
            display(accounts);
        }
        else if(strcmp(command, "EXIT") == 0)
        {
            break;
        }
    }

    return 0;
}
