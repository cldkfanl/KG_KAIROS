#include<iostream>
using namespace std;

int main(){
    int K;
    cin>>K;
    int arr[46][2] = {};
    arr[0][0] = 1;
    arr[0][1] = 0;
    for(int i=1; i<=45; i++){
        arr[i][0] = arr[i-1][1];
        arr[i][1] = arr[i-1][0] + arr[i-1][1];
    }

    cout<<arr[K][0]<<" "<<arr[K][1]<<endl;


    return 0;
}