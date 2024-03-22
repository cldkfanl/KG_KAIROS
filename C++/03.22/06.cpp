#include<iostream>
using namespace std;

class Animal{
    public :
    void speak(){
        cout<<"동물의 왕국"<<endl;
    }
};
class Mammal{
    public :
    void breathe(){
        cout<<"포유류는 폐로 숨을 쉽니다."<<endl;
    }
};
class Dog : public Animal, public Mammal{
    public :
    void bark(){
        cout<<"멍멍"<<endl;
    }
};
int main(){
    Dog dog;
    dog.speak();
    dog.breathe();
    dog.bark();

    return 0;
}
