#include<iostream>
#include<fstream>
using namespace std;
//문제2: 반지름을 입력 받고, 원의 넓이를 계산하여 출력하는 프로그램을 작성하세요. (원주율은 3.14로 가정합니다.)
int main(){

    int r;
    double PI = 3.14;
    cout<<"반지름을 입력하세요."<<endl;
    cin >>r;
    cout<<"원의 넓이는 "<<PI*r*r<<" 입니다."<<endl;


    return 0;
}