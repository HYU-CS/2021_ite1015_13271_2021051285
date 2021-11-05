#include <iostream>
#include <cstdlib>
#include <string>
#include <map>

class DeliveryFood
{
protected:
    int totalPrice;
    std::string sideMenu;

public:
    DeliveryFood(void) : totalPrice(0) { }
    virtual ~DeliveryFood(void) { }
    int getTotalPrice(void) const { return totalPrice; }
    std::string getSideMenu(void) const { return sideMenu; }
    virtual void sideMenuAdd(std::string _sideName) = 0;
    virtual void sideMenuAdd(int _sideIndex) = 0;
    virtual void showSideMenu(void) = 0;
    virtual void addFood(void) = 0;
};

class Pizza : public DeliveryFood
{
private:
    std::map<std::string, int> pizzaSideMenuList;
    int price;

public:
    Pizza(int price);
    void sideMenuAdd(std::string _sideName);
    void sideMenuAdd(int _sideIndex);
    void showSideMenu(void);
    void addFood(void);
};

Pizza::Pizza(int price)
: price(price), pizzaSideMenuList({{"cola", 2000}, {"fried potato", 3000}, {"sprite", 2000}}) { }

void Pizza::sideMenuAdd(std::string _sideName)
{
    this->sideMenu = _sideName;
    this->totalPrice += pizzaSideMenuList[_sideName];
}

void Pizza::sideMenuAdd(int _sideIndex)
{
    int i = 1;
    
    for(std::map<std::string, int>::iterator it = this->pizzaSideMenuList.begin(); it != this->pizzaSideMenuList.end(); it++)
    {
        if(i == _sideIndex)
        {
            this->sideMenuAdd(it->first);
            break;
        }

        i++;
    }
}

void Pizza::showSideMenu(void)
{
    int i = 1;

    for(std::map<std::string, int>::iterator it = this->pizzaSideMenuList.begin(); it != this->pizzaSideMenuList.end(); it++)
    {
        std::cout << i++ << ". " << it->first << " " << it->second << std::endl;
    }
}

void Pizza::addFood(void)
{
    this->totalPrice += this->price;
}



class Chicken : public DeliveryFood
{
private:
    std::map<std::string, int> ChickenSideMenuList;
    int price;

public:
    Chicken(int price);
    void sideMenuAdd(std::string _sideName);
    void sideMenuAdd(int _sideIndex);
    void showSideMenu(void);
    void addFood(void);
};

Chicken::Chicken(int price)
: price(price), ChickenSideMenuList({{"cheese ball", 4000}, {"cola", 2000}, {"fried potato", 3000}}) { }

void Chicken::sideMenuAdd(std::string _sideName)
{
    this->sideMenu = _sideName;
    this->totalPrice += ChickenSideMenuList[_sideName];
}

void Chicken::sideMenuAdd(int _sideIndex)
{
    int i = 1;
    
    for(std::map<std::string, int>::iterator it = this->ChickenSideMenuList.begin(); it != this->ChickenSideMenuList.end(); it++)
    {
        if(i == _sideIndex)
        {
            this->sideMenuAdd(it->first);
            break;
        }

        i++;
    }
}

void Chicken::showSideMenu(void)
{
    int i = 1;

    for(std::map<std::string, int>::iterator it = this->ChickenSideMenuList.begin(); it != this->ChickenSideMenuList.end(); it++)
    {
        std::cout << i++ << ". " << it->first << " " << it->second << std::endl;
    }
}

void Chicken::addFood(void)
{
    this->totalPrice += this->price;
}

void chooseSideMenu(DeliveryFood *food)
{
    int sideMenuNum;

    food->showSideMenu();
    std::cout << "select side menu : ";

    std::cin >> sideMenuNum;

    food->sideMenuAdd(sideMenuNum);
}

int main(void)
{
    DeliveryFood* margheritaPizza = new Pizza(12000);
    DeliveryFood* gorgonzolaPizza = new Pizza(15000);
    DeliveryFood* friedChicken = new Chicken(17000);
    DeliveryFood* spicyChicken = new Chicken(19000);

    int chooseFoodNum = 0;
    std::cout << "1. margherita pizza" << std::endl;
    std::cout << "2. gorgonzola pizza" << std::endl;
    std::cout << "3. fried chicken" << std::endl;
    std::cout << "4. spicy chicken" << std::endl;
    std::cout << "choose food : ";
    std::cin >> chooseFoodNum;

    std::string foodName;
    DeliveryFood* chosenFood;

    switch(chooseFoodNum)
    {
        case 1:
            chosenFood = margheritaPizza;
            foodName = "margherita pizza";
            break;
        case 2:
            chosenFood = gorgonzolaPizza;
            foodName = "gorgonzola pizza";
            break;
        case 3:
            chosenFood = friedChicken;
            foodName = "fried chicken";
            break;
        case 4:
            chosenFood = spicyChicken;
            foodName = "spicy chicken";
            break;
        
        default:
            std::cout << "Wrong Response" << std::endl;
            ::exit(EXIT_FAILURE);
    }

    chosenFood->addFood();

    chooseSideMenu(chosenFood);

    std::cout << foodName << ", " << chosenFood->getSideMenu() << " total price : " << chosenFood->getTotalPrice() << std::endl;
    
    return 0;
}