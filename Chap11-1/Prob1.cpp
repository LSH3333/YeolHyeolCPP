#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
    int bullet;
public:
    Gun(int bnum) : bullet(bnum) {}
    void Shot()
    {
        cout << "BBANG!" << endl;
        bullet--;
    }
};

class Police
{
private:
    int handcuffs;
    Gun *pistol;
public:
    // 생성자
    Police(int bnum, int bcuff) : handcuffs(bcuff)
    {
        if(bnum > 0)
            pistol = new Gun(bnum);
        else
            pistol = NULL;
    }
    // 복사 생성자
    Police(const Police &ref) : handcuffs(ref.handcuffs)
    {
        if(ref.pistol != NULL)
            pistol = new Gun(*(ref.pistol)); // Gun의 디폴트 복사 생성자 호출
        else
            pistol = NULL;
    }
    // 대입 연산자 오버로딩
    Police& operator= (const Police &ref)
    {
        // 현재 객체에 저장된 pistol 주소 정보 있다면 메모리 누수 방지 위해 삭제
        if(pistol != NULL)
            delete pistol;

        // 전달 받은 객체에 pistol 주소 정보 있다면 깊은 복사 진행
        if(ref.pistol != NULL)
            pistol = new Gun(*(ref.pistol));
        else
            pistol = NULL;

        handcuffs = ref.handcuffs;
        return *this;
    }

    void PutHandcuff()
    {
        cout << "SNAP!" << endl;
        handcuffs--;
    }
    void Shot()
    {
        if(pistol == NULL)
            cout << "No Pistol" << endl;
        else
            pistol->Shot();
    }
    ~Police()
    {
        if(pistol != NULL) delete pistol;
    }
};

//int main()
//{
//    Police police1(2, 3);
//    Police police2 = police1; // 복사 생성자 호출
//    police2.Shot();
//
//    Police police3(1,1);
//    police3 = police2; // 오버로딩된 대입 연산자 호출
//    police3.PutHandcuff();
//}
