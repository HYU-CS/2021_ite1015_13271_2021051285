#include <iostream>
#include <cstring>

class MyString
{
private:
	size_t len;
	size_t strbuf_size;
    char *strbuf;

public:
	MyString(void);

	MyString(const char *str);
	MyString(const MyString &str);
    MyString(MyString &&str) noexcept;

	~MyString();

    MyString &operator=(const MyString &s);
    MyString &operator=(MyString &&s) noexcept;

	size_t length(void) const;
	void println(void);
};

MyString::MyString(void)
: len(0), strbuf_size(0), strbuf(NULL) { }

MyString::MyString(const char *str)
: len(strlen(str)), strbuf_size(len), strbuf(new char[len])
{
	for (size_t i = 0; i != len; i++) strbuf[i] = str[i];
}

MyString::MyString(const MyString &str)
: len(str.len), strbuf_size(len), strbuf(new char[len])
{
	std::cout << "Copy constructor!" << std::endl;

	for (size_t i = 0; i != len; i++)
		strbuf[i] = str.strbuf[i];
}

MyString::MyString(MyString &&str) noexcept
: len(str.len), strbuf_size(str.strbuf_size), strbuf(str.strbuf)
{
    str.strbuf = NULL;
	std::cout << "Move constructor!" << std::endl;
}

MyString::~MyString()
{
	if (strbuf)
        delete[] strbuf;
}

MyString &MyString::operator=(const MyString &s)
{
	std::cout << "Copy assignment operator!" << std::endl;

	if (s.len > this->strbuf_size)
    {
		delete[] strbuf;
		strbuf = new char[s.len];
		strbuf_size = s.len;
	}
	len = s.len;
	for (size_t i = 0; i != len; i++)
    {
		strbuf[i] = s.strbuf[i];
	}

	return *this;
}

MyString &MyString::operator=(MyString &&s) noexcept
{
    std::cout << "Move assignment operator!" << std::endl;

    this->len = s.len;
    this->strbuf_size = s.strbuf_size;
    this->strbuf = s.strbuf;

    s.strbuf = NULL;

    return *this;
}

size_t MyString::length() const
{
    return len;
}

void MyString::println()
{
	for (size_t i = 0; i != len; i++)
    {
        std::cout << strbuf[i];
    }

	std::cout << std::endl;
}

template <typename T>
void my_swap(T &a, T &b) {
	T tmp(std::move(a));
	a = std::move(b);
	b = std::move(tmp);
}

int main() {
	MyString str1("abc");
	MyString str2("def");
	std::cout << "Before swap -----" << std::endl;
	std::cout << "str1 : ";
	str1.println();
	std::cout << "str2 : ";
	str2.println();

	std::cout << "After swap -----" << std::endl;
	my_swap(str1, str2);
	std::cout << "str1 : ";
	str1.println();
	std::cout << "str2 : ";
	str2.println();
}
