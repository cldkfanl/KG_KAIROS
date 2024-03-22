#include <iostream>
using namespace std;
#include<string>

int main(){
    int a;
    int& rA = a;

    cout<<"변수 a : "<<a<<endl;
    cout<<"레퍼런스 Ra : "<<rA<<endl;

    rA = 50;

    cout<<"rA에 50 대입"<<endl;
    cout<<"레퍼런스 rA : "<<rA<<endl;

    cout<<"변수 a : "<<a<<endl;
}
