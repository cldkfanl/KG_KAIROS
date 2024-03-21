#include<iostream>
#include<fstream>
using namespace std;
int main(){


    char input;
    while(true){
        cout << "방향키를 입력하세요"<<endl;
        cin >> input;

        switch(input){
            case 'a' :
            case 'A' :
            cout<<"좌"<<endl;
            break;
            
            case 'd' :
            case 'D' :
            cout<<"우"<<endl;
            break;
            case 'W' :
            case 'w' :
            cout<<"앞"<<endl;
            break;
            case 'S' :
            case 's' :
            cout<<"뒤"<<endl;
            break;
            
            case 'q' :
            case 'Q' :
            cout<<"정지"<<endl;
            break;

            default:
            cout << "잘못된 입력입니다." << endl;
            break;
        }
        if(input == 'q' || input == 'Q'){
            break;
        }
    }
    return 0;
}