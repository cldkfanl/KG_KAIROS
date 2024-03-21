#include<iostream>
#include<fstream>
using namespace std;
int main(){

    int intval = 42;
    float floatval = 3.14;

    printf("정수값 : %d\n", intval);
    
    // 부동소수점 출력
    printf("부동소수점 : %f\n", floatval);

    
    // %.nf 소수점 n자리까지 출력
    printf("소수점 2자리까지 출력 : %.2f\n", floatval);

    //%10.1f : 총 10자리를 확보하고 소수점 이하 1자리까지 출력
    printf("10자리 확보 후 소수점 1자리 : %10.1f\n", floatval);


    return 0;
}