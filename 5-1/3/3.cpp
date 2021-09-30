#include <iostream>
#include <string>

class Student
{
private:
    std::string _name;
    std::string _major;
    std::string _studentID;

public:
    Student(void);
    void setName(std::string name);
    void setMajor(std::string major);
    void setStudentID(std::string studentID);
    void showStudentInfo(void);
};

Student::Student(void)
: _name(" "), _major(" "), _studentID(" ") { }

void Student::setName(std::string name)
{
    this->_name = name;
}

void Student::setMajor(std::string major)
{
    this->_major = major;
}

void Student::setStudentID(std::string studentID)
{
    this->_studentID = studentID;
}

void Student::showStudentInfo(void)
{
    std::cout << this->_name << " / " << this->_major << " / " << this->_studentID << std::endl;
}

int main(void)
{
    std::string name, major, studentID;
    Student student;

    std::cout << "Name: ";
    std::getline(std::cin, name);
    std::cout << "Major: ";
    std::getline(std::cin, major);
    std::cout << "StudentID: ";
    std::getline(std::cin, studentID);

    student.setName(name);
    student.setMajor(major);
    student.setStudentID(studentID);

    student.showStudentInfo();

    return 0;
}