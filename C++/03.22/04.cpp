#include<iostream>
using namespace std;

class Car{
    private:
        int num;
        double gas;
    public:
        void setNumGas(int n, double g);
        void show();
};
void Car::show(){
    cout<<"차 번호 : "<<num<<endl;
    cout<<"연료량 : " <<gas<<endl;
}
void Car::setNumGas(int n, double g){
    if(g>0 && g < 1000){
        num = n;
        gas = g;
        cout<<"차번호"<<num<<"차량의 연료량을"<<gas<<"로 변경합니다."<<endl;
    }
    else{
        cout<<g<<"는 범위를 벗어난 양입니다."<<endl;
    }
}

int main(){
    Car car1;

    car1.setNumGas(1234, 33.3);
    car1.show();

    cout<<"잘못된 연료량의 경우"<<endl;
    car1.setNumGas(1234, -10.0);
    car1.show();



    return 0;
}