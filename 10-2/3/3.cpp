#include <iostream>

class PublicTransport
{
protected:
    int totalPrice;

public:
    PublicTransport(void): totalPrice(0) { }
    void show(void) { std::cout << "Total price : " << this->totalPrice << std::endl; }
};

class Bus : virtual public PublicTransport
{
private:
    int busPrice;
    int busTicket;

public:
    Bus(void): busPrice(8000), busTicket(0) { }
    void setTicket(int _ticket)
    {
        this->totalPrice += (_ticket - this->busTicket) * this->busPrice;
        this->busTicket = _ticket;
    }
    int getTicket(void)
    {
        return this->busTicket;
    }
    int getPrice(void)
    {
        return this->busPrice;
    }
    void show()
    {
        std::cout << "Bus total price : " << this->busPrice * this->busTicket << std::endl;
    }
};

class Train : virtual public PublicTransport
{
private:
    int trainPrice;
    int trainTicket;

public:
    Train(void): trainPrice(12000), trainTicket(0) { }
    void setTicket(int _ticket)
    {
        this->totalPrice += (_ticket - this->trainTicket) * this->trainPrice;
        this->trainTicket = _ticket;
    }
    int getTicket(void)
    {
        return this->trainTicket;
    }
    int getPrice(void)
    {
        return this->trainPrice;
    }
    void show()
    {
        std::cout << "Train total price : " << this->trainPrice * this->trainTicket << std::endl;
    }
};

class Transportation : virtual public Bus, virtual public Train
{
public:
    void show(void)
    {
        Bus::show();
        Train::show();
        PublicTransport::show();
    }
};

int main(void)
{
    Transportation transportaion = Transportation();

    std::cout << "Bus price : " << static_cast<Bus &>(transportaion).getPrice() << std::endl;
    std::cout << "Bus ticket : " << static_cast<Bus &>(transportaion).getTicket() << std::endl;
    static_cast<Bus &>(transportaion).setTicket(2);
    std::cout << "Bus ticket : " << static_cast<Bus &>(transportaion).getTicket() << std::endl;

    std::cout << "Train price : " << static_cast<Train &>(transportaion).getPrice() << std::endl;
    std::cout << "Train ticket : " << static_cast<Train &>(transportaion).getTicket() << std::endl;
    static_cast<Train &>(transportaion).setTicket(3);
    std::cout << "Train ticket : " << static_cast<Train &>(transportaion).getTicket() << std::endl;

    transportaion.show();
}