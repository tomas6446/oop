#include <iostream>
#include <stdexcept>
#include <limits>
#include "Skaicius.h"

int Skaicius::minReiksme = 0;
int Skaicius::maxReiksme = 0;

void Skaicius::setMin(int maximum)
{
    minReiksme = maximum;
}

void Skaicius::setMax(int minimum)
{
    maxReiksme = minimum;
}

void Skaicius::setVal(int val)
{
    this->val = val;
}

bool Skaicius::rangeCheck(int num)
{
    if (num < getMax() && num > getMin()) // patenka į rėžius
    {
        this->setVal(num);
        return true;
    }
    else
    {
        std::out_of_range exc = std::out_of_range("out_of_range.\n");
        std::cerr << exc.what();
        return false;
    }
}

int Skaicius::getMax()
{
    return maxReiksme;
}

int Skaicius::getMin()
{
    return minReiksme;
}

int Skaicius::getVal()
{
    return val;
}


int main()
{
    Skaicius *number = new Skaicius[10];
    number->setMax(100);
    number->setMin(10);

    int input, suitableNum = 0;
    while (suitableNum < 10) // kol ne bus 10 tinkamnų
    {
        if (!(std::cin >> input))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::out_of_range exc = std::out_of_range("invalid_argument\n");
            std::cerr << exc.what();
        }
        else // jeigu ne invalid_argument
        {
            if (number[suitableNum].rangeCheck(input)) // jeigu patenka į rėžius
            {
                suitableNum++;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        std::cout << number[i].getVal() << " ";
    }

    delete[] number;
    return 0;
}
