# Banking System in C++

A console-based **Banking System** developed in C++ as part of my programming internship. The project demonstrates the practical use of **Object-Oriented Programming (OOP), vectors, file handling, and basic banking operations**.

## Features

* Create and manage customers
* Create bank accounts for registered customers
* Search customers by Customer ID
* Search accounts by Account Number
* Deposit money
* Withdraw money
* Transfer money between accounts
* View account transaction history
* Store customer information using file handling
* Store account information using file handling
* Load saved customer and account data when the program starts
* Validate duplicate Customer IDs and Account Numbers
* Validate deposit, withdrawal, and transfer amounts

## OOP Concepts Used

The project uses several important Object-Oriented Programming concepts:

* **Classes and Objects** — Used to model customers, accounts, and transactions.
* **Encapsulation** — Important data members are kept private inside classes.
* **Constructors** — Used to initialize Customer, Account, and Transaction objects.
* **Member Functions** — Used to perform operations such as deposits, withdrawals, and transfers.
* **References** — Used during account-to-account fund transfers.
* **Vectors** — Used to dynamically store multiple customers, accounts, and transactions.

## Classes

### Customer

Stores customer-related information:

* Customer ID
* Name
* Phone Number

### Account

Stores account-related information and handles:

* Account Number
* Customer ID
* Account Balance
* Deposits
* Withdrawals
* Transfers
* Transaction history

### Transaction

Stores transaction information:

* Transaction ID
* Transaction Type
* Transaction Amount

## File Handling

The project uses C++ file handling to provide data persistence.

Two files are used:

* `customers.txt` — Stores customer information.
* `accounts.txt` — Stores account information and balances.

The program saves updated information to the files and loads the saved data when the program starts.

The `|` delimiter is used to keep different pieces of information separate inside the files.

## Technologies Used

* **Language:** C++
* **Concepts:** OOP, File Handling, Vectors, Functions, Loops, Conditional Statements
* **Libraries:**

  * `iostream`
  * `vector`
  * `iomanip`
  * `fstream`

## How to Run

1. Clone the repository:

```bash
git clone <repository-url>
```

2. Open the project in a C++ IDE such as **Code::Blocks, Visual Studio, or VS Code**.

3. Compile and run the program.

4. The program will automatically create and use the required text files for storing customer and account data.

## Main Menu

```text
======== Banking System ========

1). Create Customer
2). Create Account
3). Search Customer
4). Search Account
5). Deposit
6). Withdraw
7). Transfer
8). Show Transactions
9). Exit
```

## Learning Outcomes

Through this project, I practiced:

* Designing classes for a real-world problem
* Applying OOP principles in C++
* Working with `vector`
* Implementing constructors and member functions
* Using file input/output with `fstream`
* Reading and writing structured data to text files
* Managing relationships between customers and accounts
* Implementing validation and duplicate checking
* Building a complete console-based application

## Future Improvements

Some possible improvements for future versions include:

* Persistent transaction history using file handling
* Password authentication and user login
* Transaction dates and timestamps
* Account deletion
* Customer deletion
* Better input validation
* Improved security and data protection
* A graphical user interface

## Author

**Ali Hamza Akram**
BS Computer Science Student
C++ Programming Intern — CodeAlpha
