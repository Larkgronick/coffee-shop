#include <iostream>
using namespace std;
void showMenu();

int main()
{
   int userchoice = 0;
   double byn = 0.0;
 
   while (true)
   {
     showMenu();
     cout << "Your choice? ";
     cin >> userchoice;
     
     switch (userchoice)
     {
     case 1:
        break;
     case 2:
        break;
     case 3:
        break;
     case 4:
        break;
     default:
      cout << "Input [1..5], please" << endl  << endl;
         break;
     }
     return 0;
   }
}

void showMenu()
{
   cout << "Bianchi LEI 700" << endl;
   cout << "Choose your coffee: " << endl;
   cout << "1) Espresso " << endl;
   cout << "2) Cappuccino " << endl;
   cout << "3) Latte" << endl;
   cout << "-----------------" << endl;
   cout << "4) Service menu" << endl;
}