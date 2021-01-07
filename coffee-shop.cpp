#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;
#define PIN_ATTEMPTS 3
#define START_CUPS_AMOUNT 7
#define PIN "1234"

const int ESPRESSO_PRICE = 1;
const double CAPPUCCINO_PRICE = 1.5;
const double LATTE_PRICE = 1.5;
const int MINIMAL_PAYMENT = 1;
int cupsAmount = START_CUPS_AMOUNT; 
double balance = 0.0;
double totalBalance = 0.0;

void loadMenu();
void loadServiceOnly();
void showMenuItems();
void insertPayment();
void showCoinsVariants();
void showPaymentMenu();
void orderCoffee(double, string);
void checkBalance(double);
void showProgressBar();
bool checkCups(int);
bool checkPin();
string getPin();
void showServiceMenu();
int makeChoice();
int addCups(int);
void withdrawMoney();
void goToServicePart();


int main()
{
   loadMenu();
}

void loadMenu()
{
   system ("CLS");
   int userChoice = 0;
 
   while (true)
   {
     showMenuItems();
     userChoice = makeChoice();
     
     switch (userChoice)
     {
     case 1:
        insertPayment();
        break;
     case 2:
        orderCoffee(ESPRESSO_PRICE, "espresso");
        break;
     case 3:
        orderCoffee(CAPPUCCINO_PRICE, "cappuccino");
        break;
     case 4:
        orderCoffee(LATTE_PRICE, "latte");
        break;
     case 5: 
		  goToServicePart();
		  break;
     default:
        system ("CLS");
        cout << "Input [1..5], please" << endl;
        continue;
     }
   }
}

bool checkCups(int cups)
{
   return (cups > 0);
}

void showPaymentMenu()
{
   system ("CLS");
   int userChoice = 0;

    while (true)
   {
     showCoinsVariants();
     userChoice = makeChoice();
     
     switch (userChoice)
     {
     case 1:
        totalBalance += 0.10;
		  balance += 0.10;
        loadMenu();
        break;
     case 2:
        totalBalance += 0.20;
		  balance += 0.20;
        loadMenu();
        break;
     case 3:
        totalBalance += 0.50;
		  balance += 0.50;
        loadMenu();
        break;
     case 4:
        totalBalance += 1;
		  balance += 1;
        loadMenu();
        break;
     case 5:
     	  totalBalance += 2;
        balance += 2;
        loadMenu();
        break;
     default:
        system ("CLS");
        cout << "Input [1..5], please" << endl;
        continue;
     }
   }
}

void loadServiceOnly()
{
   system ("CLS");
   int userChoice = 0;

   while (true)
   { 
      cout << "We are very sorry but there are no cups left" << endl;
      cout << "---------------" << endl;
      cout << "5) Service" << endl;
      cout << "---------------" << endl << endl;
      userChoice = makeChoice();
      
      switch (userChoice)
      {
        case 5:
        goToServicePart();
         break;
      default:
         system ("CLS");
         cout << "Please, select service menu" << endl;
         continue;
      }
      if (cupsAmount != 0) {
      	break;
	  }
   }
}


void showMenuItems()
{  
   cout << "Dear customer, make your choice: " << endl << endl;
   cout << "Balance: "  << setw(13) << balance << " BYN" << endl;
   cout << "---------------" << endl;
   cout << "1) Deposit money | + $" << endl;
   cout << "2) Espresso " << setw(7) << "| " << ESPRESSO_PRICE << setw(6) << " BYN" << endl;
   cout << "3) Cappuccino " << setw(5) << "| " << CAPPUCCINO_PRICE << " BYN" << endl;
   cout << "4) Latte " << setw(10) << "| " << LATTE_PRICE << " BYN" << endl;
   cout << "---------------" << endl;
   cout << "5) Service menu" << endl << endl;
 
}

void showCoinsVariants()
{
   cout << "Please deposit coins" << endl << endl;
   cout << "Pay attention that the coffee machine doesn't give change" << endl;
   cout << "---------------" << endl;
   cout << "1) 10  coins   |" << endl;
   cout << "2) 20  coins   |" << endl;
   cout << "3) 50  coins   |" << endl;
   cout << "4)  1  BYN     |"  << endl;
   cout << "5)  2  BYN     |"  << endl ;
   cout << "---------------" << endl << endl;

}

void insertPayment(){
   double payment;
   if (checkCups(cupsAmount))
   {
      showPaymentMenu();
   } else {
      loadServiceOnly();
   }

}

void checkBalance(double price, string coffee)
{
   system ("CLS");

   int userChoice = 0; 

   if (balance >= price)
   {
      balance -= price;
      cupsAmount--;

      cout << "Making your coffee..." << endl;
      showProgressBar();
      cout << "Here is the best " << coffee << " in the City." << endl; 
//      std::cout << R"(
//        (   
//         )
//       c[]  
//       )" << '\n';
      cout << "Please, help yourself!" << endl << endl;
      
      while (true)
      {
         cout << "Press 0 if Customer has taken his cup of coffee" << endl << endl; 
         userChoice = makeChoice();
         switch (userChoice)
         {
         case 0:
            loadMenu();
            break;
         default:
            system ("CLS");
            cout << "Input [0] please" << endl;
            continue;
         }
      }
   } else {
      insertPayment();
   }
 
}

void orderCoffee(double price, string coffee)
{
   if (checkCups(cupsAmount))
   { 
      checkBalance(price, coffee);
   } else {
      loadServiceOnly();
   }
}

void showProgressBar()
{
  int barLength = 20;
   cout << "[";     
   for (int i = 0; i < barLength; i++) {         
      Sleep(100);       
      cout << ":";  
   }
   cout << "]" << endl << endl;  
}

bool checkPin ()
{
	string equalPin = PIN;
	bool isCorrect = true;
	string pinAttempt = getPin();
	
	if (pinAttempt.length() != equalPin.length()) {
		isCorrect = false;
	} else {
		for (int i = 0; i < pinAttempt.length(); i++) {
			if (pinAttempt[i] != equalPin[i]) {
				isCorrect = false;
				break;
			}
		}
	}	
	return isCorrect;
}

string getPin () 
{
	string pin;
	cout << "Please input PIN: ";
	cin >> pin;
	
	return pin;
}

void showServiceMenu () 
{
	cout << "Balance is " << totalBalance << " BYN" << endl ;
	cout << "There are " << cupsAmount << " cups loaded" << endl << endl;
	cout << "Choose the option:" << endl;
   cout << "---------------" << endl;
	cout << "1) Add cups" << endl;
	cout << "2) Withdrawal of proceeds" << endl;
	cout << "3) Back to main menu" << endl;
   cout << "---------------" << endl << endl;
}

int makeChoice () 
{
	int choice;
	
	cout << "Your choice: ";
	cin >> choice;
	
	return choice;		
}

int addCups(int currentAmount)
{
	system("cls");
	int addingAmount;
	
	cout << "How many cups are you adding? ";
	cin >> addingAmount;
	
	return currentAmount + addingAmount;	
}

void withdrawMoney()
{
	system("cls");
	cout << totalBalance << " BYN were given away." << endl;
	
	totalBalance = 0.0;
	balance = 0.0;
}

void goToServicePart() 
{
   system("cls");
	int serviceMenuChoice = 0;
	string pinAttempt = "";
	int pinAttemptsLeft = PIN_ATTEMPTS;
	bool isCorrectPin;
	
	do 
	{
		pinAttemptsLeft--;
		isCorrectPin = checkPin();
		if (isCorrectPin == false) {
         system("cls");
			cout << "PIN is wrong. There are " << pinAttemptsLeft << " attempts left." << endl << endl;  
		}
	} while (pinAttemptsLeft > 0 && isCorrectPin != true);
	
	if (isCorrectPin == true) {
		system ("cls");
		while (true) {
			showServiceMenu();
			serviceMenuChoice = makeChoice();
			if (serviceMenuChoice == 1) {
				cupsAmount = addCups(cupsAmount);
			} else if (serviceMenuChoice == 2) {
				withdrawMoney();
			} else if (serviceMenuChoice == 3) {	
            system ("cls");
				break;
			} else {
            system ("cls");
				cout << "Choose variants from 1 to 3." << endl;
			}
		}
	} else {
		cout << "The machine is blocked." << endl;
		exit (1);
	}
	return;		
}
