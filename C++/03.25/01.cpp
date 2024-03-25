#include <iostream>
#include <string>
using namespace std;
//미션 : 직원, 관리자 클래스 정의
//Employee 클래스 정의, 상속받는 Manager 구현
//이름, 나이 기본정보 저장하는 멤버변수 포함 , 매니저는 부서 추가로 정의

class employee {
protected :
    string name;
    int age;
public :
    employee(const string name, int age) : name(name), age(age) {}
    void printer() const {
        cout<<"name : " << name << endl;
        cout<<"age : " << age << endl; 
    }
};

class manager : public employee {
    private :
    string department;
    public :
    manager(const string name, int age, const string department) : employee(name, age), department(department) {}
    void printer() {
        cout << "name :" << name << endl;
        cout << "age :" << age << endl;
        cout << "department :" << department << endl;
    }
};

int main() {
    employee emp("홍길동", 30);
    manager mgr("이순신", 40, "IT");

    emp.printer();
    mgr.printer();
   return 0;
}