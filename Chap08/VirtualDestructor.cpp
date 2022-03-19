
class First
{
public:
    virtual ~First() {}
};

class Second : public First
{
public:
    virtual ~Second() {}
};

class Third : public Second
{
public:
    virtual ~Third() {}
};

int main()
{
    First * ptr = new Third();
    delete ptr;
}