#include <iostream>
using namespace std;
const int ESPRESSO_PRICE = 1;
const double CAPPUCCINO_PRICE = 1.5;
const double LATTE_PRICE = 1.5;
const int MINIMAL_PAYMENT = 1;
int cupsAmount = 7;
double balance = 0;

int loadMenu();
void showMenuItems();
bool checkCups(int);
bool checkPayment(double);
void insertPayment();
void orderCoffee(double, string);
void checkBalance(double);

int main()
{
   loadMenu();
}

int loadMenu()
{
   int userchoice = 0;
 
   while (true)
   {
     showMenuItems();
     cout << "Your choice? ";
     cin >> userchoice;
     
     switch (userchoice)
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

void showMenuItems()
{
   cout << "Dear customer, make your choice: " << endl;
   cout << "Balance: " << balance << " BYN" << endl;
   cout << "1) Deposit money " << endl;
   cout << "2) Espresso " << "("<< ESPRESSO_PRICE << ")" << endl;
   cout << "3) Cappuccino " << "("<< CAPPUCCINO_PRICE << ")" << endl;
   cout << "4) Latte " << "("<< LATTE_PRICE << ")" << endl;
   cout << "-----------------" << endl;
   cout << "5) Service menu" << endl;
}

bool checkCups(int cups)
{
   if (cups > 0)
   {
      return true;
   } else {
      return false;
   }
   
}

bool checkPayment(double payment)
{
 if(payment > 1) {
    balance += payment; 
 } else {
     cout << "The denomination of this bill is less than the allowed" << endl;
 }
 loadMenu();
}

void insertPayment(){
   double payment;
   if (checkCups(cupsAmount))
   {
      cout << "Please deposit money. Minimal note is " << MINIMAL_PAYMENT <<" BYN. Pay attention that the coffee machine doesn't give change" << endl;
      cin >> payment;
      checkPayment(payment);
   } else {
      cout << "We are very sorry but there are no cups left" << endl;
      loadMenu();
   }

}

void checkBalance(double price, string coffee)
{
   if (balance >= price)
   {
      balance = balance - price;
      cupsAmount--;
      cout << "progress" << endl;
      cout << "Here is the best " << coffee << " in the City. Please, help yourself!" << endl;  
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
      cout << "We are very sorry but there are no cups left" << endl;
   }
   loadMenu();
}
