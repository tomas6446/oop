#ifndef INHERITENCE_H
#define INHERITENCE_H

#include "iostream"
#include <cmath>

using namespace std;

class Taskas {
private:
    int x{}, y{};
public:
    Taskas() = default;

    Taskas(int X, int Y)
    {
        this->x = X;
        this->y = Y;
    }

    ~Taskas() = default;

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
    Taskas taskas;
public:
    explicit Figura(const Taskas &t)
    {
        this->taskas = t;
        std::cout << "Figura konstruktorius" << std::endl;
    }

    ~Figura()
    {
        std::cout << "Figura destruktorius" << std::endl;
    }

    Taskas getTaskas() const
    {
        return this->taskas;
    }

    void setTaskas(Taskas t)
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
    double spindulys{};
public:
    Skritulys(Taskas centr, double spindul) : Figura(centr)
    {
        this->spindulys = spindul;
        std::cout << "Skritulys konstruktrius" << std::endl;
    }

    ~Skritulys()
    {
        std::cout << "Skritulys destruktorius" << std::endl;
    }

    virtual double plotas() const
    {
        return M_PI * (spindulys * spindulys);
    }

    virtual double perimetras() const
    {
        return 2 * M_PI * spindulys;
    }

    double getSpindulys() const
    {
        return this->spindulys;
    }

    void setSpindulys(double spindul)
    {
        this->spindulys = spindul;
    }

    void spausdinti() override
    {
        cout << "spindulys: " << spindulys << " ";
        Figura::spausdinti();
    }
};

class Elipse : public Skritulys {
private:
    double a{}, b{};
public:
    Elipse(Taskas centr, double A, double B) : Skritulys(centr, A)
    {
        this->a = A;
        this->b = B;
        std::cout << "Elipse konstruktorius" << std::endl;
    }

    ~Elipse()
    {
        std::cout << "Elipse destruktorius" << std::endl;
    }

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

    double plotas() const override
    {
        return M_PI * a * b;
    }

    double perimetras() const override
    {
        return M_PI * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
    }

    void spausdinti() override
    {
        cout << "a: " << a << " " << "b: " << b << " ";
        Skritulys::spausdinti();
    }
};

class Kvadratas : public Figura {
private:
    double a{};
public:
    Kvadratas(Taskas centr, double A) : Figura(centr)
    {
        this->a = A;
        std::cout << "Elipse konstruktorius" << std::endl;
    }

    ~Kvadratas()
    {
        std::cout << "Elipse destruktorius" << std::endl;
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

    void spausdinti() override
    {
        cout << "a: " << a << " ";
        Figura::spausdinti();
    }
};

class Staciakampis : public Kvadratas {
private:
    double a{}, b{};

public:
    Staciakampis(Taskas centr, double A, double B) : Kvadratas(centr, A)
    {
        this->a = A;
        this->b = B;
        std::cout << "Staciakampis konstruktorius" << std::endl;
    }

    ~Staciakampis()
    {
        std::cout << "Staciakamplis destruktorius" << std::endl;
    }

    double plotas() const override
    {
        return a * b;
    }

    double perimetras() const override
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

    void spausdinti() override
    {
        cout << "b: " << b << " ";
        Kvadratas::spausdinti();
    }
};

#endif
