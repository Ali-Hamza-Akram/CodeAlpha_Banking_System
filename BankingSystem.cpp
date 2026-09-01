#include<iostream>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std;

class Customer{
private:
    string customerID, name, phoneNo;

public:
    Customer(string customerID, string name, string phoneNo){
        this->customerID = customerID;
        this->name = name;
        this->phoneNo = phoneNo;
    }

    void displayInfo(){
        cout<<"Customer ID: "<<customerID<<endl
            <<"Name:        "<<name<<endl
            <<"PhoneNo:     "<<phoneNo<<endl;
    }

    string displayCustomerID(){
        return customerID;
    }
    string displayname(){
        return name;
    }
    string displayphoneNo(){
        return phoneNo;
    }
};

class Transaction{
private:
    string transactionID, type;
    float amount;

public:
    Transaction(string transactionID, string type, float amount){
        this->transactionID = transactionID;
        this->type = type;
        this->amount = amount;
    }

    void displayTransactionRow(){
        cout<<left<<setw(20)<<transactionID
            <<setw(20)<<type
            <<setw(15)<<amount<<endl;
    }
};

class Account{
private:
    string accountNo;
    string customerID;
    float balance;

public:
    Account(string customerID, string accountNo, float balance){
        this->customerID = customerID;
        this->accountNo = accountNo;
        this->balance = balance;
    }

    void displayInfo(){
        cout<<"Customer ID: "<<customerID<<endl
            <<"Account No:  "<<accountNo<<endl
            <<"Balance:     "<<balance<<endl;
    }

    string displayAccountNo(){
        return accountNo;
    }
        string displayCustomerID(){
        return customerID;
    }
    float displaybalance(){
        return balance;
    }

    vector<Transaction> transactions;

    void addTransaction(string type, float amount){

        int transactionNumber = transactions.size() + 101;
        string transactionID = "T" + to_string(transactionNumber);

        Transaction T1(transactionID, type, amount);
        transactions.push_back(T1);
    }

    void deposit(){
        displayInfo();

        float depositAmt;

        do{
            cout<<"\nEnter amount to deposit: ";
            cin>>depositAmt;

            if(depositAmt<=0){
                cout<<"Enter Valid Amount!";
            }
            else{
                balance = balance + depositAmt;

                cout<<"\nAmount Deposit Successfully!"<<endl;
                cout<<"Current Balance Now: "<<balance<<endl<<endl;
            }

        }while(depositAmt<=0);

        addTransaction("Deposit", depositAmt);
    }

    void withdraw(){
        displayInfo();

        float withdrawAmt;

        do{
            cout<<"\nEnter amount to withdraw: ";
            cin>>withdrawAmt;

            if(withdrawAmt<=0){
                cout<<"Enter Valid Amount!";
            }
            else if(withdrawAmt > balance){
                cout<<"Insufficient Balance!";
            }
            else{
                balance = balance - withdrawAmt;

                cout<<"\nAmount Withdrawan Successfully!"<<endl;
                cout<<"Current Balance Now: "<<balance<<endl<<endl;
            }

        }while(withdrawAmt<=0 || withdrawAmt > balance);

        addTransaction("Withdraw", withdrawAmt);
    }

    void transfer(Account& Receiver, float amount){

        if(balance<=0){
            cout<<"You have no balance in account"<<endl;
        }
        else if(amount<=0){
            cout<<"Enter Valid Amount"<<endl;
        }
        else if(amount>balance){
            cout<<"Insuffienct Balance!"<<endl;
        }
        else{
            balance = balance - amount;
            Receiver.balance = Receiver.balance + amount;

            cout<<"Amount Sent to: "<<Receiver.displayAccountNo()<<endl;
            cout<<"Remaining Balance: "<<balance;

            addTransaction("Transfer Sent", amount);
            Receiver.addTransaction("Transfer Recieved", amount);
        }
    }

    void showTransactions(){

        cout<<"\n\n\t  === Transaction Slip ===\n\n";

        cout<<left<<setw(20)<<"Transaction ID"
            <<setw(20)<<"Type"
            <<setw(15)<<"Amount"<<endl;

        cout<<"-------------------------------------------------------"<<endl;

        for(int i=0; i<transactions.size(); i++){
            transactions[i].displayTransactionRow();
        }
    }
};

vector<Customer> customers;
vector<Account> accounts;
string CustomerID, name, phoneNo, accountNo;
float balance;

void saveCustomers(){
    ofstream Writefile("customers.txt");

    for(int i = 0; i < customers.size(); i++){
        Writefile << customers[i].displayCustomerID() << "|"
          << customers[i].displayname() << "|"
          << customers[i].displayphoneNo() << endl;
    }
    Writefile.close();
}

void loadCustomers(){
    ifstream Readfile("customers.txt");
    string CustomerID, name, phoneNo;
    while(getline(Readfile, CustomerID, '|')&&
          getline(Readfile, name, '|')&&          
          getline(Readfile, phoneNo)
        ){

    Customer C(CustomerID, name, phoneNo);
    customers.push_back(C);
    }
    Readfile.close();
}

void saveAccounts(){
    ofstream Writefile("accounts.txt");

    for(int i = 0; i < accounts.size(); i++){
        Writefile << accounts[i].displayCustomerID() << "|"
          << accounts[i].displayAccountNo() << "|"
          << accounts[i].displaybalance() << endl;
    }
    Writefile.close();
}

void loadaccounts(){
    ifstream Readfile("accounts.txt");
    string CustomerID, accountNo;
    float balance;
    while(getline(Readfile, CustomerID, '|')&&
          getline(Readfile, accountNo, '|')&&          
          (Readfile>> balance)
        ){

    Account A(CustomerID, accountNo, balance);
    accounts.push_back(A);
    Readfile.ignore();
    }
    Readfile.close();
}

void createCustomer(){
        cout<<"\n=== Create Customer ==="<<endl;
    bool duplicate = false;

    do{
        duplicate = false;
        cout<<"\nEnter Customer ID: ";
        cin>>CustomerID;

        for(int i=0; i<customers.size(); i++){
            if(CustomerID == customers[i].displayCustomerID()){
                duplicate = true;
                cout<<"\nCustomer ID Already Exists!"<<endl;
                break;
            }
        }
    }while(duplicate == true);

    cout<<"Enter Customer Name: ";
    cin.ignore();
    getline(cin, name);
    cout<<"Enter Phone Number: ";
    cin>>phoneNo;

    Customer C(CustomerID, name, phoneNo);
    customers.push_back(C);
    saveCustomers();
    cout<<"\nCustomer Created Successfully!"<<endl;
}

void createAccount(){
          cout<<"\n=== Create Account ==="<<endl;

          cout<<"\nEnter Customer ID: ";
          cin>>CustomerID;

          bool found = false;

          for(int i=0; i<customers.size(); i++){
              if(CustomerID == customers[i].displayCustomerID()){

                  found = true;

                  cout<<"Customer Found!"<<endl;
                  customers[i].displayInfo();

                  cout<<"\n=== Account Creation ==="<<endl;
                  bool duplicate = false;

                  do{
                    duplicate = false;
                    cout<<"\nEnter Account Number: ";
                    cin>>accountNo;

                    for(int i=0; i<accounts.size(); i++){
                        if(accountNo == accounts[i].displayAccountNo()){
                            duplicate = true;
                            cout<<"\nAccount Already Exists!"<<endl;
                            break;
                        }
                    }
                  }while(duplicate == true);
                  
                  do{
                    cout<<"Enter Initial Balance: ";
                    cin>>balance;

                    if(balance < 0){
                        cout<<"Initial balance cannot be negative!"<<endl;
                    }

                 }while(balance < 0);

                  Account A(CustomerID, accountNo, balance);
                  accounts.push_back(A);
                  saveAccounts();
                  cout<<"Account Created Successfully!"<<endl;
                  break;
              }
          }
          if(found == false){
              cout<<"Customer not found!"<<endl;
          }
}

void searchCustomer(){
      cout<<"\n=== Search Customer ==="<<endl;

      cout<<"\nEnter Customer ID: ";
      cin>>CustomerID;

      bool found = false;

      for(int i=0; i<customers.size(); i++){
          if(CustomerID == customers[i].displayCustomerID()){
              found = true;

              cout<<"Customer Found!"<<endl;
              customers[i].displayInfo();
              break;
          }
      }
      if(found == false){
        cout<<"Customer not found!"<<endl;
      }
}

void searchAccount(){
    cout<<"\n=== Search Account ==="<<endl;

    cout<<"\nEnter Account Number: ";
    cin>>accountNo;

    bool accountfound = false;

    for(int i=0; i<accounts.size(); i++){
        if(accountNo == accounts[i].displayAccountNo()){
            accountfound = true;
            accounts[i].displayInfo();
            break;
        }
    }
    if(accountfound == false){
      cout<<"Account not found!"<<endl;
    }
}

void depositAmt(){

    cout<<"\n=== Deposit ==="<<endl;
    cout<<"\nEnter Account Number: ";
    cin>>accountNo;

    bool accountfound = false;

    for(int i=0; i<accounts.size(); i++){
        if(accountNo == accounts[i].displayAccountNo()){
            accountfound = true;
            accounts[i].deposit();
            saveAccounts();
            break;
        }
    }
    if(accountfound == false){
      cout<<"Account not found!"<<endl;
    } 

}

void withdrawAmt(){

    cout<<"\n=== Withdraw ==="<<endl;
    cout<<"\nEnter Account Number: ";
    cin>>accountNo;

    bool accountfound = false;

    for(int i=0; i<accounts.size(); i++){
        if(accountNo == accounts[i].displayAccountNo()){
            accountfound = true;
            accounts[i].withdraw();
            saveAccounts();
            break;
        }
    }
    if(accountfound == false){
      cout<<"Account not found!"<<endl;
    } 
}

void TransferAmt(){
    cout<<"\n=== Transfer ==="<<endl;

    cout<<"Enter Sender's Account Number: ";
    cin>>accountNo;
    float amount;
    int senderAccount;

    bool senderfound = false;
    bool recieverfound = false;

    for(int i=0; i<accounts.size(); i++){
        if(accountNo == accounts[i].displayAccountNo()){
            senderfound = true;
            senderAccount = i;

            cout<<"Enter Reciever's Account Number: ";
            cin>>accountNo;
            int recieverAccount;

            for(int i=0; i<accounts.size(); i++){
                if(accountNo == accounts[i].displayAccountNo()){
                    recieverfound = true;
                    recieverAccount = i;

                    if(senderAccount == recieverAccount){
                        cout<<"Sender and Reciever cannot be same"<<endl;
                    }
                    else{
                    cout<<"Enter Amount: ";
                    cin>>amount;
                    accounts[senderAccount].transfer(accounts[recieverAccount], amount);
                    saveAccounts();
                    }
                }  
            }
            if(recieverfound == false){
              cout<<"Account not found!"<<endl;
            }            
            break;
        }
    }

    if(senderfound == false){
      cout<<"Account not found!"<<endl;
    } 
    
}

void displayTransactions(){

    cout<<"\n=== Show Transactions ==="<<endl;
    cout<<"\nEnter Account Number: ";
    cin>>accountNo;

    bool accountfound = false;

    for(int i=0; i<accounts.size(); i++){
        if(accountNo == accounts[i].displayAccountNo()){
            accountfound = true;
            accounts[i].showTransactions();
            break;
        }
    }
    if(accountfound == false){
      cout<<"Account not found!"<<endl;
    } 
}


int main(){
    loadCustomers();
    loadaccounts();
    int choice;

    float balance;
    cout<<"\n======== Banking System ========"<<endl;
    do{
        cout<<"\n==== Main Menu ===="<<endl;

        cout<<"\n1). Create Customer";
        cout<<"\n2). Create Account";
        cout<<"\n3). Search Customer";
        cout<<"\n4). Search Account";
        cout<<"\n5). Deposit";
        cout<<"\n6). Withdraw";
        cout<<"\n7). Transfer";
        cout<<"\n8). Show Transactions";
        cout<<"\n9). Exit"<<endl;

        cout<<"\nEnter your Choice: ";
        cin>>choice;

        switch(choice){
        case 1:{
          createCustomer();
          break;
        }

        case 2:{
          createAccount();
          break;
      }
        
        case 3:{
          searchCustomer();
          break;
      }
      
        case 4:{
          searchAccount();
          break;
      }

        case 5:{
          depositAmt();
          break;
        }

        case 6:{
          withdrawAmt();
          break;
        }

        case 7:{
          TransferAmt();  
          break;
        }

        case 8:{
          displayTransactions();
          break;
        }

        case 9:
            cout<<"\nExiting Banking System..."<<endl;
            break;

        default:
            cout<<"\nInvalid Choice! Please try again."<<endl;
            break;
      }

    }while(choice != 9);
}