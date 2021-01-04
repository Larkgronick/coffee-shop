#include <iostream>
#include <windows.h>
using namespace std;
#define PIN_ATTEMPTS 3
#define START_CUPS_AMOUNT 0
//define
const int ESPRESSO_PRICE = 1;
const double CAPPUCCINO_PRICE = 1.5;
const double LATTE_PRICE = 1.5;
const int MINIMAL_PAYMENT = 1;
const string PIN = "1234";

// to main
int cupsAmount = START_CUPS_AMOUNT; 
double balance = 0;
double totalBalance = 0;


int loadMenu();
int loadServiceOnly();
void showMenuItems();
bool checkCups(int);
void insertPayment();
void showCoinsVariants();
int showPaymentMenu();
void orderCoffee(double, string);
void checkBalance(double);
int showProgressBar();
bool checkPin();
string getPin();
void showServiceMenu();
int makeChoice();
int addCups(int);
double withdrawMoney(double);
void goToServicePart();


int main()
{
   loadMenu();
}

int loadMenu()
{
   int userChoice = 0;
 
   while (true)
   {
     // to main
     showMenuItems();
     cout << "Your choice? ";
     cin >> userChoice;
     
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
      cout << "Input [1..5], please" << endl  << endl;
      continue;
     }
 }
     return 0;
   }



bool checkCups(int cups)
{
   return (cups > 0);
 
}

int showPaymentMenu()
{
   int userChoice = 0;

    while (true)
   {
     
     showCoinsVariants();
     cout << "Your choice? ";
     cin >> userChoice;
     
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
      cout << "Input [1..5], please" << endl  << endl;
      continue;
     }
     return 0;
   }
}

int loadServiceOnly()
{
   int userChoice = 0;

   while (true)
   {
      cout << "We are very sorry but there are no cups left" << endl;
      cout << "5) Service" << endl;
      cout << "Your choice? ";
      cin >> userChoice;
      
      switch (userChoice)
      {
        case 5:
        goToServicePart();
         break;
      default:
         cout << "Please, select service menu" << endl  << endl;
         continue;
      }
      if (cupsAmount != 0) {
      	break;
	  }
   }
   return 0;
}


void showMenuItems()
{
   cout << "Dear customer, make your choice: " << endl;
   cout << "Balance: " << balance << " BYN" << endl;
   cout << "1) Deposit money " << endl;
   cout << "2) Espresso " << "("<< ESPRESSO_PRICE << ")" << endl;
   cout << "3) Cappuccino " << "("<< CAPPUCCINO_PRICE << ")" << endl;
   cout << "4) Latte " << "("<< LATTE_PRICE << ")" << endl;
   cout << "-----------------" << endl;
   cout << "5) Service menu" << endl << endl;
}

void showCoinsVariants()
{
   cout << "Please deposit coins" << endl;
   cout << "Pay attention that the coffee machine doesn't give change" << endl;
   cout << "1) 10 coins" << endl;
   cout << "2) 20 coins" << endl;
   cout << "3) 50 coins" << endl;
   cout << "4) 1 BYN" << endl;
   cout << "5) 2 BYN" << endl << endl;

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
   int userChoice = 0; 
   if (balance >= price)
   {
      balance -= price;
      cupsAmount--;
      showProgressBar();
      cout << "Here is the best " << coffee << " in the City. Please, help yourself!" << endl;
   //   std::cout << R"(
   //      (   
   //       )
   //     c[]  
   //     )" << '\n';
      while (true)
      {
         cout << "Press 0 if Customer has taken his cup of coffee" << endl; 
         cout << "Your choice? ";
         cin >> userChoice;
         switch (userChoice)
         {
         case 0:
            loadMenu();
            break;
         default:
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

int showProgressBar()
{
  int barLength = 20;
   cout << "[";     
   for (int i = 0; i < barLength; i++) {         
      Sleep(100);       
      cout << ":";  
   }
   cout << "]" << endl << endl;  
   return 0;
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
	
	if (isCorrect == false) {
		cout << "PIN is wrong." << endl;
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
	//system("cls");
	cout << "Balance is " << totalBalance << " BYN" << endl;
	cout << "There are " << cupsAmount << " cups loaded" << endl;
	cout << "Choose the option:" << endl;
	cout << "1 - Add cups" << endl;
	cout << "2 - Withdrawal of proceeds" << endl;
	cout << "3 - Back to main menu" << endl;
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

double withdrawMoney(double currentBalance)
{
	system("cls");
	cout << currentBalance << " BYN were given away" << endl;
	
	totalBalance = 0.0;
	balance = 0.0;
	
	return totalBalance;
}

void goToServicePart() 
{
	int userChoice = 0;
	string pinAttempt = "";
	int pinAttemptsLeft;
	bool isCorrectPin;
	pinAttemptsLeft = PIN_ATTEMPTS;
	
	do 
	{
		pinAttemptsLeft--;
		isCorrectPin = checkPin();
	} while (pinAttemptsLeft > 0 && isCorrectPin != true);
	
	if (isCorrectPin == true) {
		system ("cls");
		while (true) {
			showServiceMenu();
			userChoice = makeChoice();
			if (userChoice == 1) {
				cupsAmount = addCups(cupsAmount);
			} else if (userChoice == 2) {
				totalBalance = withdrawMoney(totalBalance);
			} else if (userChoice == 3) {
				system ("cls");
				break;
			} else {
				cout << "Choose variants fron 1 to 3." << endl;
			}
		}
	} else {
		cout << "The machine is blocked" << endl;
		exit (1);
	}
	return;		
}
