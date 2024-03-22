#include<iostream>
using namespace std;


class Cal1{
public:
    int a, b, c;
    int aaa(int a, int b);
    int aaa(int a, int b, int c);
};
int Cal1::aaa(int a, int b){
    return a+b;
}
int Cal1::aaa(int a, int b, int c){
    return (a+b+c)/3;
}

int main(){
    Cal1 cal1;
    int a = 0, b = 0, c = 0;

    cout<<"정수를 입력 : ";
    cin >> a;
    cal1.a = a;
    cout<<"정수를 입력 : ";
    cin >> b;
    cal1.b = b;
    cout<<"정수를 입력 : ";
    cin >> c;
    cal1.c = c;
    cout<<"두 수의 합 : "<<cal1.aaa(a,b)<<endl;
    cout<<"세 수의 평균 : "<<cal1.aaa(a,b,c)<<endl;


    return 0;
}