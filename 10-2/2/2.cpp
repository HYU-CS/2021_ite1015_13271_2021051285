#include <iostream>
#include <cstdlib>
#include <string>
#include <map>

std::map<int, std::string> pizzaSideMenuMap = {{1, "cola"}, {2, "fried potato"}, {3, "sprite"}};
std::map<int, std::string> chickenSideMenuMap = {{1, "cheese ball"}, {2, "cola"}, {3, "fried potato"}, {4, "sprite"}};

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
    void showSideMenu(void);
    void addFood(void);
};

Pizza::Pizza(int price)
: price(price), pizzaSideMenuList({{"cola", 2000}, {"fried potato", 3000}, {"sprite", 2000}}) { }

void Pizza::sideMenuAdd(std::string _sideName)
{
    if(_sideName.c_str()[0] >= '0' && _sideName.c_str()[0] <= '9' && _sideName.size() == 1)
    {
        _sideName = pizzaSideMenuMap[_sideName.c_str()[0] - '0'];
    }

    this->sideMenu = _sideName;
    this->totalPrice += pizzaSideMenuList[_sideName];
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
    void showSideMenu(void);
    void addFood(void);
};

Chicken::Chicken(int price)
: price(price), ChickenSideMenuList({{"cheese ball", 4000}, {"cola", 2000}, {"fried potato", 3000}, {"sprite", 2000}}) { }

void Chicken::sideMenuAdd(std::string _sideName)
{
    if(_sideName.c_str()[0] >= '0' && _sideName.c_str()[0] <= '9' && _sideName.size() == 1)
    {
        _sideName = chickenSideMenuMap[_sideName.c_str()[0] - '0'];
    }

    this->sideMenu = _sideName;
    this->totalPrice += ChickenSideMenuList[_sideName];
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
    std::string sideMenuNum;

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

    delete margheritaPizza;
    delete gorgonzolaPizza;
    delete friedChicken;
    delete spicyChicken;
    
    return 0;
}