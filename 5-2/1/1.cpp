#include <iostream>
#include <string>

class Library
{
private:
    size_t _count;
    std::string *_title;
    std::string *_author;
    int *_price;

public:
    Library(size_t num);
    void setBookInfo(size_t index, std::string title, std::string author, int price);
    void showBookList(void);
    ~Library(void);
};

Library::Library(size_t num)
: _count(num), _title(new std::string[num]), _author(new std::string[num]), _price(new int[num]) { }

void Library::setBookInfo(size_t index, std::string title, std::string author, int price)
{
    this->_title[index] = title;
    this->_author[index] = author;
    this->_price[index] = price;
}

void Library::showBookList(void)
{
    for(size_t i = 0; i < this->_count; i++)
    {
        std::cout << "Book " << i + 1 << " : " << this->_title[i] << std::endl;
        std::cout << this->_author[i] << " / " << this->_price[i] << std::endl;
    }
}

Library::~Library(void)
{
    delete[] this->_title;
    delete[] this->_author;
    delete[] this->_price;
}



int main(void)
{
    size_t num;

    std::cout << "How many register book : ";
    std::cin >> num;
    std::cin.ignore();

    Library lib(num);

    for(size_t i = 0; i < num; i++)
    {
        std::string title, author;
        int price;

        std::cout << "Book title : ";
        std::getline(std::cin, title);
        std::cout << "Book author : ";
        std::getline(std::cin, author);
        std::cout << "Book price : ";
        std::cin >> price;
        std::cin.ignore();

        lib.setBookInfo(i, title, author, price);
    }

    lib.showBookList();

    return 0;
}