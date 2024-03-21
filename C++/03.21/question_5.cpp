#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
int main(){
//미션 1 : 1~100 7의 배수
    int i = 1;
    do{
        if(i % 7 == 0){
            cout<<i<<endl;
        }
    }while(i++ <100);


//미션 2 : 입력값이 y면 계속하고 n이면 종료하기
    char input;
    do{
        cin>>input;
        
    }while(input == 'y');

}


