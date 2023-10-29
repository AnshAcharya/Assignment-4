# Question 1

## Structures and Enums

### AccountType (Enum)

- This enum defines the type of an account, which can be either `savings` or `current`.
- Enum Values:
  - `savings` (with a value of 0)
  - `current` (with a value of 1)

### AccountInfo (Struct)

- This struct represents the information of a bank account, including the account number, account type, name, and balance.
- Members:
  - `int num`: Account number
  - `AccountType AcountType`: Type of the account (savings or current)
  - `char name[50]`: Account holder's name
  - `float balance`: Account balance

### Node (Struct)

- This struct defines a node for a linked list, containing an `AccountInfo` structure and a pointer to the next node.
- Members:
  - `AccountInfo A`: Account information
  - `struct Node *next`: Pointer to the next node in the linked list

## Functions

### `compareAccountNumbers(const void *a, const void *b)`

- This function is used as a comparison function for `qsort` to sort an array of `AccountInfo` structures by their account numbers.
- It compares two account numbers and returns the difference between them.

### `display(LinkedList l)`

- This function displays the account information in a sorted order by account number.
- It takes a linked list of accounts as input and sorts the accounts before displaying them.

### `lowBalanceAccounts(LinkedList l)`

- This function prints the account numbers and names of accounts with a balance less than 100.

### `transaction(int accountNumber, float amount, int code, LinkedList l)`

- This function performs transactions on a specific account.
- It takes the account number, transaction amount, and transaction code as input and updates the account balance accordingly.

### `createAccount(AccountType A, char name[], float amount, LinkedList l)`

- This function creates a new account with the specified account type, name, and initial balance.
- It checks for duplicate account names before creating the account.

### `deleteAccount(AccountType A, char name[], LinkedList l)`

- This function deletes an account with the specified account type and name.
- It also updates the `last` account number to ensure proper assignment of account numbers in the future.


## Notes

- The `last` variable is used to keep track of the last assigned account number and is initialized to 100.

# Question 2

## Structures and Enums

### `operation` (Enum)

- This enum defines the mathematical operations that can be performed on complex numbers.
- Enum Values:
  - `ADD` (with a value of 1)
  - `SUB` (with a value of 2)
  - `COSINE` (with a value of 3)
  - `DOT` (with a value of 4)

### `num` (Struct)

- This struct represents a node in the linked list, containing a floating-point number and a pointer to the next node.
- Members:
  - `float x`: Floating-point value
  - `struct num *next`: Pointer to the next node in the linked list

## Functions

### `add(int n, LinkedList num1, LinkedList num2)`

- This function performs element-wise addition of two linked lists of floating-point numbers.
- It returns a new linked list containing the result.
- The function takes the number of elements (`n`), and two input linked lists (`num1` and `num2`).

### `sub(int n, LinkedList num1, LinkedList num2)`

- This function performs element-wise subtraction of two linked lists of floating-point numbers.
- It returns a new linked list containing the result.
- The function takes the number of elements (`n`), and two input linked lists (`num1` and `num2`).

### `freeLinkedList(LinkedList list)`

- This function frees the memory used by a linked list by traversing and deallocating all its nodes.
- It helps prevent memory leaks.

### `dot(int n, LinkedList num1, LinkedList num2)`

- This function calculates the dot product of two complex numbers.
- It returns the resulting dot product value.
- The function takes the number of elements (`n`), and two input linked lists (`num1` and `num2`).

### `magnitude(int n, LinkedList num)`

- This function calculates the magnitude of a complex number
- It returns the magnitude value.
- The function takes the number of elements (`n`) and the input linked list (`num`).

### `cosineSimilarity(int n, LinkedList num1, LinkedList num2)`

- This function calculates the cosine similarity between two complex numbers of floating-point numbers.
- It returns the cosine similarity value.
- The function takes the number of elements (`n`) and two input linked lists (`num1` and `num2`).

### `reverseLinkedList(LinkedList head)`

- This function reverses a linked list and returns the new head of the reversed list.
- It is used to reverse the result of addition or subtraction.

# Question 3

## Structures

### `Node` (Struct)

- This struct represents a node in the linked list, containing a color (represented by an integer) and a pointer to the next node.
- Members:
  - `int color`: Integer representing the color.
  - `struct Node *next`: Pointer to the next node in the linked list.

## Functions

### `append(LinkedList l, int n)`

- This function appends a new color to the end of the linked list.
- It returns the modified linked list.
- If the linked list (`l`) is initially empty, it creates the first node. Otherwise, it traverses the list to find the last node and appends the new color as a new node.

### `modified_list(LinkedList l)`

- This function modifies the linked list by removing consecutive duplicate colors.
- It returns the modified linked list.
- It iterates through the list and removes nodes whose color matches the color of the next node, effectively removing consecutive duplicates.

---


