#include <iostream>
#include <string>

class Book
{
private:
    std::string title;
    int price, pages;

public:
    Book(std::string title = "", int price = 0, int pages = 0)
    {
        this->title = title; this->price = price; this->pages = pages;
    }
    void show(void)
    {
        std::cout << "Book : " << title << ' ' << price << "won " << pages << "pages" << std::endl;
    }

    friend bool operator==(const Book &lhs, const std::string &rhs);
    friend bool operator==(const Book &lhs, int rhs);
    friend bool operator==(const Book &lhs, const Book &rhs);
};

bool operator==(const Book &lhs, const std::string &rhs)
{
    return lhs.title == rhs;
}

bool operator==(const Book &lhs, int rhs)
{
    return lhs.price == rhs;
}

bool operator==(const Book &lhs, const Book &rhs)
{
    return lhs.title == rhs.title && lhs.price == rhs.price && lhs.pages == rhs.pages;
}

int main(void)
{
    Book a("Dune1", 30000, 500), b("Dune2", 30000, 500);
    a.show();
    if(a == "Dune1") std::cout << "This book is Dune1" << std::endl;
    if(a == 30000) std::cout << "Original price is 30000won" << std::endl;
    if(a == b) std::cout << "They are the same book" << std::endl;
    return 0;
}