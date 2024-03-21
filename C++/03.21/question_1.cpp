#include<iostream>
#include<fstream>
using namespace std;
//문제1: 사용자로부터 두 개의 정수를 입력 받고, 두 수의 합을 출력하는 프로그램을 작성하세요.
int main(){

    int fir, sec;
    cout<<"첫 숫자를 입력하세요"<<endl;
    cin >>fir;
    cout<<"두번째 숫자를 입력하세요"<<endl;
    cin >>sec;
    cout<<"두 수의 합은 "<<fir+sec<<" 입니다."<<endl;


    return 0;
}