#include <iostream>
#include <fstream> // For files
#include <string>
#include <stdio.h>
#include<windows.h>
#include "Bank.h"

using namespace std;
/*COORD line = {0,0};
void pos(int x, int y)		
{	
	line.X=x;						
	line.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),line);
}*/

// Class Menu

class Menu
{
    public:
    Bank bank;// object of the Bank Class

    // This calls the method to load the files and the BST
    void load_file()
    {
    	bank.open_file();
	    bank.readFromFile();
	    bank.readFromFileUser();
	    bank.read_from_employee_file();
    }

    // This calls the method to close files
    void unload_file()
    {
        bank.close_file();
    }

    //Menu Method for existing account
    void existing_account(int account,int passcode)
    {
        system("cls");
        char choice='a';//Initialized with some random character

        while(choice!='0')
        {
            system("cls");
            pos(70,1);
            cout<<"---------------------------------------------"<<endl;
            pos(70,2);
			cout<<"---------------------------------------------"<<endl;
            pos(70,3);
			cout<<"                   USER                      "<<endl;
            pos(70,4);
			cout<<"---------------------------------------------"<<endl;
            pos(70,5);
			cout<<"---------------------------------------------"<<endl;
            pos(62,7);
			cout<<"1-Display Information";
			pos(62,9);
			cout<<"2-Check Balance";
			pos(62,11);
			cout<<"3-Withdraw Amount";
			pos(62,13);
			cout<<"4-Deposit Amount";
			pos(62,15);
			cout<<"5-Delete Account";
			pos(62,17);
			cout<<"6-back";
			pos(62,19);
			cout<<"Enter Choice:  ";
			pos(75,19);
            cin>>choice;
            switch(choice)
            {
                case '1':
                {
                    cout<<"Display Information"<<endl;
                    bank.search_account(account);
                    break;
                }
                case '2':
                {
                    cout<<"Check Balance"<<endl;
                    bank.checkBalance(account);
                    break;
                }
                case '3':
                {
                    cout<<"Withdraw Amount"<<endl;
                    bank.withdraw(account);
                    break;
                }
                case '4':
                {
                    cout<<"Deposit Amount"<<endl;
                    bank.deposit(account);
                    break;
                }
                case '5':
                {
                    char input;
                    cout<<"Delete Account"<<endl;
                    cout<<"Are you sure you want to delete account?\n1-Yes\t\t2-No"<<endl;
                    cin>>input;
                    if(input=='1')
                    {
                        bank.delete_account(account);
                        choice='0';
                    }
                    else if (input=='2')
                    {
                        cout<<"Cancelled!"<<endl;
                    }
                    else
                        cout<<"Invalid input"<<endl;
                    break;
                }
                case '6':
                {
                    cout<<"Back"<<endl;
                    choice='0';
                    system("cls");
                    break;
                }
                default:
                    cout<<"Invalid Input..Try Again"<<endl;
            }
        }
    }

    // method to login into existing account through password and account no
    void login_account()
    {
    	system("CLS");
        int account;
        int passcode;
        bool check;
        pos(70,1);
        cout<<"---------------------------------------------"<<endl;
        pos(70,2);
		cout<<"---------------------------------------------"<<endl;
        pos(70,3);
		cout<<"             LOGIN INT0 ACCOUNT              "<<endl;
        pos(70,4);
		cout<<"---------------------------------------------"<<endl;
        pos(70,5);
		cout<<"---------------------------------------------"<<endl;
        pos(62,7);
        cout<<"Enter Account no:";
        pos(81,7);
        cin>>account;
        pos(62,9);
        cout<<"Enter Password:";
        pos(76,9);
        cin>>passcode;
        
        check= bank.check_account(account,passcode); // calls method to confirm login
        
        if (check)
        {
        	existing_account(account,passcode);
		}     
        else
        {
          cout<<"Incorrect Account or Password.."<<endl;
          system("pause");
        }
    }

    //Menu for User's Side
    void user()
    {
        char choice='a';// initialized with some random character
        while (choice!='0')
        {
			system("cls");
			pos(70,1);
			cout<<"---------------------------------------------"<<endl;
			pos(70,2);
			cout<<"---------------------------------------------"<<endl;
			pos(70,3);
			cout<<"                   USER                      "<<endl;
			pos(70,4);
			cout<<"---------------------------------------------"<<endl;
			pos(70,5);
			cout<<"---------------------------------------------"<<endl;
			pos(62,7);
			cout<<"1-Create an Account";
			pos(62,9);
			cout<<"2-Existing Account";
			pos(62,11);
			cout<<"3-Back";
			pos(62,13);
			cout<<"4-Exit";
			pos(62,15);
			cout<<"Enter Choice : ";
			pos(79,15);
			cin>>choice;
			
			switch(choice)
			{
				case '1':
				{
					system("CLS");
					pos(70,1);
				    cout<<"---------------------------------------------"<<endl;
				    pos(70,2);
					cout<<"---------------------------------------------"<<endl;
				    pos(70,3);
					cout<<"               CREATE ACCOUNT                "<<endl;
				    pos(70,4);
					cout<<"---------------------------------------------"<<endl;
				    pos(70,5);
					cout<<"---------------------------------------------"<<endl;
				    bank.add_account();
				    break;
				}
				case '2':
				{
					system("CLS");
					pos(70,1);
				    cout<<"---------------------------------------------"<<endl;
				    pos(70,2);
					cout<<"---------------------------------------------"<<endl;
				    pos(70,3);
					cout<<"               EXISTING ACCOUNT              "<<endl;
				    pos(70,4);
					cout<<"---------------------------------------------"<<endl;
				    pos(70,5);
					cout<<"---------------------------------------------"<<endl<<endl<<endl;
				    login_account();
				    break;
				}
				case '3':
				{
				    cout<<"Back"<<endl;
				    choice='0';
				    system("cls");
				    break;
				}
				case '4':
				{
				    exit(1);
				}
				default:
				{
				 cout<<"Invalid Input..Try Again"<<endl;
				 system("pause");
				}
			}
        }
    }

    // Menu for Admin's side
    void admin()
    {
        int account;
        char choice='a'; //inialized with some random character
        while(choice!='0')
        {
            system("cls");
            pos(70,0);
            cout<<"---------------------------------------------"<<endl;
            pos(70,1);
			cout<<"---------------------------------------------"<<endl;
            pos(70,2);
			cout<<"                  ADMIN                      "<<endl;
            pos(70,3);
			cout<<"---------------------------------------------"<<endl;
            pos(70,4);
			cout<<"---------------------------------------------"<<endl;
			pos(62,6);
            cout<<"1-Register User";
            pos(62,8);
			cout<<"2-Delete User";
			pos(62,10);
			cout<<"3-Search";
			pos(62,12);
			cout<<"4-Display All Users";
			pos(62,14);
			cout<<"5-Search Employee";
			pos(62,16);
			cout<<"6-Display All Employee";
			pos(62,18);
			cout<<"7-Back";
			pos(62,20);
			cout<<"8-Exit";
			pos(62,22);
			cout<<"Enter Choice : ";
			pos(78,22);
            cin>>choice;
            switch(choice)
            {
                case '1':
                {
                	system("CLS");
                	pos(70,0);
                    cout<<"---------------------------------------------"<<endl;
                    pos(70,1);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,2);
					cout<<"               REGISTER ACCOUNT              "<<endl;
                    pos(70,3);
					cout<<"---------------------------------------------"<<endl;
                   	pos(70,4);
				    cout<<"---------------------------------------------"<<endl;
                    bank.add_account();
                    break;
                }
                case '2':
                {
                	system("CLS");
                	pos(70,1);
                    cout<<"---------------------------------------------"<<endl;
                    pos(70,2);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,3);
					cout<<"               DELETE ACCOUNT                "<<endl;
                    pos(70,4);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,5);
					cout<<"---------------------------------------------"<<endl;
                    pos(62,7);
					cout<<"Enter the Account No to delete : ";
                    pos(96,7);
					cin>>account;
                    bank.delete_account(account);
                    break;
                }
                case '3':
                {
                	system("CLS");
                	pos(70,1);
                    cout<<"---------------------------------------------"<<endl;
                    pos(70,2);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,3);
					cout<<"               SEARCH ACCOUNT                "<<endl;
                    pos(70,4);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,5);
					cout<<"---------------------------------------------"<<endl;
                    pos(62,7);
					cout<<"Enter the Account No to Search:";
                    pos(93,7);
					cin>>account;
                    bank.search_account(account);
                    break;
                }
                case '4':
                {
                	system("CLS");
                	pos(70,1);
                    cout<<"---------------------------------------------"<<endl;
                    pos(70,2);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,3);
					cout<<"       DISPLAY ALL THE ACCOUNTS/USER INFO    "<<endl;
                    pos(70,4);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,5);
					cout<<"---------------------------------------------"<<endl;
                    bank.display_information();
                    break;
                }
                case '5':
                {
                	system("CLS");
                	pos(70,1);
                    cout<<"---------------------------------------------"<<endl;
                    pos(70,2);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,3);
					cout<<"            SEARCH EMPLOYEE                   "<<endl;
                    pos(70,4);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,5);
					cout<<"---------------------------------------------"<<endl;
                    bank.search_employe();
                    break;
                }
                case '6':
                {
                	system("CLS");
                	pos(70,1);
                    cout<<"---------------------------------------------"<<endl;
                    pos(70,2);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,3);
					cout<<"           SHOW ALL EMPLOYEES                "<<endl;
                    pos(70,4);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,5);
					cout<<"---------------------------------------------"<<endl;
                    bank.show_all_employee();
                    break;
                }
                case '7':
                {
                    cout<<"Back"<<endl;
                    choice='0';
                    system("cls");
                    break;
                }
                case '8':
                {
                   exit(1);
                }
                default:
                    {
                     cout<<"Invalid Input..Try Again"<<endl;
                     system("pause");
                    }

            }
        }
    }
    
    void employee()
    {
    	system("CLS");
    	int choice;
    	pos(70,1);
    	cout<<"---------------------------------------------"<<endl;
        pos(70,2);
		cout<<"---------------------------------------------"<<endl;
        pos(70,3);
		cout<<"                  EMPLOYEE                   "<<endl;
        pos(70,4);
		cout<<"---------------------------------------------"<<endl;
        pos(70,5);
		cout<<"---------------------------------------------"<<endl;
        pos(62,7);
		cout<<"1. Add Employee";
		pos(62,9);
		cout<<"2. Search Employee";
		pos(62,11);
		cout<<"3. Delete Employee";
		pos(62,13);
		cout<<"4. Back";
        pos(62,15);
		cout<<"Enter Choice : ";
		pos(78,17);
    	cin>>choice;
    	switch(choice)
    	{
    		case 1:
    		{
    			system("CLS");
    			pos(70,1);
    			cout<<"---------------------------------------------"<<endl;
            	pos(70,2);
				cout<<"---------------------------------------------"<<endl;
               	pos(70,3);
				cout<<"              REGISTER EMPLOYEE              "<<endl;
                pos(70,4);
				cout<<"---------------------------------------------"<<endl;
                pos(70,5);
				cout<<"---------------------------------------------"<<endl;
    			bank.add_employee();
    			break;
    		}
    		case 2:
    			bank.search_employe();
    			break;
    		case 3:
    			int account;
    			cout<<"Enter Account Number: ";
    			cin>>account;
    			bank.delete_employee(account);
    			break;
    		case 4:
    			menu();
    			break;
    		default:
    			cout<<"Wrong Entrance"<<endl;
    		
    	}
    	employee();
	}

    //Main Menu
    void menu()
    {
		system("cls");
        int pass_admin=1234;
        int pass;
        char choice='a';// Initialized with some random character
        while(choice!='0')
        {
        	pos(70,5);
            cout<<"---------------------------------------------"<<endl;
            pos(70,6);
			cout<<"---------------------------------------------"<<endl;
            pos(70,7);
			cout<<"                MAIN MENU                    "<<endl;
            pos(70,8);
			cout<<"---------------------------------------------"<<endl;
            pos(70,9);
			cout<<"---------------------------------------------"<<endl;
            pos(62,12);
			cout<<"1-Admin";
			pos(62,14);
			cout<<"2-User";
			pos(62,16);
			cout<<"3-Employee";
			pos(62,18);
			cout<<"4-Exit";
			pos(62,20);
			cout<<"Enter Choice : ";
            cin>>choice;
            switch(choice)
            {
                case '1':
                {
                	pos(62,22);
                    cout<<"Enter the Password: "<<endl;
                    pos(83,22);
                    cin>>pass;
                    if(pass==pass_admin)
                    admin();
                    else
                    {
                       cout<<"----ERROR\nAccess Denied---"<<endl;
                       system("pause");
                       system("cls");
                    }
                    break;
                }
                case '2':
                {
                    user();
                    break;
                }
                case '3':
                {
                    employee();
                    break;
                }
                case '4':
                {
                	system("CLS");
                	pos(70,20);
                	cout<<"---------------------------------------------"<<endl;
                    pos(70,21);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,22);
					cout<<"              HOPE TO SEE YOU SOON           "<<endl;
                	pos(70,23);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,24);
					cout<<"---------------------------------------------"<<endl;
                    choice='0';
                    exit(0);
                    break;	
				}
                default:
                    cout<<"Invalid Input..Try Again"<<endl;
            }
        }

    }
};
