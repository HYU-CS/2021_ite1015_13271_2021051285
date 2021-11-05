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
    ~Pizza();
    void sideMenuAdd(std::string _sideName);
    void showSideMenu(void);
    void addFood(void);
};

Pizza::Pizza(int price)
: price(price), pizzaSideMenuList({{"cola", 2000}, {"fried potato", 3000}, {"sprite", 2000}}) { }

void Pizza::sideMenuAdd(std::string _sideName)
{
    this->totalPrice += pizzaSideMenuList[_sideName];
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
: price(price), ChickenSideMenuList({{"cheese ball", 4000}, {"cola", 2000}, {"fried potato", 3000}}) { }

void chooseSideMenu(DeliveryFood *food)
{
    
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

    DeliveryFood* chosenFood;

    switch(chooseFoodNum)
    {
        case 1:
            chosenFood = margheritaPizza;
            break;
        case 2:
            chosenFood = gorgonzolaPizza;
            break;
        case 3:
            chosenFood = friedChicken;
            break;
        case 4:
            chosenFood = spicyChicken;
            break;
        
        default:
            std::cout << "Wrong Response" << std::endl;
            ::exit(EXIT_FAILURE);
    }

    chosenFood->addFood();

    chooseSideMenu(chosenFood);
    
    return 0;
}