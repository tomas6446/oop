#ifndef KAMBARYS_H
#define KAMBARYS_H

#include <vector>
#include <iostream>

class Langas {
private:
    float width, height;
    static int languCreated;
public:
    Langas();

    Langas(float width, float height);

    ~Langas();

    static int getKiekis();

    float getWidth() const;

    float getHeight() const;
};

class Durys {
private:
    float width, height;
    static int durysCreated;
public:
    Durys();

    Durys(float width, float height);

    ~Durys();

    static int getKiekis();

    float getWidth() const;

    float getHeight() const;
};

class Kambarys {
private:
    float width{}, height{}, length{};


public:
    std::vector<Langas *> langas;
    Durys *durys;

    Kambarys();

    Kambarys(float width, float height, float length);

    Kambarys(const Kambarys &k);

    ~Kambarys();

    void addLangas(Langas *l);

    void addDurys(Durys *d);

    float getWidth() const;

    float getHeight() const;

    float getLength() const;

    Kambarys &operator=(const Kambarys &k);
};


#endif
