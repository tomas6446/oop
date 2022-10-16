#ifndef VEKTORIUS_H
#define VEKTORIUS_H

#include <bits/stdc++.h>

template<class T>
class iter;

template<class T>
class victor {
    friend class iter<T>;

    typedef iter<T> iterator;

private:
    T *array;
    int current{};
    int capacity{};
    int step;

public:
    victor()
    {
        this->array = new T[1];
        this->capacity = 1;
        this->current = 0;
        this->step = 1;
    }

    victor(int capacity)
    {
        this->array = new T[capacity];
        this->capacity = capacity;
        this->current = 0;
        this->step = 1;
    }

    victor(int capacity, int step)
    {
        this->array = new T[capacity];
        this->capacity = capacity;
        this->current = 0;
        this->step = step;
    }

    ~victor()
    {
        delete[] this->array;
        this->current = 0;
    }

    void push_back(T val)
    {
        if (this->current >= this->capacity) {
            T *temp = new T[this->capacity + this->step];

            for (int i = 0; i < this->capacity; ++i) {
                temp[i] = this->array[i];
            }

            delete[] this->array;
            this->capacity += this->step;
            this->array = temp;
        }
        this->array[this->current] = val;
        this->current++;
    }

    T &operator[](int index)
    {
        if (index < 0 || index > this->capacity) {
            throw std::out_of_range("out of range exception");
        }
        return this->array[index];
    }

    int size() { return this->current; }

    iterator begin()
    {
        return iterator(*this, 0);
    };

    iterator end()
    {
        return iterator(*this, current);
    }
};

template<class T>
class iter {
private:
    victor<T> &vect;
    int current{};
public:
    iter() = default;

    iter(victor<T> &p, int c) : vect(p), current(c) {}

    ~iter() = default;

    iter &operator++()
    {
        current++;
        return *this;
    }

    T &operator*() const { return vect.array[current]; }

    T *operator->() const { return vect.array[current]; }

    bool operator<(const iter &b) { return &this->vect == &b.vect && this->current < b.current; };

    bool operator!=(const iter &b) { return &this->vect == &b.vect && this->current != b.current; };
};

class SkaiciuPalyginimas {
public:
    int operator()(int a, int b)
    {
        int sumA = 0;
        int sumB = 0;

        while (a > 0) {
            sumA += a % 10;
            a /= 10;
        }
        while (b != 0) {
            sumB += b % 10;
            b /= 10;
        }

        if (sumA < sumB) {
            return 1;
        }
        else {
            return 0;
        }
    }

    int operator()(std::string a, std::string b)
    {
        std::regex vowels("[aeiouAEIOU]");

        a = std::regex_replace(a, vowels, "");
        b = std::regex_replace(b, vowels, "");

        if (a < b) {
            return 1;
        }
        else {
            return 0;
        }
    }
};


#endif
