#include<iostream>
#include<fstream>
using namespace std;
int main(){
//미션 1 : 홀 짝 판별 출력
    int n;
    cin>>n;
    n%2==0?cout<<"짝수"<<endl:cout<<"홀수"<<endl;

//미션 2 : 둘중 큰 수 출력
    int fir, sec;
    cin >>fir>>sec;
    cout<<(fir>=sec?fir:sec)<<endl; //1번째

//미션 3 : 입력받은 세개의 숫자중 제일 작은 값 출력
    int a,b,c;
    cin>>a>>b>>c;
    cout<<(a>b?(a>c?a:c):(b>c?b:c))<<endl;


    return 0;
}