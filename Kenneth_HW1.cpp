#include <iostream> //libraries.
#include <cmath>
#include <fstream>
#include <string>
#include <math.h>
#include <iomanip>

using std::cout; //using from libraries.
using std::cin;
using std::endl;
using std::to_string;


    float cookiesPrice = 2.00; //defining constants
    float sodaPrice = 2.50;
    float chocolatePrice = 1.75;
    float chipsPrice = 1.50;
    float total = 0.0;

int main()
{                                                         //Initial prompt.
    cout << "Welcome to Superior Vending Machine" << endl;
    cout << endl;
    cout << "To checkout: type 'checkout'" << endl;
    cout << endl;

    std::ofstream write_receipt; //opening receipt file.
    write_receipt.open("receipt.txt");

    std::string order;    //Order Prompt.
    cout << endl;
    cout << "What would you like to order? " << endl;
    cout << "cookies $2.00. soda $2.50. chocolate $1.75. chips $1.50." << endl;
    cout << endl;
    cout << "Type:| '1' for cookies | '2' for soda | '3' for chocolate | '4' for chips |" << endl;
    cout << endl;
    cin >> order;
        while (order != "checkout") //loops until "checkout" is input.
        {
              if(order == "1") //records order to receipt and prompts for additional orders
              {
                    write_receipt << std::fixed;
                    write_receipt << std::setprecision(2); //sets output to receipt.txt to be 2 digits after decimal
                    write_receipt << "cookies: $" << cookiesPrice << endl; //writes order selection and corresponding price to reciept
                    total += cookiesPrice;
                    cout << endl;
                    cout << "You have selected cookies." << endl;
                    cout << endl;
                    cout << "Would you like to order anything else?" << endl;
                    cin >> order;
              }
              else if (order == "3") //follows cookies format
              {
                    write_receipt << std::fixed;
                    write_receipt << std::setprecision(2);
                    write_receipt << "chocolate: $" << chocolatePrice << endl;
                    total += chocolatePrice;
                    cout << endl;
                    cout << "You have selected chocolate." << endl;
                    cout << endl;
                    cout << "Would you like to order anything else?" << endl;
                    cin >> order;
              }
              else if (order == "4") //follows cookies format
              {
                    write_receipt << std::fixed;
                    write_receipt << std::setprecision(2);
                    write_receipt << "chips: $" << chipsPrice << endl;
                    total += chipsPrice;
                    cout << endl;
                    cout << "You have selected chips." << endl;
                    cout << endl;
                    cout << "Would you like to order anything else?" << endl;
                    cin >> order;
              }
              else if (order == "2") //follows cookies format
              {
                    write_receipt << std::fixed;
                    write_receipt << std::setprecision(2);
                    write_receipt << "soda: $" << sodaPrice << endl;
                    total += sodaPrice;
                    cout << endl;
                    cout << "You have selected soda." << endl;
                    cout << endl;
                    cout << "Would you like to order anything else?" << endl;
                    cin >> order;
              }
              else //prevents incorrect order input
              {
                    cout << endl;
                    cout << "Please enter a valid order." << endl;
                    cout << endl;
                    cin >> order;
              }
          }
    write_receipt.close();//closes file recepit.txt

                                            //Receipt prompt
    std::ifstream read_receipt; //opens receipt.txt for input only
    read_receipt.open("receipt.txt");
    cout << endl;
    cout << endl;
    cout << "Here is your receipt: " << endl;
    cout << endl;

    std::string final_order;
      while (std::getline(read_receipt, final_order)) //reads all lines from receipt.txt file and writes to variable: final_order
      {
            cout << final_order << endl; //prints receipt except for total
      }
    cout << endl;
    cout << std::fixed;
    cout << "Total: $"<< std::setprecision(2) << total; //outputs total to 2 digits after the decimal
    cout << endl;
    cout << endl;
    cout << "Goodbye. Thanks for ordering." << endl;
    read_receipt.close();
  return 0;
}
