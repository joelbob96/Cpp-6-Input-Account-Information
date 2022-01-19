#include <iostream>
#include <string>

class account{
  private:
  std::string account_code;
  std::string first_name;
  std::string last_name;
  double balance;

  public:
  account(const std::string ac, const std::string& fn, const std::string& ln, double bal):
  account_code(ac),
  first_name(fn),
  last_name(ln),
  balance(bal)
  {}

void output(std::ostream& s)const{
    s <<  account_code << "," << first_name << "," << last_name << "," << balance << "\n";
  }



  friend std::ostream& operator<<(std::ostream& s, const account& e) {
      e.output(s);
      return s;
  }



};