#include <iostream>
#include <string>

class Library
{
private:
    std::string *_title;
    std::string *_author;
    int *_price;

public:
    Library(int num);
    void setBookInfo(int index, std::string title, std::string author, int price);
    void showBookList(int num);
    ~Library();
};

Library::Library(int num)
:  _title(new std::string[num]), _author(new std::string[num]), _price(new int[num]) { }

void Library::setBookInfo(int index, std::string title, std::string author, int price)
{
    this->_title[index] = title;
    this->_author[index] = author;
    this->_price[index] = price;
}

void Library::showBookList(int num)
{
    for(size_t i = 0; i < num; i++)
    {
        std::cout << "Book " << i + 1 << " : " << this->_title[i] << std::endl;
        std::cout << this->_author[i] << " / " << this->_price[i] << std::endl;
    }
}

Library::~Library()
{
    delete[] this->_title;
    delete[] this->_author;
    delete[] this->_price;
}



int main(void)
{
    int num;

    std::cout << "How many register book : ";
    std::cin >> num;
    std::cin.ignore();

    Library *lib = new Library(num);

    for(int i = 0; i < num; i++)
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

        lib->setBookInfo(i, title, author, price);
    }

    lib->showBookList(num);

    delete lib;

    return 0;
}