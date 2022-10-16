#include <iostream>
#include "kambarys.h"


int Durys::durysCreated = 0;
int Langas::languCreated = 0;

Durys::Durys()
{
    width = 0;
    height = 0;

    durysCreated++;
}

Durys::Durys(float width, float height)
{
    this->width = width;
    this->height = height;

    durysCreated++;
}

Durys::~Durys()
{
    durysCreated--;
}

int Durys::getKiekis()
{
    return durysCreated;
}

float Durys::getWidth() const
{
    return width;
}

float Durys::getHeight() const
{
    return height;
}

Langas::Langas()
{
    width = 0;
    height = 0;

    languCreated++;
}

Langas::Langas(float width, float height)
{
    this->width = width;
    this->height = height;

    languCreated++;
}

Langas::~Langas()
{
    languCreated--;
}

int Langas::getKiekis()
{
    return languCreated;
}

float Langas::getWidth() const
{
    return width;
}

float Langas::getHeight() const
{
    return height;
}

Kambarys &Kambarys::operator=(const Kambarys &k)
{
    if (this == &k) {
        return *this;
    }
    for (auto i: this->langas) {
        delete i;
        i = nullptr;
    }
    this->langas.clear();
    delete this->durys;

    this->length = k.length;
    this->width = k.width;
    this->height = k.height;

    this->durys = new Durys(k.durys->getHeight(), k.durys->getHeight());
    for (int i = 0; i < langas.size(); i++) {
        Langas *l = new Langas(k.langas[i]->getWidth(), k.langas[i]->getHeight());
        langas.push_back(l);
    }
    return *this;
}

Kambarys::Kambarys()
{
    this->width = 0;
    this->height = 0;
    this->length = 0;
}

Kambarys::Kambarys(float width, float height, float length)
{
    this->width = width;
    this->height = height;
    this->length = length;
}

Kambarys::Kambarys(const Kambarys &k)
{
    this->length = k.length;
    this->width = k.width;
    this->height = k.height;
    this->durys = new Durys(k.durys->getHeight(), k.durys->getHeight());
    for (int i = 0; i < langas.size(); i++) {
        Langas *l = new Langas(k.langas[i]->getWidth(), k.langas[i]->getHeight());
        langas.push_back(l);
    }
}

Kambarys::~Kambarys()
{
    for (auto i: this->langas) {
        delete i;
        i = nullptr;
    }
    this->langas.clear();
    delete this->durys;
    this->durys = nullptr;
}

void Kambarys::addLangas(Langas *l)
{
    this->langas.push_back(l);
}

void Kambarys::addDurys(Durys *d)
{
    this->durys = new Durys(*d);
}

float Kambarys::getWidth() const
{
    return width;
}

float Kambarys::getHeight() const
{
    return height;
}

float Kambarys::getLength() const
{
    return length;
}

float calcArea(Kambarys k)
{
    float doorArea = k.getHeight() * k.getWidth();

    float langasArea = 0;
    for (auto l: k.langas) {
        langasArea += l.getHeight() * l.getWidth();
    }

    float kambarysArea = 2 * ((k.getWidth() * k.getHeight()) +
                              (k.getLength() * k.getHeight()) +
                              (k.getWidth() * k.getLength())) - (langasArea + doorArea);
    return kambarysArea;
}

float calcPlithPerimeter(Kambarys k)
{
    float durysPlinth = k.getWidth();
    float kambarysPlinth = (2 * (k.getWidth() + k.getLength())) - durysPlinth;
    return kambarysPlinth;
}

int main()
{
    Langas *l1 = new Langas(2.1, 2.1);
    Langas *l2 = new Langas(2.1, 2.1);
    Durys *d1 = new Durys(2.2, 0.7);

    Kambarys *k1 = new Kambarys(10, 2, 5);

    k1->addDurys(d1);
    k1->addLangas(l1);
    k1->addLangas(l2);

    std::cout << l1->getKiekis() << " " << d1->getKiekis() << std::endl;

    std::cout << "Plotas: " << calcArea(k1) << std::endl;
    std::cout << "Grindjuosciu ilgis: " << calcPlithPerimeter(k1) << std::endl;
    std::cout << "Grindjuosciu ilgis: " << calcPlithPerimeter(k1) << std::endl;

    std::cout << l1->getKiekis() << " " << d1->getKiekis() << std::endl;
//
//    Kambarys k2(10, 2, 5);
//    k2 = *k1;
//    delete k1;

    return 0;
}