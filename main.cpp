#include <iostream>
#include <string>
using namespace std;
 class bank{
protected:
    string name;
    int accountNo;
    double balance;
public:
  static int totalAccount;
    bank(string name,int accountNo,double balance){
        this->name=name;
        this->balance=balance;
        this->accountNo=accountNo;
        totalAccount++;
    }


    virtual double getter()=0;

     virtual void deposit(double amount) = 0;


 };
 class savingAccunt : public bank{
    public:
    savingAccunt(string name,int accountNo,double balance):bank( name, accountNo, balance){}

    void deposit(double amount) {

    // Savings Account (amount ka 5% extra munafa):
    balance += amount + (amount * 0.05);

}
double getter(){
return balance;
    }

 };

  class currentAccunt : public bank{
    public:
    currentAccunt(string name,int accountNo,double balance):bank( name, accountNo, balance){}

    void deposit(double amount){
    // Current Account:
    balance += amount;

    }
    double getter(){
return balance;
    }
  };
  int bank::totalAccount=0;
  int main(){
    currentAccunt q1 ("Nauman",2139445,3100.23);
    q1.deposit(2100);
    cout<<q1.getter()<<endl;
    savingAccunt s1 ("Ali " ,324453656,3212.43);
    s1.deposit(2100);
    cout<<s1.getter()<<endl;
    cout<<bank::totalAccount;
  };
