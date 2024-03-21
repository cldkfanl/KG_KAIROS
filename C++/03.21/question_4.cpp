#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
int main(){
//미션 1 : 1~100 3의 배수 출력
    for(int i=1; i<=100; i++){
        if(i%3 ==0){
            cout<<i<<endl;
        }
    }

//미션 2 : 1~ 10 제곱 출력
    for(int i=1; i<=10; i++){
        cout<<pow(i,2)<<endl;
    }

//미션 3 : 2~100 소수 출력

    for(int i=2; i<=100; i++){
        bool state = true;
        
        for(int j=2; j<=sqrt(i); j++){
            if(i % j ==0){
                state = false;
                break;
            }
        }

        if(state){
            cout<<i<<endl;
        }
    }
    int Num = 2;
    while(Num<=100){
        bool state = true;
        for(int i=2; i<Num; i++){
            if(Num % i == 0){
                state = false;
                break;
            }
        }
        if(state){
            cout<<Num<<endl;
        }
        Num++;
    }


    for(int i=0; i<5; i++){
        if(i == 0 || i == 4){
            for(int j=0; j<10; j++){
                cout<<"*";
            }
        }
        else{
            for(int j=0; j<10; j++){
                if(j == 0 || j == 9){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
            }
        }
        cout<<endl;
    }

    return 0;
}