#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Car
{
public:
    string manufacturer;
    int model;
    int price;
    string color;
    int maxSpeed;

    Car() { }

    void setRandomParams()
    {
        string manufacturers[] = {"Audi", "BMW", "Ford", "Honda", "Hyundai"};
        string colors[] = {"red", "black", "green", "yellow", "blue", "purple"};
        manufacturer = manufacturers[rand() % 5];
        model = rand() % 11;
        price = rand() % (100000 - 1501) + 1500;
        color = colors[rand() % 6];
        maxSpeed = rand() % (280 - 101) + 100;
    }
};

void printElement(Car item);

class Stack
{
private:
    Car stack[100];
    int count = 0;
public:
    void push(Car item)
    {
        for (int i = count; i > 0; i--)
        {
            stack[i] = stack[i - 1];
        }

        stack[0] = item;
        count++;
    }

    Car pop()
    {
        Car item = stack[0];
        for (int i = 1; i < count; i++)
        {
            stack[i - 1] = stack[i];
        }
        count--;
        return item;
    }

    bool isEmpty()
    {
        if (count != 0)
            return false;
        else
            return true;
    }

    void printStack()
    {
        for (int i = 0; i < count; i++)
        {
            printElement(stack[i]);
        }
    }

    void randStack(int n)
    {
        for (int i = 0; i < n; i++)
        {
            Car car = Car();
            car.setRandomParams();
            stack[i] = car;
            count = n;
        }
    }

};

void printElement(Car item)
{
    cout << "Manufacturer: " + item.manufacturer + "; Model: " + to_string(item.model) + "; Price: " + to_string(item.price) + "; Color: " + item.color + "; Maximum speed: " + to_string(item.maxSpeed) << endl;
}


int main()
{
    srand(time(NULL));
    Stack arrStack = Stack();
    
    arrStack.randStack(5);
    
    while (!arrStack.isEmpty())
    {
        Car item = arrStack.pop();
        cout << "Pop item: ";
        printElement(item);
        arrStack.printStack();
    }

    return 0;
}
