#ifndef TRUPMENA_H
#define TRUPMENA_H

#include <iostream>
#include <limits>

class Trupmena {
private:
    int skaitiklis;
    unsigned int vardiklis;

    Trupmena add(const Trupmena &a, const Trupmena &b);

    Trupmena sub(const Trupmena &a, const Trupmena &b);

    bool isSmaller(const Trupmena &a, const Trupmena &b);

    void simplify();

public:

    std::string toString() const;

    Trupmena();

    Trupmena(int skaitiklis);

    Trupmena(int skaitiklis, unsigned int vardiklis);

    Trupmena(const Trupmena &t); // Copy constructor


    Trupmena operator+(const Trupmena &b);

    Trupmena operator-(const Trupmena &b);

    Trupmena operator+=(const Trupmena &b);

    Trupmena operator-=(const Trupmena &b);

    Trupmena &operator=(const Trupmena &other);


    Trupmena operator++();

    Trupmena operator++(int);


    bool operator<(const Trupmena &b);

    bool operator>(const Trupmena &b);

    friend std::ostream &operator<<(std::ostream &os, Trupmena t);
};

#endif
