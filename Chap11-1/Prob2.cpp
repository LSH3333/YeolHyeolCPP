#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
    char * title;
    char * isbn; // ����ǥ�ص�����ȣ
    int price;

public:
    Book(char * _title, char * _isbn, int _price) : price(_price)
    {
        title = new char[strlen(title) + 1];
        strcpy(title, _title);
        isbn = new char[strlen(_isbn) + 1];
        strcpy(isbn, _isbn);
    }
    // ���� ������
    Book(const Book &ref) : price(ref.price)
    {
        title = new char[strlen(ref.title)+1];
        strcpy(title, ref.title);
        isbn = new char[strlen(ref.isbn)+1];
        strcpy(isbn, ref.isbn);
    }
    // ���� ������ �����ε�
    Book& operator= (const Book &ref)
    {
        // ���� �ּҰ� ���� (�޸� ���� ����)
        delete []title;
        delete []isbn;

        price = ref.price;
        // ���� �Ҵ�
        title = new char[strlen(ref.title)+1];
        strcpy(title, ref.title);
        isbn = new char[strlen(ref.isbn)+1];
        strcpy(isbn, ref.isbn);
        return *this;
    }

    void ShowBookInfo()
    {
        cout << "����: " << title << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "����: " << price << endl;
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
    // ���� ������
    EBook(const EBook &ref) : Book(ref)
    {
        DRMKey = new char[strlen(ref.DRMKey)+1];
        strcpy(DRMKey, ref.DRMKey);
    }
    // ���� ������ �����ε�
    EBook& operator= (const EBook &ref)
    {
        Book::operator=(ref);
        delete []DRMKey; // ���� ���� ����
        DRMKey = new char[strlen(ref.DRMKey)+1];
        strcpy(DRMKey, ref.DRMKey);
        return *this;
    }

    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout << "����Ű: " << DRMKey << endl;
    }

    ~EBook()
    {
        delete []DRMKey;
    }
};

int main()
{
    EBook ebook1("���� C++ ebook", "555-12345-890-1", 10000, "fdx9w018kiw");
    EBook ebook2 = ebook1; // ���� ������ ȣ��
    ebook2.ShowEBookInfo();
    cout << endl;

    EBook ebook3("dumy", "dumy", 0, "dumy");
    ebook3 = ebook2; // ���� ������ ȣ��
    ebook3.ShowEBookInfo();
}