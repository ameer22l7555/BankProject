#pragma once
#include<iostream>
using namespace std;

template <class T>
class DList {
private:


	struct node {
	public:
		node* next;
		node* prev;
		T data;


		node()
		{
			next = 0;
			prev = 0;

		}
		node(T d, node* n, node* p)
		{
			data = d;
			next = n;
			prev = p;
		}
	};

	class ListIterator {
	private:
		node* iptr;
	public:
		ListIterator(node* ptr = 0)
		{
			iptr = ptr;
		}

		ListIterator& operator++() {
			if (iptr != nullptr) {
				iptr = iptr->next;
			}
			return *this;
		}

		T& operator* () const {
			if (iptr != nullptr) {
				return iptr->data;
			}
			else {
				throw std::runtime_error("Invalid iterator");
			}
		}
		ListIterator operator++(int) {
			ListIterator temp = *this;
			if (iptr != nullptr) {
				iptr = iptr->next;
			}
			return temp;
		}

		bool operator !=(const ListIterator& l)const
		{
			return iptr != l.iptr;
		}
		bool operator ==(const ListIterator& l)const
		{
			return iptr == l.iptr;
		}

	};


	node* head;
	node* tail;
	friend class ListIterator;

public:
	typedef ListIterator Iterator;
	Iterator begin()
	{
		Iterator I(head);
		return I;
	}
	Iterator end()
	{
		Iterator I(NULL);
		return I;
	}
	DList()
	{
		head = 0;
		tail = 0;
	}


	void addnode(T data)
	{
		node* temp = new node();
		temp->data = data;

		if (head == 0)
		{
			head = temp;
			tail = temp;
			temp->next = 0;
			temp->prev = 0;
		}
		else {
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
			temp->next = 0;


		}

	}


	void delet(const T data) {
		node* current = head;

		while (current != 0) {
			if (current->data == data) {
				if (current == head) {
					head = current->next;
					if (head != 0) {
						head->prev = 0;
					}
				}
				else {
					current->prev->next = current->next;
					if (current->next != 0) {
						current->next->prev = current->prev;
					}
				}
				delete current;
				break;
			}
			current = current->next;
		}

	}

	void sorting() {

		if (head == 0 || head->next == 0) {
			cout << " empty list " << endl;
		}
		T t1;
		bool swapped = true;
		while (swapped) {
			swapped = false;
			node* temp = head;


			while (temp->next != 0) {
				if (temp->data > temp->next->data) {

					t1 = temp->data;
					temp->data = temp->next->data;
					temp->next->data = t1;
					swapped = true;
				}

				temp = temp->next;
			}
		}
	}



};




class Date
{
private:
	int month;
	int date;
	int year;
public:
	Date(int month = 0, int date = 0, int year = 0)
	{
		this->year = year;
		this->month = month;
		this->date = date;
	}
	friend ostream& operator<<(ostream& cout, const Date& obj) {

		cout << " " << obj.date << " - " << obj.month << " - " << obj.year << endl;
		return cout;
	}
	friend istream& operator>>(istream& in, Date& obj)
	{
		cout << endl << " date of transaction: ";
		in >> obj.date;
		cout << " month of transaction: ";
		in >> obj.month;
		cout << " year of transaction: ";
		in >> obj.year;
		return  in;
	}
	~Date()
	{
		//
	}
};

class Time
{
private:
	int hours;
	int minutes;
public:
	Time(int hours = 0, int minutes = 0)
	{
		this->hours = hours;
		this->minutes = minutes;
	}
	friend ostream& operator<<(ostream& cout, const Time& obj) {

		cout << obj.hours << " : " << obj.minutes << endl;
		return cout;
	}
	friend istream& operator>>(istream& in, Time& obj)

	{
		cout << endl << " time of transaction: " << endl;
		cout << " enter hours: " << endl;
		in >> obj.hours;
		cout << " enter minutes: " << endl;
		in >> obj.minutes;
		return  in;
	}
	~Time()
	{
		//	
	}

};

class Transaction {
private:
	static int trans_Serial;
	int transactionID;
	Time transaction_time;
	Date transaction_date;
	string transaction_type;
	double transferred_amount;
	long account_number;
	friend class Account;


public:
	Transaction(int trid = 0, long ac = 0, Time Ttime = 0, Date Tdate = 0, string type = " ", double tram = 0.0, long acc = 0)
	{
		account_number = ac;
		transactionID = trid;
		transaction_time = Ttime;
		transaction_date = Tdate;
		transaction_type = type;
		transferred_amount = tram;
		account_number = acc;
	}
	Transaction(int Tr, string type)
	{
		account_number = 0;

		transaction_time = 0;
		transaction_date = 0;
		transaction_type = type;
		transferred_amount = 0;
		account_number = 0;
		transactionID = Tr;
	}

	friend istream& operator>>(istream& in, Transaction& obj) {

		cout << " enter date of transaction: " << endl;
		in >> obj.transaction_date;
		cout << " enter time of transaction: " << endl;
		in >> obj.transaction_time;
		cout << " enter amount transfered: " << endl;
		in >> obj.transferred_amount;
		return in;
	}
	friend ostream& operator<<(ostream& cout, const Transaction& obj) {
		cout << "Transaction ID: " << obj.transactionID << endl;
		cout << "Transaction Time: " << obj.transaction_time << endl;
		cout << "Transaction Date: " << obj.transaction_date << endl;
		cout << "Transaction Type: " << obj.transaction_type << endl;
		cout << "Transferred Amount: " << obj.transferred_amount << endl;
		cout << "Account Number: " << obj.account_number << endl;
		return cout;
	}
	bool operator==(const Transaction& other) const {
		return this->transactionID == other.transactionID;
	}


	~Transaction()
	{
		//
	}
};
class Account {
private:

	int Account_Number;
	string Account_Title;
	double Account_Balance;
	DList<Transaction> history;
	friend class Bank;


public:

	Account(int ac)
	{
		Account_Title = " ";
		Account_Number = ac;
		Account_Balance = 0;
	}
	Account()
		: Account_Title(" "), Account_Balance(0.0) {


		Account_Number = 0;
	}

	Account(int ac, const string& acctitle, double accbalance)
		: Account_Title(acctitle), Account_Balance(accbalance) {

		Account_Number = ac;
	}



	bool operator==(const Account& other) const {
		return this->Account_Number == other.Account_Number;
	}
	long getaccountnumber()
	{
		long acc;
		acc = Account_Number;
		return acc;
	}
	friend istream& operator>>(istream& in, Account& obj) {



		cout << " enter account title: " << endl;
		in >> obj.Account_Title;
		cout << " enter initial account balance: " << endl;
		in >> obj.Account_Balance;


		return in;
	}

	void credittransaction(const Transaction& transaction) {
		if (transaction.transferred_amount < 0) {
			cout << "Invalid Amount Entry" << endl;
		}
		else {
			this->Account_Balance += transaction.transferred_amount;
			history.addnode(transaction);
		}
	}


	void debittransaction(const Transaction& transaction) {
		if (this->Account_Balance >= transaction.transferred_amount) {
			this->Account_Balance -= transaction.transferred_amount;
			history.addnode(transaction);
		}
		else {
			cout << "Insufficient funds for debit transaction." << endl;
		}
	}


	void displayaccountdetails() {
		cout << "Account Number: " << Account_Number << endl;
		cout << "Account Title: " << Account_Title << endl;
		cout << "Account Balance: " << Account_Balance << endl;
		cout << "Transaction History:" << endl;



		DList<Transaction>::Iterator lit = history.begin();


		if (lit != 0) {
			while (lit != 0) {
				Transaction& transaction = *lit;

				cout << "TransactionID: " << transaction.transactionID << endl;

				cout << "Transaction Time: " << transaction.transaction_time << endl;

				cout << "Transaction Date: " << transaction.transaction_date << endl;

				cout << "Type: " << transaction.transaction_type << endl;

				cout << "Amount: " << transaction.transferred_amount << endl;
				++lit;
			}
		}
		else {
			cout << "No history of transactions" << endl;
		}
	}
};


class Bank {
private:
	DList<Account> accounts;

	int acc_serial;
	int trans_serial;

	friend class Account;
public:

	Bank()
	{
		acc_serial = 1;
		trans_serial = 1;
	}

	void removeaccount(int n)
	{
		Account taccount;
		DList<Account>::Iterator lit = accounts.begin();
		bool delet = false;
		while (delet == false & lit != 0) {

			taccount = *lit;
			if (taccount.Account_Number == n) {
				accounts.delet(taccount);
				cout << "Account with account number: " << n << " deleted successfully" << endl;
				delet = true;
			}
			lit++;
		}
	}
	void addaccount() {

		Account newAccount(acc_serial);
		cin >> newAccount;
		acc_serial = acc_serial + 1;

		accounts.addnode(newAccount);
		cout << "Account created successfully with account number: " << newAccount.Account_Number << endl;
	}


	void displayaccounts() {
		Account taccount;
		DList<Account>::Iterator lit = accounts.begin();

		if (lit != 0) {
			while (lit != 0) {
				taccount = *lit;
				cout << "Account Title: " << taccount.Account_Title << endl;
				cout << "Account Number: " << taccount.Account_Number;
				cout << endl;
				cout << "Acccount Balance: " << taccount.Account_Balance << endl;


				++lit;
			}
		}
		else {
			cout << "No Accounts in Bank." << endl;
		}
	}
	void transaction(int num)
	{
		Account taccount;


		string st;
		cout << "Enter type of your transaction: either credit or debit: ";
		cin >> st;
		Transaction trans(trans_serial, st);
		cin >> trans;

		DList<Account>::Iterator lit = accounts.begin();
		bool dele = false;
		while (lit != 0 && dele == false)
		{
			taccount = *lit;
			if (taccount.Account_Number == num) {
				if (st == "credit")
				{
					taccount.credittransaction(trans);
				}
				else if (st == "debit")
				{
					taccount.debittransaction(trans);
				}
				dele = true;
				trans_serial = trans_serial + 1;
			}
		}



		taccount.displayaccountdetails();
	}

};