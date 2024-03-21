#include<iostream>
#include<fstream>
using namespace std;
int main(){

    int num;
    bool isnum;
    cin >> num;

    if(num % 2 == 0){
        isnum = true;
    }
    else{
        isnum = false;
    }

    if(0){
        cout<<"짝수 입니다."<<endl;
    }
    else{
        cout<<"홀수 입니다."<<endl;
    }

    return 0;
}