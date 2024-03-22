#include<iostream>
using namespace std;

int main(){
    //미션 1 : 1~10중 짝수 건너뛰기
    for(int i=1; i<=10; i++){
        if(i % 2 == 0){
            continue;
        }
        cout<<i<<endl;
    }

    //미션 2 : 입력값이 음수이면 건너뛰고 루프로 돌아가기(5회), 양수이면 출력.
    int cnt = 0;
    while(cnt++ < 5){
        int input;
        cin >> input;
        if(input < 0){
            continue;
        }
        cout<<input<<endl;
    }
}