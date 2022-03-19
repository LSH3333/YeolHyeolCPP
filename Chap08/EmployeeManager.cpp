#include <iostream>
#include <cstring>
using namespace std;

// 순수 가상함수를 지닌 불완전한 클래스 = 추상 클래스 = 객체 생성이 불가능한 클래스
class Employee
{
private:
//    char name[100];
    string name;
public:
    Employee(string name)
    {
//        strcpy(this->name, name);
        this->name = name;
    }
    void ShowYourName() const
    {
        cout << "name: " << name << endl;
    }
    // 자료형 기반이 아닌 하위 클래스를 가르키는 객체의 함수가 호출 되도록 가상함수화
    // = 0 으로 표현해 순수 가상함수화
    virtual int GetPay() const = 0;
    virtual void ShowSalaryInfo() const = 0;
};

// 정규직
class PermanentWorker : public Employee
{
private:
    int salary;
public:
    PermanentWorker(string name, int money)
    : Employee(name), salary(money) {}

    virtual int GetPay() const
    {
        return salary;
    }
    virtual void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

// 임시직
class TemporaryWorker : public Employee
{
private:
    int workTime;
    int payPerHour;
public:
    TemporaryWorker(string name, int pay)
    : Employee(name), workTime(0), payPerHour(pay) {}

    void AddWorkTime(int time) { workTime += time; }
    virtual int GetPay() const { return workTime * payPerHour; }
    virtual void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

// 영업직은 정규직의 일종
class SalesWorker : public PermanentWorker
{
private:
    int salesResult;
    double bonusRatio;
public:
    SalesWorker(string name, int money, double ratio)
    : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {}

    // function overriding
    void AddSalesResult(int value) { salesResult += value; }
    virtual int GetPay() const
    {
        // 함수명이 같다면 기본적으로 현재 클래스의 함수 호출, 따라서 상속받은 기초 클래스의 함수를 콜하고 싶다면
        // 앞에 명시해줌
        return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
    }
    virtual void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }

};

// control class
class EmployeeHandler
{
private:
    Employee * empList[50];
    int empNum;
public:
    EmployeeHandler() : empNum(0) {}

    void AddEmployee(Employee * emp)
    {
        empList[empNum++] = emp;
    }

    void ShowAllSalaryInfo() const
    {
        for(int i = 0; i < empNum; i++)
        {
            empList[i]->ShowSalaryInfo();
        }
    }

    void ShowTotalSalary() const
    {
        int sum = 0;
        for(int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();
        cout << "salary sum: " << sum << endl;
    }

    ~EmployeeHandler()
    {
        for(int i = 0; i < empNum; i++) delete empList[i];
    }

};

int main()
{
    EmployeeHandler handler;

    // 정규직 등록
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));

    // 임시직 등록
    TemporaryWorker * alba = new TemporaryWorker("JUNG", 700);
    alba->AddWorkTime(5);
//    handler.AddEmployee(new TemporaryWorker("JUNG", 700));
    handler.AddEmployee(alba);

    // 영업직 등록
    SalesWorker * seller = new SalesWorker("HONG", 1000, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller);

    // 이번 달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();

    // 이번 달에 지불해야 할 금액의 총합
    handler.ShowTotalSalary();

}