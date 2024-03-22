#include <iostream>
using namespace std;
#include<string>
//미션 1 : 사칙연산 계산기 만들기
//미션 2 : a , b 평균값 계산기 만들기

class calc{
    public:
    int a, b;
    int add(){
        return a+b;
    }
    int sub(){
        return a-b;
    }
    int mul(){
        return a*b;
    }
    int div(){
        if(b != 0){
            return a/b;
        }
        else{
            return 0;
        }
    }
};

class avgcalc{
    public :
    int sum = 0;
    int len = 0;
    void addnum(int num){
        sum += num;
        len ++;
    }
    double calnum(){
        return (double)sum / (double)len;
    }
};

int main(){
    calc c;
    avgcalc ac;
    cout<<"모드를 입력하세요 : (1 : 계산기 , 2 : 평균값계산기)"<<endl;
    int num;
    cin >> num;
    if(num == 1){
        cout<<"두개의 값을 입력하세요."<<endl;
        cin >> c.a>>c.b;
        cout<<"계산기 입력값 : "<<c.a<<" , "<<c.b<<endl;
        cout<<"+ : "<<c.add()<<endl;
        cout<<"- : "<<c.sub()<<endl;
        cout<<"* : "<<c.mul()<<endl;
        cout<<"/ : "<<c.div()<<endl;
    }
    else if(num == 2){
        cout<<"종료하려면 0을 입력하세요."<<endl;;
        while(true){
            int num;
            cin>> num;
            if(num == 0){
                break;
            }
            else{
                ac.addnum(num);
            }
        }
        printf("평균값 : %.2f\n",ac.calnum());
    }

    
}
