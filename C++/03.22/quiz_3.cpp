#include<iostream>
using namespace std;


class BankAccount{
    private :
    int accountNumber;
    int balance;

    public :
    BankAccount(int accountNumber, int balance);
    void transfer(int amount, BankAccount otherAccount);
    void deposit(int amount);
    void withdraw(int amount);
    void show();

};
void BankAccount :: show(){
    cout<<"계좌 "<<accountNumber<<"의 잔액은 "<<balance<<"입니다."<<endl;
}
BankAccount :: BankAccount(int accountNum, int money){
    accountNumber = accountNum;
    balance = money;
    show();
}
void BankAccount :: withdraw(int amount){
    balance -= amount;
    show();
}
void BankAccount :: deposit(int amount){
    balance += amount;
    show();
}
void BankAccount :: transfer(int amount, BankAccount otherAccount){
    balance -= amount;
    otherAccount.balance += amount;
    cout<<accountNumber<<"에서 "<< otherAccount.accountNumber<<"로 "<<amount<<"원 이체하기"<<endl;
    show();
}
int main(){
    BankAccount b1(1, 100000);
    BankAccount b2(2, 1000);
    b1.withdraw(8000);
    b1.transfer(2000, b2);


    return 0;
}
