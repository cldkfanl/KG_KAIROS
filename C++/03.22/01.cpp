#include<iostream>
using namespace std;
int fir, sec;
void swap(){
    int thr = fir;
    fir = sec;
    sec = thr;
}
int main(){
    //미션1 : a , b 스왑 하는 함수 만들기
    cin >> fir >> sec;
    swap();
    cout <<"fir : "<< fir <<", sec : "<< sec;
}