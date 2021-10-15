#include <iostream>
#include <string>

// class declaration

class Printer
{
private:
    int availableCount;
    int availablePage;

public:
    Printer(int availableCount, int availablePage);
    int print(int usedPage);
    int getAvailableCount(void) const;
    int getAvailablePage(void) const;
};

class InkJetPrinter : public Printer
{
private:
    const std::string model;
    const std::string manufacturer;

public:
    InkJetPrinter(int availableCount, int availablePage, std::string model, std::string manufacturer);
    void print(int usedPage);
    void showInfo(void) const;
};

class LaserPrinter : public Printer
{
private:
    const std::string model;
    const std::string manufacturer;

public:
    LaserPrinter(int availableCount, int availablePage, std::string model, std::string manufacturer);
    void print(int usedPage);
    void showInfo(void) const;
};

// function definition of class Printer

Printer::Printer(int availableCount, int availablePage)
: availableCount(availableCount), availablePage(availablePage) { }

int Printer::print(int usedPage)
{
    if(this->availablePage < usedPage)
    {
        return 1;
    }
    else if(this->availableCount < usedPage)
    {
        return 2;
    }
    else
    {
        this->availableCount -= usedPage;
        this->availablePage -= usedPage;
        return 0;
    }
}

int Printer::getAvailableCount(void) const
{
    return this->availableCount;
}

int Printer::getAvailablePage(void) const
{
    return this->availablePage;
}

// function definition of class InkJetPrinter

InkJetPrinter::InkJetPrinter(int availableCount, int availablePage, std::string model, std::string manufacturer)
: Printer(availableCount, availablePage), model(model), manufacturer(manufacturer)
{
    this->showInfo();
}

void InkJetPrinter::print(int usedPage)
{
    int result = Printer::print(usedPage);

    if(result == 0)
    {
        std::cout << "Printed." << std::endl;
    }
    else if(result == 1)
    {
        std::cout << "Cannot print because of not enough page." << std::endl;
    }
    else if(result == 2)
    {
        std::cout << "Cannot print because of not enough Ink." << std::endl;
    }
}

void InkJetPrinter::showInfo(void) const
{
    std::cout << "InkJet: ";
    std::cout << this->model << ", " << this->manufacturer << ", ";
    std::cout << this->getAvailablePage() << " available pages, ";
    std::cout << this->getAvailableCount() << " available Ink" << std::endl;
}

// function definition of class LaserPrinter

LaserPrinter::LaserPrinter(int availableCount, int availablePage, std::string model, std::string manufacturer)
: Printer(availableCount, availablePage), model(model), manufacturer(manufacturer)
{
    this->showInfo();
}

void LaserPrinter::print(int usedPage)
{
    int result = Printer::print(usedPage);

    if(result == 0)
    {
        std::cout << "Printed." << std::endl;
    }
    else if(result == 1)
    {
        std::cout << "Cannot print because of not enough page." << std::endl;
    }
    else if(result == 2)
    {
        std::cout << "Cannot print because of not enough Toner." << std::endl;
    }
}

void LaserPrinter::showInfo(void) const
{
    std::cout << "Laser: ";
    std::cout << this->model << ", " << this->manufacturer << ", ";
    std::cout << this->getAvailablePage() << " available pages, ";
    std::cout << this->getAvailableCount() << " available Toner" << std::endl;
}

// main function

int main(void)
{
    int count, page;
    std::cout << "Currently operating 2 printers are follow" << std::endl;
    std::cin >> page >> count;
    InkJetPrinter inkjet(count, page, "Officejet V30", "HP");
    std::cin >> page >> count;
    LaserPrinter laser(count, page, "SCX-6x47", "Samsung");

    std::cout << std::endl;

    while(true)
    {
        int printer, page;
        char ch = '\0';

        std::cout << "Insert printer(1:InkJet, 2:Laser) and pages: ";
        std::cin >> printer >> page;
        std::cin.ignore();

        if(printer == 1)
        {
            inkjet.print(page);
        }
        else if(printer == 2)
        {
            laser.print(page);
        }

        inkjet.showInfo();
        laser.showInfo();

        while(true)
        {
            std::cout << "Do you want keep printing? (y/n) >> ";
            std::cin >> ch;
            std::cin.ignore();
            if(ch == 'n' || ch == 'y')
            {
                break;
            }
        }

        if(ch == 'n')
        {
            break;
        }

        std::cout << std::endl;
    }
    return 0;
}