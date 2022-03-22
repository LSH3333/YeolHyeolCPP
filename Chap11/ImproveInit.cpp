class AAA
{

};

class BBB
{
private:
    AAA mem;
public:
    BBB(const AAA &ref) : mem(ref) {} // 이니셜라이저에 의한 초기화
};

class CCC
{
private:
    AAA mem;
public:
    CCC(const AAA &ref) { mem = ref; } // 대입연산에 의한 초기화
};