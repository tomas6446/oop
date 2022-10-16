#include "Trupmena.h"

Trupmena::Trupmena(int skaitiklis, unsigned int vardiklis)
{
    if (vardiklis > std::numeric_limits<int>::max()) {
        throw std::range_error("'Vardiklis' cannot be negative\n");
    }
    if (vardiklis == 0) {
        throw std::runtime_error("Attempted to divide by zero.\n");
    }

    this->skaitiklis = skaitiklis;
    this->vardiklis = vardiklis;
    this->simplify();
}

Trupmena::Trupmena(const Trupmena &t)
{
    this->vardiklis = t.vardiklis;
    this->skaitiklis = t.skaitiklis;
};// Copy constructor

Trupmena::Trupmena()
{
    skaitiklis = 0;
    vardiklis = 1;
}

Trupmena::Trupmena(int skaitiklis)
{
    this->skaitiklis = skaitiklis;
    this->vardiklis = 1;
}

Trupmena Trupmena::add(const Trupmena &a, const Trupmena &b)
{
    Trupmena res;
    res.skaitiklis = (skaitiklis * b.vardiklis) + (b.skaitiklis * vardiklis);
    res.vardiklis = vardiklis * b.vardiklis;

    res.simplify();
    return res;
}

Trupmena Trupmena::sub(const Trupmena &a, const Trupmena &b)
{
    Trupmena res;
    res.skaitiklis = (skaitiklis * b.vardiklis) - (b.skaitiklis * vardiklis);
    res.vardiklis = vardiklis * b.vardiklis;

    res.simplify();
    return res;
}

bool Trupmena::isSmaller(const Trupmena &a, const Trupmena &b)
{
    if (a.vardiklis < b.vardiklis) {
        return true;
    }
    else if (b.vardiklis > a.vardiklis) {
        return false;
    }
    else {
        if (a.skaitiklis < b.skaitiklis) {
            return true;
        }
        else {
            return false;
        }
    }
}

std::string Trupmena::toString() const
{
    return std::to_string(skaitiklis) + "/" + std::to_string(vardiklis);
}

std::ostream &operator<<(std::ostream &os, Trupmena t)
{
    return os << t.toString();
}

void Trupmena::simplify()
{
    int i = 1, dev = 1;
    // count until 'i' will divide without remainder
    while (i++ < this->vardiklis) {
        if (this->vardiklis % i == 0 && this->skaitiklis % i == 0) {
            // save number which divides 'vardiklis' and 'skaitiklis' by 'i' without remainder
            dev = i;
        }
    }
    // divide skaitiklis and vardiklis
    this->skaitiklis /= dev;
    this->vardiklis /= dev;
}

Trupmena Trupmena::operator+(const Trupmena &b)
{
    return add(*this, b);
}

Trupmena Trupmena::operator-(const Trupmena &b)
{
    return sub(*this, b);
}

Trupmena Trupmena::operator+=(const Trupmena &b)
{
    *this = *this + b;
    return *this;
}

Trupmena Trupmena::operator-=(const Trupmena &b)
{
    *this = *this - b;
    return *this;
}

Trupmena Trupmena::operator++()
{
    Trupmena temp((int) this->vardiklis, this->vardiklis);
    *this = *this + temp;
    return *this;
}

Trupmena Trupmena::operator++(int)
{
    Trupmena temp((int) this->vardiklis, this->vardiklis);
    *this = temp + *this;
    return *this;
}

Trupmena &Trupmena::operator=(const Trupmena &other)
{
    if (this == &other) {
        return *this;
    }

    this->skaitiklis = other.skaitiklis;
    this->vardiklis = other.vardiklis;

    return *this;
}

bool Trupmena::operator<(const Trupmena &b)
{
    return isSmaller(*this, b);
}

bool Trupmena::operator>(const Trupmena &b)
{
    return !(*this < b);
}

int main()
{
    Trupmena trupmena1(1, 13);
    Trupmena trupmena2(-1342, 12);
    Trupmena trupmena3(313, 12);

    try {
        trupmena1 += trupmena1;
        trupmena1 += trupmena2 += trupmena3;
    }
    catch (const std::exception &e) {
        std::cerr << e.what();
    }

    std::cout << trupmena1 << " " << trupmena2 << " " << trupmena3 << std::endl;

    return 0;
}
