#include<iostream>
#include<fstream>
using namespace std;
int main(){

    int a;
    cout<<"수를 입력하세요 : "<<endl;
    cin >> a;

    if(a == 1){
        cout << a + 10 <<endl;
    }
    else if(a == 2){
        cout << a + 20<<endl;
    }
    else{
        cout<<"Out of range"<<endl;
    }

    return 0;
}