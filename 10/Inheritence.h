#ifndef PRAT10_INHERITENCE_H
#define PRAT10_INHERITENCE_H

#include "iostream"
#include <cmath>

using namespace std;

class Inheritence {
private:
    int x{}, y{};
public:
    Inheritence() = default;

    Inheritence(int X, int Y)
    {
        this->x = X;
        this->y = Y;
    }

    ~Inheritence() = default;

    int getX() const
    {
        return this->x;
    }

    int getY() const
    {
        return this->y;
    }

    void setX(int X)
    {
        this->x = X;
    }

    void setY(int Y)
    {
        this->y = Y;
    }
};

class Figura {
protected:
    Inheritence taskas;
public:
    Figura() = default;

    Figura(const Inheritence &t)
    {
        this->taskas = t;
    }

    ~Figura() = default;

    Inheritence getTaskas() const
    {
        return this->taskas;
    }

    void setTaskas(Inheritence t)
    {
        this->taskas = t;
    }

    virtual void spausdinti()
    {
        cout << "taskas: [" << this->taskas.getX() << " ; " << this->taskas.getY() << "]" << endl;
    }
};

class Skritulys : public Figura {
private:
    double centras{}, spindulys{};
public:
    Skritulys() = default;

    Skritulys(double centr, double spindul)
    {
        this->centras = centr;
        this->spindulys = spindul;
    }

    ~Skritulys() = default;

    virtual double plotas() const
    {
        return M_PI * (spindulys * spindulys);
    }

    virtual double perimetras() const
    {
        return 2 * M_PI * spindulys;
    }

    double getCentras() const
    {
        return this->centras;
    }

    double getSpindulys() const
    {
        return this->spindulys;
    }

    void setCentras(double centr)
    {
        this->centras = centr;
    }

    void setSpindulys(double spindul)
    {
        this->spindulys = spindul;
    }

    virtual void spausdinti()
    {
        cout << "centras: " << centras << " spindulys: " << spindulys << " ";
        Figura::spausdinti();
    }
};

class Elipse : public Skritulys {
private:
    double a{}, b{};
public:
    Elipse() = default;

    Elipse(double centr, double A, double B) : Skritulys(centr, A)
    {
        this->a = A;
        this->b = B;
    }

    ~Elipse() = default;

    double getA() const
    {
        return this->a;
    }

    double getB() const
    {
        return this->b;
    }

    void setA(double A)
    {
        this->a = A;
    }

    void setB(double B)
    {
        this->b = B;
    }

    double plotas() const
    {
        return M_PI * a * b;
    }

    double perimetras() const
    {
        return M_PI * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
    }

    void spausdinti()
    {
        cout << "a: " << a << " " << "b: " << b << " ";
        Skritulys::spausdinti();
    }
};

class Kvadratas : public Figura {
private:
    double centras{}, a{};
public:
    Kvadratas() = default;

    Kvadratas(double centr, double A)
    {
        this->centras = centr;
        this->a = A;
    }

    ~Kvadratas() = default;

    double getCentras() const
    {
        return this->centras;
    }

    double getA() const
    {
        return a;
    }

    void setA(double A)
    {
        this->a = A;
    }

    virtual double plotas() const
    {
        return a * a;
    }

    virtual double perimetras() const
    {
        return 4 * a;
    }

    void setCentras(double centr)
    {
        this->centras = centr;
    }

    void spausdinti()
    {
        cout << "a: " << a << " centras: " << centras << " ";
        Figura::spausdinti();
    }
};

class Staciakamplis : public Kvadratas {
private:
    double a{}, b{};

public:
    Staciakamplis() = default;

    Staciakamplis(double centr, double A, double B) : Kvadratas(centr, A)
    {
        this->a = A;
        this->b = B;
    }

    ~Staciakamplis() = default;

    double plotas() const
    {
        return a * b;
    }

    double perimetras() const
    {
        return 2 * (a + b);
    }

    double getB() const
    {
        return this->b;
    }

    void setB(double B)
    {
        this->b = B;
    }

    void spausdinti()
    {
        cout << "b: " << b << " ";
        Kvadratas::spausdinti();
    }
};

#endif
