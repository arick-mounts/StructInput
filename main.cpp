#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
 *
 *This program reads data from a .csv file and 
 *places that data into an array of 'product' Structs.
 *The program reads as many as 64 products.
 *The program prints the 'product' array, and the total value of their costs
 *
 *Data Structures @ TCC
 *
 *Arick Mounts
 */


struct Product{
  string name;
  double price;
  int amount;
};

void printProduct (Product pro){
  cout << pro.name << ": $" << (pro.price * pro.amount) << endl;
}


int main() {
  
  Product Arr[64] = {}; 
  ifstream filein;
  filein.open("project_03_data.csv");
  for (int i = 0; i < 64; i++){
    if (getline(filein ,Arr[i].name, ',')){
      string inS;
      getline(filein,inS, ',');
      Arr[i].price = stod(inS);
      getline(filein, inS, '\n');
      Arr[i].amount = stoi(inS);
    }
  }
  double Total = 0;
  for (int i = 0; i < 64; i++){
    
    if (Arr[i].price > 0){
      printProduct(Arr[i]);
      Total = Total + (Arr[i].price * Arr[i].amount);
    }
    if(i == 63){
      cout << "==========\n$" << Total << endl;
    }
  }

  filein.close();
}