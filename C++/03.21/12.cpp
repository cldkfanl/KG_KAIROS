#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main(){
    int res;
    cin>>res;

    for(int i=1; i<=10; i++){
        if(res == i){
            continue;
        }
        cout<<i<<endl;
    }
    return 0;
}