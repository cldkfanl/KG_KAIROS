#include <iostream>
#include <string>
using namespace std;
struct Human{
    int age = 20;
    int height = 180;
    string name = "dodo";
};

void setHuman(Human* pH, int a, int h, string n){
    pH->age += a;
    pH->height = h;
    pH->name = n;
}

int main(){
    Human h = {20, 180, "haho"};
    setHuman(&h, 10, 170, "gigi");

    cout<<"age : "<<h.age<<endl;
    cout<<"height : "<<h.height<<endl;
    cout<<"name : "<<h.name<<endl;

    return 0;
}