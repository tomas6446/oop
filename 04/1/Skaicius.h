#ifndef SKAICIUS_H
#define SKAICIUS_H

class Skaicius
{
private:
    static int minReiksme, maxReiksme;
    int val;

public:
    int getMin();

    int getMax();

    int getVal();

    void setMin(int minimum);

    void setMax(int maximum);

    void setVal(int val);

    bool rangeCheck(int val);
};

#endif
