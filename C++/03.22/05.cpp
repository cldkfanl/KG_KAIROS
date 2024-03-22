#include<iostream>
using namespace std;
class Car {
    private :
    int num;
    double gas;
    public :
    Car();
    Car(int n, double g);
    void show();
};

int main(){
    Car car1;
    Car car2(1234, 33.3);
    return 0;
}

Car::Car(){
    num = 0;
    gas = 0.0;
    cout<<"자동차가 만들어졌습니다 "<<endl;
}

Car::Car(int n, double g){
    num = n;
    gas = g;
    cout<<"차번호 : "<<num <<", 연료량 : "<<gas <<"생산됨"<<endl;
}
void Car::show(){
    cout<<"차번호 "<<num<<endl;
    cout<<"연료량 "<<gas<<endl;
}