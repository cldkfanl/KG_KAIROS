#include <iostream>
using namespace std;
#include<string>


void swap(int *fir, int *sec){
    int thr = *fir;
    *fir = *sec;
    *sec = thr;
}

void refer_swap(int &fir, int &sec){
    int thr = fir;
    fir = sec;
    sec = thr;
}
int main(){
    //미션1 : 포인터를 사용해서 1, 5 swap

    int x = 1, y = 5;

    swap(&x, &y);
    cout<< "x : " << x << ", y : "<< y <<endl;

    //미션2 : 레퍼런스를 사용해서 1, 5 swap

    refer_swap(x, y);
    cout<< "x : " << x << ", y : "<< y <<endl;
    
}
