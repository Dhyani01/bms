//***************************************************************
//                   HEADER FILES USED IN PROJECT
//****************************************************************

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void print(T t, V... v) {_print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}


//***************************************************************
//                   CLASSES  & FUNCTIONS USED IN PROJECT
//****************************************************************

class account
{
	int acno;
	char name[30];
	int deposit;
	char type;
public:
	void create_account();		//function to get data from user

	void show_account() const;	//function to show data on screen

	void modify();			//function to add new data

	void dep(int);			//function to accept amount and add to balance amount

	void draw(int);			//function to accept amount and subtract from balance amount

	void report() const;		//function to show data in tabular format

	int retacno() const;		//function to return account number

	int retdeposit() const;		//function to return balance amount

	char rettype() const;		//function to return type of account

};         				//class ends here


int totamt;

void account::create_account()
{
	cout<<"\nEnter The account No. : ";
	cin>>acno;
	cout<<"\n\nEnter The Name of The account Holder : ";
	cin.ignore();
	cin.getline(name,30);
	cout<<"\nEnter Type of The account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin>>deposit;
	cout<<"\n\n\nAccount Created..";
}



void account::show_account() const
{
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nAccount Holder Name : ";
	cout<<name;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit;
}




void account::modify()
{
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,30);
	cout<<"\nModify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nModify Balance amount : ";
	cin>>deposit;
}



void account::dep(int x)
{
	deposit+=x;
}


void account::draw(int x)
{
	deposit-=x;
}


void account::report() const
{
  cout<<endl<<acno<<setw(5)<<" "<<name<<setw(30-strlen(name))<<" "<<type<<setw(8)<<" "<<deposit<<endl<<endl;
  totamt=totamt+deposit;
}



int account::retacno() const
{
	return acno;
}



int account::retdeposit() const
{
	return deposit;
}



char account::rettype() const
{
	return type;
}


//***************************************************************
//    	function declaration
//****************************************************************

void write_account();			//function to write record in binary file

void display_sp(int);			//function to display account details given by user

void modify_account(int);		//function to modify record of file

void delete_account(int);		//function to delete record of file

void display_all();			//function to display all account details

void deposit_withdraw(int, int); 	// function to desposit/withdraw amount for given account

void intro();				//introductory screen function


//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************


int main()
{
	char ch;
	int num;
	intro();
	do
	{
		system("cls");
		cout<<"******************* MAIN MENU *********************";
		cout<<"\n\n       1. CREATE NEW ACCOUNT                   ";
		cout<<"\n\n       2. DEPOSIT AMOUNT                       ";
		cout<<"\n\n       3. WITHDRAW AMOUNT                      ";
		cout<<"\n\n       4. BALANCE ENQUIRY                      ";
		cout<<"\n\n       5. LIST OF ALL ACCOUNTS                 ";
		cout<<"\n\n       6. CLOSURE OF ACCOUNT                   ";
		cout<<"\n\n       7. MODIFICATION OF ACCOUNT              ";
		cout<<"\n\n       8. EXIT                                 ";
		cout<<"\n\n       Select Your Option (1-8) ";
		cin>>ch;
		system("cls");
		cout<<endl;
		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		 case '7':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			modify_account(num);
			break;
		 case '8':
			system("cls");
			cout<<"\n\n\t      Thanks for using     \n";
			cout<<"\n\n\t     Bank Managemnt System \n";
			cout<<"\n\n\t        See You Again      \n";
			break;
		 default :
			cout<<"\a";
		}
		cin.ignore();
		cin.get();
    }while(ch!='8');
	return 0;
}



//***************************************************************
//    	function to write in file
//****************************************************************

void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write((char *) (&ac), sizeof(account));
	outFile.close();
}


//***************************************************************
//    	function to read specific record from file
//****************************************************************


void display_sp(int n)
{
	account ac;
	char flag = 'F' ;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";
	while(inFile.read((char *) (&ac), sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag='T';
		}
	}
    inFile.close();
	if (flag=='F')
		cout<<"\n\nAccount number does not exist";
}



//***************************************************************
//    	function to modify record of file
//****************************************************************


void modify_account(int n)
{
	char found='F';
	account ac;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}

	while(!File.eof() && found== 'F')
	{
		File.read((char *) (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*(sizeof(account));
			File.seekp(pos,ios::cur);
		    File.write((char *) (&ac), sizeof(account));
		    cout<<"\n\n\t Record Updated";
		    found='T';
		  }
	}

	File.close();
	if(found=='F')
		cout<<"\n\n Record Not Found ";
}


//***************************************************************
//    	function to delete record of file
//****************************************************************


void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if (!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) (&ac), sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write((char *) (&ac), sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\n\tAccount Deleted ..";
}


//***************************************************************
//    	function to display all accounts deposit list
//****************************************************************

void display_all()
{
	system("cls");
	totamt=0;
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"=======================================================\n";
	cout<<"A/c no.      NAME                     A/c Type  Balance\n";
	cout<<"=======================================================\n";
	while(inFile.read((char *) (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
	cout<<"=======================================================\n";
	cout<<"                         Total Amount : Rs."<<totamt<<"\n";
	cout<<"=======================================================\n";
}

//***************************************************************
//    	function to deposit and withdraw amounts
//****************************************************************

void deposit_withdraw(int n, int option)
{
	int amt;
	char found= 'F';
	char trans= 'F';
	account ac;
	fstream File;
	File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found== 'F')
	{
		File.read((char *) (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSIT AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited";
				cin>>amt;
				ac.dep(amt);
				trans='T';
			}
		    if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					{
					cout<<"Insufficience balance";
					}
				else
					{
					ac.draw(amt);
					trans='T';
					}
		      }
			int pos=(-1)*(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write((char *) (&ac), sizeof(account));
			if (trans== 'T')
			{
			cout<<"\n\n\t Transaction Successful";
			cout<<"\n\n\t Record Updated";
			}
			found='T';
	       }
	 }
    File.close();
	if(found=='F' && trans == 'F')
		cout<<"\n\n Record Not Found ";
}


//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{
	system("cls") ;
	cout<<"\n\n\n\t   BANKING ";
	cout<<"\n\n\n\t MANAGEMENT";
	cout<<"\n\n\n\t    SYSTEM ";
	cout<<"\n\n\n\nMADE BY : YASH THAKUR";
	cout<<"\n\n\n\nSCHOOL  : KV PUSHP VIHAR";
	cin.get();
}




void account::information()
{
	cout<<"\nEnter The account No. : ";
	cin>>acno;
	cout<<"\n\nEnter The Name of The account Holder : ";
	cin.ignore();
	cin.getline(name,30);
	cout<<"\nEnter Type of The account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\n\nAccount Information is:";
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************