#include <iostream>
#include <string>
using namespace std;

struct Human{
    int age;
    int height;
    string name = "dodo";
    void print_(int age, int height){
        cout << "age : " << age << endl;
        cout << "height : " << height << endl;
    }
};


int main(){
    Human h = {20, 170};

    cout<<"age : "<<h.age<<endl;
    cout<<"height : "<<h.height<<endl;
    cout<<"----------------"<<endl;
    h.print_(20, 170);
    return 0;
}