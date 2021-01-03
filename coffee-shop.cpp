#include <iostream>
using namespace std;
//define
const int ESPRESSO_PRICE = 1;
const double CAPPUCCINO_PRICE = 1.5;
const double LATTE_PRICE = 1.5;
const int MINIMAL_PAYMENT = 1;
// to main
int cupsAmount = 7; 
double balance = 0;

int loadMenu();
int loadServiceOnly();
void showMenuItems();
bool checkCups(int);
void insertPayment();
void showCoinsVariants();
int showPaymentMenu();
void orderCoffee(double, string);
void checkBalance(double);

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
     default:
      cout << "Input [1..5], please" << endl  << endl;
      continue;
     }
     return 0;
   }

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
        balance += 0.10;
        loadMenu();
        break;
     case 2:
        balance += 0.20;
        loadMenu();
        break;
     case 3:
        balance += 0.50;
        loadMenu();
        break;
     case 4:
        balance += 1;
        loadMenu();
        break;
     case 5:
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
        cout << "Load service menu" << endl; // NIKITA'S PART
         break;
      default:
         cout << "Please, select service menu" << endl  << endl;
         continue;
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
      cout << "progress" << endl; // ADD PROGRESS FUNCTION
     
      while (true)
      {
         cout << "Here is the best " << coffee << " in the City. Please, help yourself!" << endl;
         cout << "Press 0 if Customer has taken his cup of coffee" << endl; 
         cout << "Your choice? ";
         cin >> userChoice;
         switch (userChoice)
         {
         case 0:
            loadMenu();
            break;
         default:
            cout << "Press 0 if Customer has taken his cup of coffee" << endl; 
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
