#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
    char * title;
    char * isbn; // 국제표준도서번호
    int price;

public:
    Book(char * _title, char * _isbn, int _price) : price(_price)
    {
        title = new char[strlen(title) + 1];
        strcpy(title, _title);
        isbn = new char[strlen(_isbn) + 1];
        strcpy(isbn, _isbn);
    }
    // 복사 생성자
    Book(const Book &ref) : price(ref.price)
    {
        title = new char[strlen(ref.title)+1];
        strcpy(title, ref.title);
        isbn = new char[strlen(ref.isbn)+1];
        strcpy(isbn, ref.isbn);
    }
    // 대입 연산자 오버로딩
    Book& operator= (const Book &ref)
    {
        // 기존 주소값 삭제 (메모리 누수 방지)
        delete []title;
        delete []isbn;

        price = ref.price;
        // 동적 할당
        title = new char[strlen(ref.title)+1];
        strcpy(title, ref.title);
        isbn = new char[strlen(ref.isbn)+1];
        strcpy(isbn, ref.isbn);
        return *this;
    }

    void ShowBookInfo()
    {
        cout << "제목: " << title << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "가격: " << price << endl;
    }

    ~Book()
    {
        delete []title;
        delete []isbn;
    }

};

class EBook : public Book
{
private:
    char * DRMKey;

public:
    EBook(char * _title, char * _isbn, int _price, char * _DRMKey)
            : Book(_title, _isbn, _price)
    {
        DRMKey = new char[strlen(_DRMKey) + 1];
        strcpy(DRMKey, _DRMKey);
    }
    // 복사 생성자
    EBook(const EBook &ref) : Book(ref)
    {
        DRMKey = new char[strlen(ref.DRMKey)+1];
        strcpy(DRMKey, ref.DRMKey);
    }
    // 대입 연산자 오버로딩
    EBook& operator= (const EBook &ref)
    {
        Book::operator=(ref);
        delete []DRMKey; // 기존 정보 삭제
        DRMKey = new char[strlen(ref.DRMKey)+1];
        strcpy(DRMKey, ref.DRMKey);
        return *this;
    }

    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout << "인증키: " << DRMKey << endl;
    }

    ~EBook()
    {
        delete []DRMKey;
    }
};

int main()
{
    EBook ebook1("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w018kiw");
    EBook ebook2 = ebook1; // 복사 생성자 호출
    ebook2.ShowEBookInfo();
    cout << endl;

    EBook ebook3("dumy", "dumy", 0, "dumy");
    ebook3 = ebook2; // 대입 연산자 호출
    ebook3.ShowEBookInfo();
}