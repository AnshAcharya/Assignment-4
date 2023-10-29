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

---
