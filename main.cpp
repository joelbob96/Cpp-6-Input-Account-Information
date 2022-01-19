#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "account.h"
//#include "trim.h"

int main() {

  //account J("1234567", "Joel", "Martin", 8000.00);

  //std::cout << J << "\n";



  
  try{
  std::ifstream input("account.dat");
  if(!input){throw "Error opening input file";}

  std::ofstream o_stream{"account.csv"};
  
  if(!o_stream){throw "Error opening output file";}
  std::string line_input;
  std::string acc;
  std::string fn;
  std::string ln;
  //std::string balance_string;
  double balance;
  char c;
  int i = 0;
  std::vector <account> V1;

  while(!input.eof()){
  
  i++;

  if(!std::getline(input, line_input)){throw i;}
  
  acc = line_input.substr (0,10);

  fn = line_input.substr (10,15);

  //trim(fn);

  ln = line_input.substr (25,25);

  //trim(ln);

  balance = std::stod (line_input.substr (50,11));
  
  class account a(acc, fn, ln, balance);

  V1.push_back(a);

  //a.output(o_stream);

  //std::cout << a;
  }
  
  for(auto j = V1.begin(); j != V1.end(); ++j){
    std::cout << *j;
    account b = *j;
    b.output(o_stream);
  }


  }catch(char const* s)
  {
  std::cerr << s << std::endl;
  }catch(int i){
  std::cerr << "Error in input item number: " << i << std::endl;
  }

}
