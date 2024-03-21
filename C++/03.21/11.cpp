#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    int num;
    cin>>num;
    for(int i=1; i<=9; i++){
        cout<<num * i <<endl;
    }
    return 0;
}